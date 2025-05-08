/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:33:59 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:17:39 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_graphic(t_data *d)
{
	d->engine.graphic.frame = new_img(d->mlx, d->win.size);
	if (!d->engine.graphic.frame.ptr || !d->engine.graphic.frame.data)
		error(d, ERROR_IMG, NULL);
	init_cam(&d->engine.graphic.cam, WIN_WIDTH);
	init_fog(&d->engine.graphic.fog);
	init_render(&d->engine.graphic.render);
}
