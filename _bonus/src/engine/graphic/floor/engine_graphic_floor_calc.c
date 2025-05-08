/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_floor_calc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:46:37 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 17:44:13 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*calc_floor(void *arg)
{
	t_task_arg	*task;
	t_data		*d;
	t_floor		*floor;
	int			i;

	task = (t_task_arg *)arg;
	d = task->d;
	floor = &d->engine.graphic.floor;
	i = task->start;
	while (i < task->end)
	{
		floor->rays_rmag[i] = rmagf(d->engine.graphic.rays.lut[i]);
		floor->angle[i] = dotf(d->game.entities.player.cam.dir,
				d->engine.graphic.rays.lut[i])
			* (floor->dir_rmag * floor->rays_rmag[i]);
		i++;
	}
	return (free(arg), NULL);
}

void	floor_z_offset(t_floor *floor, t_player *player, t_win *win)
{
	float	z_offset;

	z_offset = player->pos.z * player->cam.zoom * win->size.y;
	floor->fz_offset = (win->half_h + z_offset) * player->cam.rzoom;
	floor->cz_offset = (win->half_h - z_offset) * player->cam.rzoom;
	floor->dir_rmag = rmagf(player->cam.dir);
}
