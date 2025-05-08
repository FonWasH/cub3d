/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_ai_seek.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:02:55 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 02:37:52 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_path(t_data *d, t_enemy *e, bool update)
{
	int	path_len;

	if (update && e->state != ATTACK_1 && e->state != ATTACK_2)
	{
		path_len = find_path(d, &e->ai.pathfinding, e);
		if (path_len > 1)
		{
			e->ai.path = e->ai.pathfinding.path;
			e->ai.path_len = path_len;
			e->ai.target = 1;
		}
		else
		{
			e->ai.path = NULL;
			e->ai.path_len = 0;
			update_dir(&e->dir, get_dir((t_vecf2){e->pos.x, e->pos.x},
					(t_vecf2){d->game.entities.player.pos.x,
					d->game.entities.player.pos.y}),
				ENEMY_ROT_SPEED * d->time.delta);
		}
	}
	if (e->ai.path != NULL && e->ai.target < e->ai.path_len)
		update_dir(&e->dir,
			get_dir((t_vecf2){e->pos.x, e->pos.y}, e->ai.path[e->ai.target]),
			ENEMY_ROT_SPEED * d->time.delta);
}

static bool	check_need_update(t_enemy *e)
{
	t_vecf2	target;

	e->ai.frame_count++;
	if (e->ai.frame_count >= AI_UPDATE_FREQ || e->ai.path == NULL
		|| e->ai.path_len == 0)
	{
		e->ai.frame_count = 0;
		return (true);
	}
	if (e->ai.path != NULL && e->ai.target < e->ai.path_len)
	{
		target = e->ai.path[e->ai.target];
		if (sqrtf(powf(e->pos.x - target.x, 2)
				+ powf(e->pos.y - target.y, 2)) < 0.2f)
		{
			e->ai.target++;
			if (e->ai.target >= e->ai.path_len)
				return (true);
		}
	}
	else
		return (true);
	return (false);
}

void	*enemy_seek_player(void *arg)
{
	t_task_arg	*task;
	t_data		*d;
	t_enemy		*enemy;

	task = (t_task_arg *)arg;
	d = task->d;
	enemy = get_enemy(d->game.entities.enemies.list, task->start);
	if (!enemy->in_zone || enemy->state == DIE_1 || enemy->state == DIE_2)
		return (free(task), NULL);
	update_path(d, enemy, check_need_update(enemy));
	if (check_range_player(enemy))
		enemy_attack(d, enemy);
	else
		enemy_move(d, enemy);
	return (free(task), NULL);
}
