/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_physic_enemies_render_1.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 04:31:59 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 04:23:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_dist(t_enemy *enemy, t_player *player)
{
	enemy->r.dist = heuf((t_vecf2){player->pos.x, player->pos.y},
			(t_vecf2){enemy->pos.x, enemy->pos.y});
}

static int	calc_angle(t_enemy *enemy, t_player *player, bool oriented)
{
	t_vecf2	to_player;
	float	angle;
	float	dist;

	if (!oriented)
		return (0);
	to_player.x = player->pos.x - enemy->pos.x;
	to_player.y = player->pos.y - enemy->pos.y;
	dist = magf(to_player);
	if (dist == 0)
		return (0);
	to_player.x /= dist;
	to_player.y /= dist;
	angle = atan2f(enemy->dir.x * to_player.y - enemy->dir.y * to_player.x,
			enemy->dir.x * to_player.x + enemy->dir.y * to_player.y);
	angle = angle * 180.0f / PI;
	if (angle < 0)
		angle += 360.0f;
	return (((int)roundf(angle / 45.0f)) % ENEMY_MAX_DIRS);
}

static void	calc_transform(t_enemy *enemy, t_player *player)
{
	t_vecf2		diff;
	float		rdet;

	diff.x = enemy->pos.x - player->pos.x;
	diff.y = enemy->pos.y - player->pos.y;
	rdet = 1.0f / (player->cam.plane.x * player->cam.dir.y
			- player->cam.dir.x * player->cam.plane.y);
	enemy->r.tran.y = rdet * (-player->cam.plane.y * diff.x
			+ player->cam.plane.x * diff.y);
	rdet *= player->cam.rzoom;
	enemy->r.tran.x = rdet * (player->cam.dir.y * diff.x
			- player->cam.dir.x * diff.y);
}

void	*calc_render_enemy_1(void *arg)
{
	t_task_arg	*task;
	t_data		*d;
	t_enemy		*enemy;

	task = (t_task_arg *)arg;
	d = task->d;
	enemy = get_enemy(d->game.entities.enemies.list, task->start);
	calc_dist(enemy, &d->game.entities.player);
	enemy->r.idir = calc_angle(enemy, &d->game.entities.player,
			d->engine.graphic.sprites.enemy.anims[enemy->state].oriented);
	calc_transform(enemy, &d->game.entities.player);
	calc_render_enemy_2(d, enemy);
	return (free(task), NULL);
}
