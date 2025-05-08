/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:17:04 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 20:04:48 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_time(t_data *d)
{
	d->time.old = d->time.current;
	d->time.current = get_time();
	d->time.delta = delta_time(d->time.current, d->time.old);
}

int	loop_core(void *data)
{
	t_data	*d;

	d = (t_data *)data;
	load_core(d);
	if (!d->load.loaded)
		return (0);
	loop_engine(d);
	loop_game(d);
	mlx_put_image_to_window(d->mlx, d->win.ptr,
		d->engine.graphic.frame.ptr, 0, 0);
	update_time(d);
	show_fps(d->time.delta, d->mlx, d->win.ptr);
	return (0);
}
