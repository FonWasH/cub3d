/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:29:02 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 17:00:13 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map, void *mlx_ptr)
{
	int	i;

	if (map->elem)
		ft_mfree((void **)map->elem, (size_t)map->size.x);
	i = 0;
	while (i < MAP_TEXTURE_NB)
	{
		if (map->tex[i].img.ptr)
			mlx_destroy_image(mlx_ptr, map->tex[i].img.ptr);
		i++;
	}
}
