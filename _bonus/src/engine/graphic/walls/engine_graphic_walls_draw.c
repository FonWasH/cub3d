/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_walls_draw.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:16:57 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 11:36:42 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine_graphic_walls_arg.h"

static void	init_arg(t_data *d, t_walls_arg *w)
{
	w->h = d->win.size.y;
	w->w = d->win.size.x;
	w->half_h = d->win.half_h;
	w->rays = d->engine.graphic.rays.lut;
	w->fog = d->engine.graphic.fog;
	w->player_cam = d->game.entities.player.cam;
	w->player_pos = d->game.entities.player.pos;
	w->zbuffer = d->engine.graphic.zbuffer;
	w->framebuffer = d->engine.graphic.frame.data;
	w->map = d->game.map;
	w->tex = NULL;
	w->tpos.x = 0;
	w->tpos.y = 0;
	w->tcurrent = 0.0f;
	w->tstep = 0.0f;
}

static void	pixel_texture(t_walls_arg *w, t_vecf2 ray)
{
	float	wall_pos;

	if (!w->is_side)
		wall_pos = w->player_pos.y + w->dist * ray.y;
	else
		wall_pos = w->player_pos.x + w->dist * ray.x;
	wall_pos -= floorf(wall_pos);
	w->tpos.x = (int)(wall_pos * TEXTURE_SIZE);
	if ((!w->is_side && ray.x > 0) || (w->is_side && ray.y < 0))
		w->tpos.x = TEXTURE_SIZE - w->tpos.x - 1;
	w->tstep = (float)TEXTURE_SIZE / w->line_h;
	w->tcurrent = (w->start - w->player_cam.p_offset - w->half_h
			+ (w->line_h >> 1) - w->z_offset) * w->tstep;
}

static bool	calc_frame_col(t_walls_arg *w, t_vec2 *i)
{
	if (w->rays[(*i).x].x == 0 && w->rays[(*i).x].y == 0)
		return ((*i).x++, false);
	wall_dist(w, w->rays[(*i).x]);
	if (w->dist <= 0.0f)
		return ((*i).x++, false);
	w->line_h = (int)((w->h / w->dist) * w->player_cam.rzoom);
	if (w->line_h <= 0)
		return ((*i).x++, false);
	w->z_offset = (int)(w->player_pos.z * w->h / w->dist);
	w->start = -(w->line_h >> 1) + w->half_h
		+ w->player_cam.p_offset + w->z_offset;
	w->end = (w->line_h >> 1) + w->half_h
		+ w->player_cam.p_offset + w->z_offset;
	if (w->start < 0)
		w->start = 0;
	if (w->end >= w->h)
		w->end = w->h - 1;
	w->tex = wall_tex_index(w);
	if (w->tex == NULL)
		return ((*i).x++, false);
	pixel_texture(w, w->rays[(*i).x]);
	return (true);
}

static void	put_pixel(t_walls_arg *w, t_vec2 i)
{
	uint32_t	color;

	w->tpos.y = (int)w->tcurrent & (TEXTURE_SIZE - 1);
	w->tcurrent += w->tstep;
	color = w->tex[(w->tpos.y << TEXTURE_SIZE_LOG2) + w->tpos.x];
	apply_fog(&w->fog, &color, w->dist);
	w->framebuffer[i.y * w->w + i.x] = color;
	w->zbuffer[i.x][i.y] = w->dist;
}

void	*draw_walls(void *arg)
{
	t_task_arg	*task;
	t_data		*d;
	t_walls_arg	w;
	t_vec2		i;

	task = (t_task_arg *)arg;
	d = task->d;
	init_arg(d, &w);
	i.x = task->start;
	while (i.x < task->end)
	{
		if (!calc_frame_col(&w, &i))
			continue ;
		i.y = w.start;
		while (i.y < w.end)
		{
			put_pixel(&w, i);
			i.y++;
		}
		i.x++;
	}
	return (free(task), NULL);
}
