/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_parse_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:57:44 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 17:02:23 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_line_map_elem(char *line)
{
	if (!*line || *line == '\n')
		return (false);
	while (*line)
	{
		if (*line != 'N' && *line != 'S' && *line != 'E' && *line != 'W'
			&& *line != '0' && *line != '1'
			&& !ft_isspace(*line) && *line != '\n')
			return (false);
		if (*line == '\n' && *(line + 1) == '\0')
			*line = '\0';
		line++;
	}
	return (true);
}

static t_emap	*get_row(t_map *map, char *line, int x, int width)
{
	t_emap	*elem;
	int		i;

	elem = ft_calloc(sizeof(t_emap), width + 1);
	if (!elem)
		return (NULL);
	elem[width] = NILL;
	i = 0;
	while (*line)
	{
		if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
		{
			elem[i] = SPAWN;
			map->spawn.pos.x = x;
			map->spawn.pos.y = i;
			map->spawn.dir = *line;
		}
		else if (*line == '0' || *line == '1')
			elem[i] = *line - '0';
		else if (ft_isspace(*line))
			elem[i] = EMPTY;
		line++;
		i++;
	}
	return (elem);
}

bool	parse_map_elem(t_map *map, char *line)
{
	int		width;

	if (is_line_map_elem(line))
	{
		width = ft_strlen(line);
		map->elem = ft_realloc(map->elem, sizeof(t_emap *) * map->size.x,
				sizeof(t_emap *) * (map->size.x + 1));
		if (!map->elem)
			return (put_error(ERROR_MEM, NULL), false);
		if (map->size.y < width)
			map->size.y = width;
		map->elem[map->size.x] = get_row(map, line, map->size.x, width);
		if (!map->elem[map->size.x])
			return (put_error(ERROR_MEM, NULL), false);
		map->size.x++;
		return (true);
	}
	return (put_error(ERROR_SYN, map->path), false);
}
