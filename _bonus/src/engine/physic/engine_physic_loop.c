/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_physic_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:24:13 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 21:12:02 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	create_update_tasks(t_data *d, int count, void *(*func)(void *))
{
	t_task_arg	*task;
	int			i;

	i = 0;
	while (i < count)
	{
		task = malloc(sizeof(t_task_arg));
		if (!task)
			error(d, ERROR_THD, NULL);
		task->d = d;
		task->start = i;
		task->end = i + 1;
		if (!threads_add_task(&d->engine.threads, func, task))
			return (free(task), error(d, ERROR_THD, NULL));
		i++;
	}
}

void	loop_physic(t_data *d)
{
	physic_jump(d, &d->game.entities.player, d->time.delta);
	create_update_tasks(d, (int)ft_lstsize(d->game.entities.enemies.list),
		enemy_seek_player);
	threads_wait_tasks(&d->engine.threads);
	create_update_tasks(d, (int)ft_lstsize(d->game.entities.enemies.list),
		calc_render_enemy_1);
	threads_wait_tasks(&d->engine.threads);
	sort_enemies(d->game.entities.enemies.list);
}
