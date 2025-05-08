/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_minimap_border.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:18:20 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 13:30:28 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_pixel_background(t_data *d, t_minimap *minimap, t_vec2 i)
{
	uint32_t	*framebuffer;
	float		dist;
	int			radius;
	t_vec2		start;

	framebuffer = d->engine.graphic.frame.data;
	start.x = minimap->pos.x;
	start.y = minimap->pos.y;
	radius = minimap->center.x;
	dist = minimap->dist[i.y][i.x];
	if (dist <= radius)
		framebuffer[(start.y + i.y) * d->win.size.x + (start.x + i.x)] = BLACK;
}

void	draw_minimap_background(t_data *d, t_minimap *minimap)
{
	t_vec2		i;

	i.y = 0;
	while (i.y < MINIMAP_SIZE)
	{
		i.x = 0;
		while (i.x < MINIMAP_SIZE)
		{
			draw_pixel_background(d, minimap, i);
			i.x++;
		}
		i.y++;
	}
}

static	void	draw_pixel_border(t_data *d, t_minimap *minimap, t_vec2 i)
{
	uint32_t	*framebuffer;
	float		dist;
	int			radius;
	t_vec2		start;

	framebuffer = d->engine.graphic.frame.data;
	start.x = minimap->pos.x;
	start.y = minimap->pos.y;
	radius = minimap->center.x;
	dist = minimap->dist[i.y][i.x];
	if (dist >= radius - MINIMAP_BORDER && dist <= radius)
		framebuffer[(start.y + i.y) * d->win.size.x + (start.x + i.x)] = GRAY;
}

void	draw_minimap_border(t_data *d, t_minimap *minimap)
{
	t_vec2		i;

	i.y = 0;
	while (i.y < MINIMAP_SIZE)
	{
		i.x = 0;
		while (i.x < MINIMAP_SIZE)
		{
			draw_pixel_border(d, minimap, i);
			i.x++;
		}
		i.y++;
	}
}
