/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:26:06 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:30:40 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	hook_config(int width, int height, void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (width > MAX_WIDTH)
		width = MAX_WIDTH;
	if (height > MAX_HEIGHT)
		height = MAX_HEIGHT;
	if (width <= 0 || height <= 0)
		error(d, ERROR_CFG, NULL);
	if (d->win.size.x != width || d->win.size.y != height)
	{
		d->win.size.x = width;
		d->win.size.y = height;
		d->win.half_h = height >> 1;
		d->game.entity.player.cam.poffset
			= d->game.entity.player.cam.pitch * height;
		mlx_destroy_image(d->mlx, d->engine.graphic.frame.ptr);
		d->engine.graphic.frame = new_img(d->mlx, d->win.size);
		if (!d->engine.graphic.frame.ptr || !d->engine.graphic.frame.data)
			error(d, ERROR_IMG, NULL);
		init_cam(&d->engine.graphic.cam, width);
	}
	return (0);
}

void	hook_core(t_data *d)
{
	mlx_hook(d->win.ptr, KeyPress, KeyPressMask, hook_key_press, d);
	mlx_hook(d->win.ptr, KeyRelease, KeyReleaseMask, hook_key_release, d);
	mlx_hook(d->win.ptr, ConfigureNotify, StructureNotifyMask, hook_config, d);
	mlx_hook(d->win.ptr, DestroyNotify, StructureNotifyMask, exit_core, d);
	mlx_loop_hook(d->mlx, loop_core, d);
	mlx_loop(d->mlx);
}
