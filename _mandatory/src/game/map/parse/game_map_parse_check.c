/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_parse_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:07:45 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 17:04:05 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_edges_valid(t_emap **elem, t_vec2 i, t_vec2 size)
{
	if (i.x == 0 || i.x == size.x - 1)
		return (elem[i.x][i.y] == WALL || elem[i.x][i.y] == EMPTY);
	if (i.y == 0 || i.y == size.y - 1)
		return (elem[i.x][i.y] == WALL || elem[i.x][i.y] == EMPTY);
	return (true);
}

static bool	is_inner_valid(t_emap **elem, t_vec2 i, t_vec2 size)
{
	if (i.x > 0 && i.x < size.x - 1 && i.y > 0 && i.y < size.y - 1
		&& elem[i.x][i.y] != WALL && elem[i.x][i.y] != EMPTY)
		return (elem[i.x][i.y + 1] != EMPTY
			&& elem[i.x][i.y - 1] != EMPTY
			&& elem[i.x + 1][i.y] != EMPTY
			&& elem[i.x - 1][i.y] != EMPTY);
	return (true);
}

static bool	format_map(t_map *map)
{
	t_vec2	i;

	i.x = 0;
	while (i.x < map->size.x)
	{
		i.y = 0;
		while (map->elem[i.x][i.y] != NILL)
			i.y++;
		if (i.y < map->size.y)
		{
			map->elem[i.x] = ft_realloc(map->elem[i.x],
					sizeof(t_emap) * (i.y + 1),
					sizeof(t_emap) * (map->size.y + 1));
			if (!map->elem[i.x])
				return (put_error(ERROR_MEM, NULL), false);
			while (i.y < map->size.y)
			{
				map->elem[i.x][i.y] = EMPTY;
				i.y++;
			}
			map->elem[i.x][i.y] = NILL;
		}
		i.x++;
	}
	return (true);
}

bool	check_map(t_map *map)
{
	t_vec2	i;
	int		spawn;

	if (!format_map(map))
		return (false);
	spawn = 0;
	i.x = 0;
	while (i.x < map->size.x)
	{
		i.y = 0;
		while (i.y < map->size.y)
		{
			if (!is_edges_valid(map->elem, i, map->size))
				return (put_error(ERROR_SYN, map->path), false);
			if (!is_inner_valid(map->elem, i, map->size))
				return (put_error(ERROR_SYN, map->path), false);
			if (map->elem[i.x][i.y] == SPAWN)
				spawn++;
			i.y++;
		}
		i.x++;
	}
	if (spawn != 1)
		put_error(ERROR_SYN, map->path);
	return ((spawn == 1));
}
