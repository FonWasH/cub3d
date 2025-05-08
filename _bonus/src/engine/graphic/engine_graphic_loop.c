/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_loop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 04:01:00 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 20:28:14 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	create_render_tasks(t_data *d, int size, void *(*func)(void *))
{
	t_task_arg	*task;
	int			range;
	int			i;

	range = size / THREADS_NB;
	i = 0;
	while (i < THREADS_NB)
	{
		task = malloc(sizeof(t_task_arg));
		if (!task)
			error(d, ERROR_THD, NULL);
		task->d = d;
		task->start = i * range;
		if (i == THREADS_NB - 1)
			task->end = size;
		else
			task->end = (i + 1) * range;
		if (!threads_add_task(&d->engine.threads, func, task))
			return (free(task), error(d, ERROR_THD, NULL));
		i++;
	}
}

void	loop_graphic(t_data *d)
{
	floor_z_offset(&d->engine.graphic.floor, &d->game.entities.player, &d->win);
	create_render_tasks(d, d->win.size.x, reset_z_buffer);
	create_render_tasks(d, d->win.size.x, calc_ray);
	create_render_tasks(d, d->win.size.x, calc_floor);
	threads_wait_tasks(&d->engine.threads);
	create_render_tasks(d, d->win.size.y, draw_floor);
	threads_wait_tasks(&d->engine.threads);
	create_render_tasks(d, d->win.size.x, draw_walls);
	threads_wait_tasks(&d->engine.threads);
	create_render_tasks(d, d->win.size.x, draw_sprites_enemies);
	threads_wait_tasks(&d->engine.threads);
	create_render_tasks(d, d->win.size.x, draw_doors);
	threads_wait_tasks(&d->engine.threads);
	draw_sprite_player(d, &d->game.entities.player);
	if (d->game.entities.player.state.damage)
		apply_hit_effect(d);
	draw_sprite_hud(d, &d->game.entities.player);
}
