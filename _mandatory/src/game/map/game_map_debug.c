/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:22:05 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 09:11:04 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_map_texture(t_map *map)
{
	static const char	*ids[] = {"NO", "SO", "EA", "WE", "F", "C", NULL};
	int					i;

	i = 0;
	while (ids[i])
	{
		printf("%s:\timage: %p\n\tcolor: %d\n",
			ids[i], map->tex[i].img.ptr, map->tex[i].col);
		i++;
	}
}

void	put_map(t_map *map)
{
	t_vec2	i;

	put_map_texture(map);
	printf("Map:");
	printf("\tsize: %d/%d\n", map->size.x, map->size.y);
	printf("\tpath: %s\n", map->path);
	i.x = 0;
	while (i.x < map->size.x)
	{
		i.y = 0;
		while (i.y < map->size.y)
		{
			printf("%d", map->elem[i.x][i.y]);
			i.y++;
		}
		printf("\n");
		i.x++;
	}
}
