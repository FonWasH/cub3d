/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_minimap_draw.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:16:47 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 12:48:19 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	pixel_color(t_data *d, t_vec2 pos)
{
	if (d->game.map.elem[pos.x][pos.y].type == WALL)
		return (GRAY);
	if (d->game.map.elem[pos.x][pos.y].type == FLOOR)
		return (BLACK);
	if (d->game.map.elem[pos.x][pos.y].type == EDOOR)
		return (RED);
	if (d->game.map.elem[pos.x][pos.y].type == PDOOR)
		return (BLUE);
	if (d->game.map.elem[pos.x][pos.y].type == SHOP)
		return (CYAN);
	return (BLACK);
}

static void	put_pixel(t_data *d, t_minimap *minimap, t_vecf2 map, t_vec2 i)
{
	uint32_t	*fb;
	t_vec2		map_pos;
	t_vec2		screen;

	fb = d->engine.graphic.frame.data;
	map_pos.x = (int)map.x;
	map_pos.y = (int)map.y;
	if (map_pos.x >= 0 && map_pos.x < MAP_SIZE_X
		&& map_pos.y >= 0 && map_pos.y < MAP_SIZE_Y)
	{
		screen.x = minimap->center.x + minimap->pos.x + i.x;
		screen.y = minimap->center.y + minimap->pos.y + i.y;
		if (screen.x >= 0 && screen.x < d->win.size.x
			&& screen.y >= 0 && screen.y < d->win.size.y)
			fb[screen.y * d->win.size.x + screen.x] = pixel_color(d, map_pos);
	}
}

static void	pixel_pos(t_data *d, t_minimap *minimap, float angle, t_vec2 i)
{
	t_vecf2	rot;	
	t_vecf2	map;
	float	dist;

	dist = mag(i);
	if (dist < minimap->center.x)
	{
		rot.x = i.x * cosf(-angle) - i.y * sinf(-angle);
		rot.y = i.x * sinf(-angle) + i.y * cosf(-angle);
		rot.x = -rot.x;
		map.x = d->game.entities.player.pos.x + rot.x / minimap->scale.x;
		map.y = d->game.entities.player.pos.y + rot.y / minimap->scale.y;
		put_pixel(d, minimap, map, i);
	}
}

static void	draw_minimap_content(t_data *d, t_minimap *minimap)
{
	t_vec2	i;
	float	angle;

	angle = atan2(d->game.entities.player.cam.dir.y,
			d->game.entities.player.cam.dir.x) + PI_2;
	i.y = -minimap->center.y;
	while (i.y < minimap->center.y)
	{
		i.x = -minimap->center.x;
		while (i.x < minimap->center.x)
		{
			pixel_pos(d, minimap, angle, i);
			i.x++;
		}
		i.y++;
	}
}

void	draw_minimap(t_data *d)
{
	draw_minimap_background(d, &d->game.ui.minimap);
	draw_minimap_content(d, &d->game.ui.minimap);
	draw_minimap_player(d, &d->game.ui.minimap.triangle);
	draw_minimap_border(d, &d->game.ui.minimap);
}
