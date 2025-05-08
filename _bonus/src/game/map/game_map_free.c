/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:29:02 by juperez           #+#    #+#             */
/*   Updated: 2025/04/28 08:03:46 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map, void *mlx_ptr)
{
	t_vec2	i;

	i.x = 0;
	while (i.x < MAP_MAX_TYPE)
	{
		i.y = 0;
		while (i.y < MAP_MAX_TEXTURE_TYPE)
		{
			if (map->tex[i.x][i.y].ptr)
				mlx_destroy_image(mlx_ptr, map->tex[i.x][i.y].ptr);
			i.y++;
		}
		i.x++;
	}
}
