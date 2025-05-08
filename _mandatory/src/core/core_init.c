/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 07:01:44 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:19:22 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_core(t_data *d, char *path)
{
	d->mlx = NULL;
	d->win.ptr = NULL;
	d->engine.graphic.frame.ptr = NULL;
	d->engine.graphic.frame.data = NULL;
	d->mlx = mlx_init();
	if (!d->mlx)
		error(d, ERROR_MLX, NULL);
	d->win.ptr = mlx_new_window(d->mlx, WIN_WIDTH, WIN_HEIGHT, NAME);
	if (!d->win.ptr)
		error(d, ERROR_WIN, NULL);
	d->win.size.x = WIN_WIDTH;
	d->win.size.y = WIN_HEIGHT;
	d->win.half_h = WIN_HEIGHT >> 1;
	init_game(d, path);
	init_engine(d);
	d->time.current = get_time();
	d->time.old = 0.0f;
	d->time.delta = 0.0f;
}
