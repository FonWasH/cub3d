/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_rays_calc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:26:23 by juperez           #+#    #+#             */
/*   Updated: 2025/04/23 04:45:24 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*calc_ray(void *arg)
{
	t_task_arg	*task;
	t_data		*d;
	t_rays		*rays;
	float		cam_x;
	int			i;

	task = (t_task_arg *)arg;
	d = task->d;
	rays = &d->engine.graphic.rays;
	i = task->start;
	while (i < task->end)
	{
		cam_x = rays->cam[i] * d->game.entities.player.cam.zoom;
		rays->lut[i].x = d->game.entities.player.cam.dir.x
			+ d->game.entities.player.cam.plane.x * cam_x;
		rays->lut[i].y = d->game.entities.player.cam.dir.y
			+ d->game.entities.player.cam.plane.y * cam_x;
		i++;
	}
	return (free(arg), NULL);
}
