/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_walls_dist.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:16:30 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 02:30:17 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine_graphic_walls_arg.h"

static void	calc_ray_side(t_walls_arg *w, t_wdist_arg *args, t_vecf2 ray)
{
	if (ray.x < 0)
	{
		args->step.x = -1;
		args->side.x = (w->player_pos.x - args->map.x) * args->delta.x;
	}
	else
	{
		args->step.x = 1;
		args->side.x = (args->map.x + 1.0f - w->player_pos.x) * args->delta.x;
	}
	if (ray.y < 0)
	{
		args->step.y = -1;
		args->side.y = (w->player_pos.y - args->map.y) * args->delta.y;
	}
	else
	{
		args->step.y = 1;
		args->side.y = (args->map.y + 1.0f - w->player_pos.y) * args->delta.y;
	}
}

static void	check_ray_hit(t_walls_arg *w, t_wdist_arg *args)
{
	bool	hit;

	hit = false;
	w->is_side = false;
	while (!hit)
	{
		if (args->side.x < args->side.y)
		{
			args->side.x += args->delta.x;
			args->map.x += args->step.x;
			w->is_side = false;
		}
		else
		{
			args->side.y += args->delta.y;
			args->map.y += args->step.y;
			w->is_side = true;
		}
		if ((args->map.x >= MAP_SIZE_X || args->map.y >= MAP_SIZE_Y)
			|| w->map.elem[args->map.x][args->map.y].collision == BLOCK_RAY)
			hit = true;
	}
}

void	wall_dist(t_walls_arg *w, t_vecf2 ray)
{
	t_wdist_arg	args;

	args.map.x = (int)w->player_pos.x;
	args.map.y = (int)w->player_pos.y;
	if (ray.x == 0)
		args.delta.x = 1e30f;
	else
		args.delta.x = fabsf(1.0f / ray.x);
	if (ray.y == 0)
		args.delta.y = 1e30f;
	else
		args.delta.y = fabsf(1.0f / ray.y);
	calc_ray_side(w, &args, ray);
	check_ray_hit(w, &args);
	w->impact = args.map;
	if (w->is_side)
		w->dist = args.side.y - args.delta.y;
	else
		w->dist = args.side.x - args.delta.x;
}
