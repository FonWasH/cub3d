/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:03:56 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 04:08:08 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	create_load_tasks(t_data *d, void *(*func)(void *))
{
	t_task_arg	*task;

	task = malloc(sizeof(t_task_arg));
	if (!task)
		error(d, ERROR_THD, NULL);
	task->d = d;
	task->start = 0;
	task->end = 0;
	if (!threads_add_task(&d->engine.threads, func, task))
		return (free(task), error(d, ERROR_THD, NULL));
}

void	load_core(t_data *d)
{
	if (d->load.loaded)
		return ;
	if (d->load.error)
		return (error(d, NULL, NULL));
	if (!d->load.loading)
	{
		create_load_tasks(d, load_audio);
		create_load_tasks(d, load_map);
		create_load_tasks(d, load_sprites_enemy);
		create_load_tasks(d, load_sprites_hud);
		create_load_tasks(d, load_sprites_player);
		d->load.loading = true;
	}
	else
		draw_loading_screen(d);
	if (d->load.audio_done && d->load.textures_done && d->load.esprites_done
		&& d->load.hsprites_done && d->load.psprites_done)
	{
		d->load.loaded = true;
		d->load.loading = false;
		mla_start_sound(d->engine.audio.sounds[A_MUSIC]);
		mla_start_sound(d->engine.audio.sounds[A_AMBIENT]);
	}
}
