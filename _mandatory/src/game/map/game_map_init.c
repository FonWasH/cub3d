/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:38:01 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 17:01:51 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	init_map(t_map *map, char *path, void *mlx_ptr)
{
	int	i;

	map->path = path;
	map->elem = NULL;
	map->size.x = 0;
	map->size.y = 0;
	map->spawn.pos.x = 0;
	map->spawn.pos.y = 0;
	map->spawn.dir = '\0';
	i = 0;
	while (i < MAP_TEXTURE_NB)
	{
		map->tex[i].img.ptr = NULL;
		map->tex[i].img.data = NULL;
		map->tex[i].col = NO_COLOR;
		i++;
	}
	if (!parse_map(map, mlx_ptr))
		return (false);
	if (DEBUG)
		put_map(map);
	return (true);
}
