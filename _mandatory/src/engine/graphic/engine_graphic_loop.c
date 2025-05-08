/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_loop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 04:01:00 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:38:12 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_graphic(t_data *d)
{
	cam_offset(&d->engine.graphic.cam, &d->game.entity.player, &d->win);
	calc_ray(d);
	draw_floor(d);
	draw_walls(d);
	mlx_put_image_to_window(d->mlx, d->win.ptr,
		d->engine.graphic.frame.ptr, 0, 0);
}
