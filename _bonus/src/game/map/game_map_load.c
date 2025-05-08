/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:13:04 by juperez           #+#    #+#             */
/*   Updated: 2025/05/04 18:03:16 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "resources_textures_map.h"

static void	load_textures(t_data *d, t_image *map_tex,
	int count, const char *paths[])
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (d->load.error)
			return ;
		map_tex[i] = open_img(d->mlx, (char *)paths[i]);
		if (!map_tex[i].ptr)
		{
			d->load.error = true;
			return (put_error(ERROR_IMG, (char *)paths[i]));
		}
		d->load.textures_count++;
		i++;
	}
}

static void	load_floor_ceil_wall_door_textures(t_data *d, t_map *map)
{
	const char	*floor_paths[] = {
		MF1A1, MF2A1, MF2B1, MF2C1, MF2D1, MF2E1, MF2F1, MF2G1, MF2H1};
	const char	*ceil_paths[] = {
		MC1A1, MC2A1, MC2C1, MC2B1, MC2D1, MC2E1, MC2F1, MC2G1, MC2H1};
	const char	*wall_paths[] = {
		MW1A1, MW2A1, MW3A1, MW3B1, MW3C1, MW3D1, MW3E1, MW3F1,
		MW3G1, MW3H1, MW3I1, MW3J1, MW3K1, MW3L1, MW3M1, MW3N1,
		MW4A1, MW4B1, MW4C1, MW4D1, MW4E1, MW4F1, MW4G1, MW4H1,
		MW4I1, MW4J1, MW5A1, MW5B1, MW5C1, MW5D1, MW5E1, MW6A1,
		MW6B1, MW6C1, MW6D1, MW6E1, MW6F1};
	const char	*edoor_paths[] = {ME1A1};
	const char	*pdoor_paths[] = {
		MP1A1, MP1A2, MP1A3, MP1A4, MP1A5, MP1A6, MP1A7};

	load_textures(d, map->tex[TF], 9, floor_paths);
	load_textures(d, map->tex[TC], 9, ceil_paths);
	load_textures(d, map->tex[TW], 37, wall_paths);
	load_textures(d, map->tex[TE], 1, edoor_paths);
	load_textures(d, map->tex[TP], 7, pdoor_paths);
}

static void	load_shop_textures(t_data *d, t_map *map)
{
	const char	*shop_paths[] = {MS1A1, MS1A2, MS1A3, MS1B1, MS1B2, MS1B3};

	return (load_textures(d, map->tex[TS], 6, shop_paths));
}

void	*load_map(void *arg)
{
	t_task_arg	*task;
	t_data		*d;
	t_map		*map;

	task = (t_task_arg *)arg;
	d = task->d;
	map = &d->game.map;
	load_floor_ceil_wall_door_textures(d, map);
	load_shop_textures(d, map);
	d->load.textures_done = true;
	return (free(task), NULL);
}
