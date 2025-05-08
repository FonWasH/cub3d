/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_floor_draw.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:01:23 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 11:57:14 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine_graphic_floor_arg.h"

static void	init_arg(t_data *d, t_floor_arg *f)
{
	f->w = d->win.size.x;
	f->half_h = d->win.half_h;
	f->rays = d->engine.graphic.rays.lut;
	f->rays_rmag = d->engine.graphic.floor.rays_rmag;
	f->angle = d->engine.graphic.floor.angle;
	f->fz_offset = d->engine.graphic.floor.fz_offset;
	f->cz_offset = d->engine.graphic.floor.cz_offset;
	f->fog = d->engine.graphic.fog;
	f->player_cam = d->game.entities.player.cam;
	f->player_pos = d->game.entities.player.pos;
	f->map = d->game.map;
	f->framebuffer = d->engine.graphic.frame.data;
	f->tex = NULL;
}

static void	row_dist(t_floor_arg *f, int y)
{
	int	relative_y;

	relative_y = y - f->half_h - f->player_cam.p_offset;
	f->is_floor = (relative_y > 0);
	if (f->is_floor)
		f->row_dist = (f->fz_offset / (float)relative_y);
	else
		f->row_dist = (f->cz_offset / (float)-relative_y);
}

static void	put_pixel(t_floor_arg *f, t_vec2 i)
{
	float		dist;
	t_vecf2		hit;
	t_vec2		tpos;
	int			itex;
	uint32_t	color;

	if (f->rays[i.x].x == 0 && f->rays[i.x].y == 0)
		return ;
	dist = f->row_dist / fmaxf(f->angle[i.x], 0.0001f);
	hit.x = f->player_pos.x + dist * (f->rays[i.x].x * f->rays_rmag[i.x]);
	hit.y = f->player_pos.y + dist * (f->rays[i.x].y * f->rays_rmag[i.x]);
	if (hit.x >= MAP_SIZE_X || hit.y >= MAP_SIZE_Y || hit.x < 0 || hit.y < 0)
		return ;
	tpos.x = ((int)(hit.x * TEXTURE_SIZE)) & (TEXTURE_SIZE - 1);
	tpos.y = ((int)(hit.y * TEXTURE_SIZE)) & (TEXTURE_SIZE - 1);
	itex = 1;
	if (f->map.elem[(int)hit.x][(int)hit.y].type == FLOOR)
		itex = f->map.elem[(int)hit.x][(int)hit.y].itex;
	if (f->is_floor)
		f->tex = f->map.tex[TF][itex].data;
	else
		f->tex = f->map.tex[TC][itex].data;
	color = f->tex[(tpos.y << TEXTURE_SIZE_LOG2) + tpos.x];
	apply_fog(&f->fog, &color, dist);
	f->framebuffer[i.y * f->w + i.x] = color;
}

void	*draw_floor(void *arg)
{
	t_task_arg	*task;
	t_data		*d;
	t_floor_arg	f;
	t_vec2		i;

	task = (t_task_arg *)arg;
	d = task->d;
	init_arg(d, &f);
	i.y = task->start;
	while (i.y < task->end)
	{
		row_dist(&f, i.y);
		i.x = 0;
		while (i.x < f.w)
		{
			put_pixel(&f, i);
			i.x++;
		}
		i.y++;
	}
	return (free(task), NULL);
}
