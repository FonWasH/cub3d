/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_render_wall_draw.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 04:31:28 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:36:09 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine_arg_walls.h"

static void	init_arg(t_data *d, t_walls_arg *arg)
{
	arg->half_h = d->win.half_h;
	arg->h = d->win.size.y;
	arg->w = d->win.size.x;
	arg->ray = d->engine.graphic.render.ray;
	arg->fog = d->engine.graphic.fog;
	arg->player_cam = d->game.entity.player.cam;
	arg->player_pos = d->game.entity.player.pos;
	arg->player_h = d->game.entity.player.height;
	arg->framebuffer = d->engine.graphic.frame.data;
	arg->tex = d->game.map.tex;
	arg->wall_tex = NULL;
	arg->tpos.x = 0;
	arg->tpos.y = 0;
	arg->tcurrent = 0.0f;
	arg->tstep = 0.0f;
}

static void	pixel_texture(t_walls_arg *arg, t_vecf2 ray)
{
	float	wall_pos;

	arg->wall_tex = arg->tex[arg->tindex].img.data;
	if (!arg->is_side)
		wall_pos = arg->player_pos.y + arg->dist * ray.y;
	else
		wall_pos = arg->player_pos.x + arg->dist * ray.x;
	wall_pos -= floorf(wall_pos);
	arg->tpos.x = (int)(wall_pos * TEXTURE_SIZE);
	if ((!arg->is_side && ray.x > 0) || (arg->is_side && ray.y < 0))
		arg->tpos.x = TEXTURE_SIZE - arg->tpos.x - 1;
	arg->tstep = (float)TEXTURE_SIZE / arg->line_h;
	arg->tcurrent = (arg->start - arg->player_cam.poffset - arg->half_h
			+ (arg->line_h >> 1) - arg->hoffset) * arg->tstep;
}

static bool	calc_frame_col(t_data *d, t_walls_arg *arg, t_vecf2 ray)
{
	if (ray.x == 0 && ray.y == 0)
		return (false);
	arg->dist = wall_dist(d, ray, &arg->is_side);
	if (arg->dist <= 0.0f)
		return (false);
	arg->line_h = (int)((arg->h / arg->dist) * arg->player_cam.rzoom);
	if (arg->line_h <= 0)
		return (false);
	arg->hoffset = (int)(arg->player_h * arg->h / arg->dist);
	arg->start = -(arg->line_h >> 1) + arg->half_h
		+ arg->player_cam.poffset + arg->hoffset;
	arg->end = (arg->line_h >> 1) + arg->half_h
		+ arg->player_cam.poffset + arg->hoffset;
	if (arg->start < 0)
		arg->start = 0;
	if (arg->end >= arg->h)
		arg->end = arg->h - 1;
	arg->tindex = wall_tex_index(arg->is_side, ray);
	if (d->game.map.tex[arg->tindex].col == NO_COLOR)
		pixel_texture(arg, ray);
	return (true);
}

static void	put_pixel(t_walls_arg *arg, t_vec2 i)
{
	uint32_t	color;

	if (arg->tex[arg->tindex].col == NO_COLOR)
	{
		arg->tpos.y = (int)arg->tcurrent & (TEXTURE_SIZE - 1);
		arg->tcurrent += arg->tstep;
		color = arg->wall_tex[
			(arg->tpos.y << TEXTURE_SIZE_LOG2) + arg->tpos.x];
	}
	else
		color = (uint32_t)arg->tex[arg->tindex].col;
	apply_fog(&arg->fog, &color, arg->dist);
	arg->framebuffer[i.y * arg->w + i.x] = color;
}

void	draw_walls(t_data *d)
{
	t_walls_arg	walls_arg;
	t_vec2		i;

	init_arg(d, &walls_arg);
	i.x = 0;
	while (i.x < d->win.size.x)
	{
		if (!calc_frame_col(d, &walls_arg, d->engine.graphic.render.ray[i.x]))
			continue ;
		i.y = walls_arg.start;
		while (i.y < walls_arg.end)
		{
			put_pixel(&walls_arg, i);
			i.y++;
		}
		i.x++;
	}
}
