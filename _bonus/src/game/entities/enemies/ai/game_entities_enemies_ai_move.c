/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_ai_move.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:12:59 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 13:13:55 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_map_collision(t_data *d, t_vecf2 pos)
{
	t_emap	*elem;

	if (pos.x + ENEMY_BOX < 0.0f || pos.x + ENEMY_BOX >= MAP_SIZE_X
		|| pos.y + ENEMY_BOX < 0.0f || pos.y + ENEMY_BOX >= MAP_SIZE_Y)
		return (false);
	if (pos.x - ENEMY_BOX < 0.0f || pos.x - ENEMY_BOX >= MAP_SIZE_X
		|| pos.y - ENEMY_BOX < 0.0f || pos.y - ENEMY_BOX >= MAP_SIZE_Y)
		return (false);
	elem = &d->game.map.elem[
		(int)(pos.x + ENEMY_BOX)][(int)(pos.y + ENEMY_BOX)];
	if (elem->collision >= BLOCK_ENEMY)
		return (false);
	elem = &d->game.map.elem[
		(int)(pos.x - ENEMY_BOX)][(int)(pos.y - ENEMY_BOX)];
	if (elem->collision >= BLOCK_ENEMY)
		return (false);
	return (true);
}

static bool	enemy_rand_idle(t_data *d, t_enemy *enemy)
{
	t_anims	*anims;

	if (enemy->state == IDLE)
	{
		enemy->idle_count--;
		if (enemy->r.dist <= ENEMY_AGR_RANGE)
			enemy->idle_count = 0;
		else if (enemy->idle_count > 0)
			return (false);
	}
	else if (enemy->state == WALK && enemy->r.dist > ENEMY_AGR_RANGE)
	{
		if (get_rand(1, 50, (int)(d->time.current + enemy->id)) == 1)
		{
			enemy->idle_count = get_rand(100, 600,
					(int)(d->time.current + enemy->id));
			enemy->state = IDLE;
			anims = &d->engine.graphic.sprites.enemy.anims[enemy->state];
			enemy->r.iframe = get_rand(0, anims->frames - 1,
					(int)(d->time.current + enemy->id));
			return (false);
		}
	}
	enemy->state = WALK;
	return (true);
}

void	enemy_move(t_data *d, t_enemy *enemy)
{
	t_vecf2	pos;

	if (!enemy_rand_idle(d, enemy))
		return ;
	pos = (t_vecf2){enemy->pos.x, enemy->pos.y};
	pos.x += enemy->dir.x * ENEMY_MOV_SPEED * d->time.delta;
	pos.y += enemy->dir.y * ENEMY_MOV_SPEED * d->time.delta;
	if (check_map_collision(d, pos))
	{
		enemy->pos.x = pos.x;
		enemy->pos.y = pos.y;
	}
}
