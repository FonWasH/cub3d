/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_render_wall_dist.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:32:56 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:38:59 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine_arg_walls.h"

static void	calc_ray_side(t_data *d, t_wdist_arg *args, t_vecf2 ray)
{
	if (ray.x < 0)
	{
		args->step.x = -1;
		args->side.x = (d->game.entity.player.pos.x - args->map.x)
			* args->delta.x;
	}
	else
	{
		args->step.x = 1;
		args->side.x = (args->map.x + 1.0f - d->game.entity.player.pos.x)
			* args->delta.x;
	}
	if (ray.y < 0)
	{
		args->step.y = -1;
		args->side.y = (d->game.entity.player.pos.y - args->map.y)
			* args->delta.y;
	}
	else
	{
		args->step.y = 1;
		args->side.y = (args->map.y + 1.0f - d->game.entity.player.pos.y)
			* args->delta.y;
	}
}

static void	check_ray_hit(t_data *d, t_wdist_arg *args, bool *is_side)
{
	bool	hit;

	hit = false;
	*is_side = false;
	while (!hit)
	{
		if (args->side.x < args->side.y)
		{
			args->side.x += args->delta.x;
			args->map.x += args->step.x;
			*is_side = false;
		}
		else
		{
			args->side.y += args->delta.y;
			args->map.y += args->step.y;
			*is_side = true;
		}
		if ((args->map.x >= d->game.map.size.x
				|| args->map.y >= d->game.map.size.y)
			|| d->game.map.elem[args->map.x][args->map.y] == WALL)
			hit = true;
	}
}

float	wall_dist(t_data *d, t_vecf2 ray, bool *is_side)
{
	t_wdist_arg	args;

	args.map.x = (int)d->game.entity.player.pos.x;
	args.map.y = (int)d->game.entity.player.pos.y;
	if (ray.x == 0)
		args.delta.x = 1e30f;
	else
		args.delta.x = fabsf(1.0f / ray.x);
	if (ray.y == 0)
		args.delta.y = 1e30f;
	else
		args.delta.y = fabsf(1.0f / ray.y);
	calc_ray_side(d, &args, ray);
	check_ray_hit(d, &args, is_side);
	if (*is_side)
		return (args.side.y - args.delta.y);
	else
		return (args.side.x - args.delta.x);
}
