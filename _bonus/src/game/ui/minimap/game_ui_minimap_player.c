/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_minimap_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:17:29 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 13:27:04 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_pixel_triangle(t_data *d, t_vec2 i, t_triangle *t)
{
	float		a[3];
	uint32_t	*framebuffer;

	framebuffer = d->engine.graphic.frame.data;
	a[0] = ((t->p[1].y - t->p[2].y) * (i.x - t->p[2].x)
			+ (t->p[2].x - t->p[1].x) * (i.y - t->p[2].y)) / t->det;
	a[1] = ((t->p[2].y - t->p[0].y) * (i.x - t->p[2].x)
			+ (t->p[0].x - t->p[2].x) * (i.y - t->p[2].y)) / t->det;
	a[2] = 1.0f - a[0] - a[1];
	if (a[0] >= 0 && a[1] >= 0 && a[2] >= 0
		&& i.x >= 0 && i.x < d->win.size.x
		&& i.y >= 0 && i.y < d->win.size.y)
		framebuffer[i.y * d->win.size.x + i.x] = WHITE;
}

void	draw_minimap_player(t_data *d, t_triangle *t)
{
	t_vec2	i;

	i.y = (int)t->b_min.y;
	while (i.y <= (int)t->b_max.y)
	{
		i.x = (int)t->b_min.x;
		while (i.x <= (int)t->b_max.x)
		{
			draw_pixel_triangle(d, i, t);
			i.x++;
		}
		i.y++;
	}
}
