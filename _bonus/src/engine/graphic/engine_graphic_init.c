/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:33:59 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 11:35:55 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_zbuffer(t_data *d)
{
	t_vec2	i;

	d->engine.graphic.zbuffer = malloc(sizeof(float *) * MAX_WIDTH);
	if (!d->engine.graphic.zbuffer)
		error(d, ERROR_MEM, NULL);
	i.x = 0;
	while (i.x < MAX_WIDTH)
	{
		d->engine.graphic.zbuffer[i.x]
			= malloc(sizeof(float) * MAX_HEIGHT);
		if (!d->engine.graphic.zbuffer[i.x])
		{
			ft_mfree((void **)d->engine.graphic.zbuffer, i.x);
			d->engine.graphic.zbuffer = NULL;
			error(d, ERROR_MEM, NULL);
		}
		i.y = 0;
		while (i.y < MAX_HEIGHT)
		{
			d->engine.graphic.zbuffer[i.x][i.y] = MAX_DISTANCE;
			i.y++;
		}
		i.x++;
	}
}

void	init_frame(t_data *d)
{
	d->engine.graphic.frame = new_img(d->mlx, d->win.size);
	if (!d->engine.graphic.frame.ptr || !d->engine.graphic.frame.data)
		error(d, ERROR_IMG, NULL);
}

void	init_graphic(t_data *d)
{
	init_frame(d);
	init_zbuffer(d);
	init_floor(&d->engine.graphic.floor);
	init_fog(&d->engine.graphic.fog);
	init_ray(&d->engine.graphic.rays, WIN_WIDTH);
}
