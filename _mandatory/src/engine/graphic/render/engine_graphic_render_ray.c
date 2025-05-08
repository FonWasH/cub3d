/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_render_ray.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 03:45:41 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:37:50 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_ray(t_data *d)
{
	float		cam_x;
	float		dir_rmag;
	int			i;

	dir_rmag = rmag(d->game.entity.player.cam.dir);
	i = 0;
	while (i < d->win.size.x)
	{
		cam_x = d->engine.graphic.cam.lut[i] * d->game.entity.player.cam.zoom;
		d->engine.graphic.render.ray[i].x = d->game.entity.player.cam.dir.x
			+ d->game.entity.player.cam.plane.x * cam_x;
		d->engine.graphic.render.ray[i].y = d->game.entity.player.cam.dir.y
			+ d->game.entity.player.cam.plane.y * cam_x;
		d->engine.graphic.render.ray_rmag[i]
			= rmag(d->engine.graphic.render.ray[i]);
		d->engine.graphic.render.angle[i] = dot(d->game.entity.player.cam.dir,
				d->engine.graphic.render.ray[i])
			* (dir_rmag * d->engine.graphic.render.ray_rmag[i]);
		i++;
	}
}
