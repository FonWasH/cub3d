/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:17:04 by juperez           #+#    #+#             */
/*   Updated: 2025/04/11 00:19:35 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_core(void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (!d->game.menu)
		loop_engine(d);
	else
		show_menu(d);
	loop_input(d);
	d->time.old = d->time.current;
	d->time.current = get_time();
	d->time.delta = deltatime(d->time.current, d->time.old);
	show_fps(d->time.delta, d->mlx, d->win.ptr);
	return (0);
}
