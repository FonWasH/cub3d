/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:26:06 by juperez           #+#    #+#             */
/*   Updated: 2025/04/27 17:08:57 by juperez          ###   ########.fr       */
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
		init_win_size(d, width, height);
		d->game.entities.player.cam.p_offset
			= d->game.entities.player.cam.pitch * height;
		mlx_destroy_image(d->mlx, d->engine.graphic.frame.ptr);
		init_frame(d);
		init_ray(&d->engine.graphic.rays, width);
		init_minimap(&d->game.ui.minimap, width);
	}
	return (0);
}

void	hook_core(t_data *d)
{
	mlx_hook(d->win.ptr, KeyPress, KeyPressMask, hook_key_press, d);
	mlx_hook(d->win.ptr, KeyRelease, KeyReleaseMask, hook_key_release, d);
	mlx_hook(d->win.ptr, ButtonPress, ButtonPressMask, hook_btn_press, d);
	mlx_hook(d->win.ptr, ButtonRelease, ButtonReleaseMask, hook_btn_release, d);
	mlx_hook(d->win.ptr, MotionNotify, PointerMotionMask, hook_motion, d);
	mlx_hook(d->win.ptr, ConfigureNotify, StructureNotifyMask, hook_config, d);
	mlx_hook(d->win.ptr, DestroyNotify, StructureNotifyMask, exit_core, d);
	mlx_loop_hook(d->mlx, loop_core, d);
	mlx_loop(d->mlx);
}
