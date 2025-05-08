/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_render_floor_draw.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 04:46:33 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:34:09 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine_arg_floor.h"

static void	init_arg(t_data *d, t_floor_arg *arg)
{
	arg->half_h = d->win.half_h;
	arg->w = d->win.size.x;
	arg->ray = d->engine.graphic.render.ray;
	arg->ray_rmag = d->engine.graphic.render.ray_rmag;
	arg->angle = d->engine.graphic.render.angle;
	arg->cam = d->engine.graphic.cam;
	arg->fog = d->engine.graphic.fog;
	arg->player_cam = d->game.entity.player.cam;
	arg->player_pos = d->game.entity.player.pos;
	arg->framebuffer = d->engine.graphic.frame.data;
	arg->floor_tex = d->game.map.tex[F].img.data;
	arg->ceil_tex = d->game.map.tex[C].img.data;
	arg->floor_col = d->game.map.tex[F].col;
	arg->ceil_col = d->game.map.tex[C].col;
}

static void	row_dist(t_floor_arg *arg, int y)
{
	int	relative_y;

	relative_y = y - arg->half_h - arg->player_cam.poffset;
	arg->is_floor = (relative_y > 0);
	if (arg->is_floor)
		arg->row_dist = (arg->cam.fhoffset / (float)relative_y);
	else
		arg->row_dist = (arg->cam.choffset / (float)-relative_y);
}

static void	pixel_color(t_floor_arg *arg, int x)
{
	t_vecf2	floor;
	t_vec2	pos;

	if (arg->is_floor)
		arg->color = (uint32_t)arg->floor_col;
	else
		arg->color = (uint32_t)arg->ceil_col;
	if ((!arg->is_floor && arg->ceil_col == NO_COLOR)
		|| (arg->is_floor && arg->floor_col == NO_COLOR))
	{
		floor.x = arg->player_pos.x + arg->dist
			* (arg->ray[x].x * arg->ray_rmag[x]);
		floor.y = arg->player_pos.y + arg->dist
			* (arg->ray[x].y * arg->ray_rmag[x]);
		pos.x = ((int)(floor.x * TEXTURE_SIZE)) & (TEXTURE_SIZE - 1);
		pos.y = ((int)(floor.y * TEXTURE_SIZE)) & (TEXTURE_SIZE - 1);
		if (arg->is_floor)
			arg->color = arg->floor_tex[(pos.y << TEXTURE_SIZE_LOG2) + pos.x];
		else
			arg->color = arg->ceil_tex[(pos.y << TEXTURE_SIZE_LOG2) + pos.x];
	}
}

static bool	put_pixel(t_floor_arg *arg, t_vec2 i)
{
	if (arg->ray[i.x].x == 0 && arg->ray[i.x].y == 0)
		return (false);
	arg->dist = arg->row_dist / fmaxf(arg->angle[i.x], 0.0001f);
	pixel_color(arg, i.x);
	apply_fog(&arg->fog, &arg->color, arg->dist);
	arg->framebuffer[i.y * arg->w + i.x] = arg->color;
	return (true);
}

void	draw_floor(t_data *d)
{
	t_floor_arg	floor_arg;
	t_vec2		i;

	init_arg(d, &floor_arg);
	i.y = 0;
	while (i.y < d->win.size.y)
	{
		row_dist(&floor_arg, i.y);
		i.x = 0;
		while (i.x < d->win.size.x)
		{
			put_pixel(&floor_arg, i);
			i.x++;
		}
		i.y++;
	}
}
