/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_parse_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:18:56 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 17:04:38 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_parse_texture_done(t_map *map)
{
	int	i;

	i = 0;
	while (i < MAP_TEXTURE_NB)
	{
		if (!map->tex[i].img.ptr && map->tex[i].col == NO_COLOR)
			return (false);
		i++;
	}
	return (true);
}

static bool	get_tex(t_map *map, char *line, void *mlx_ptr)
{
	static const char	*ids[] = {"NO", "SO", "EA", "WE", "F", "C", NULL};
	int					i;

	i = 0;
	while (ids[i])
	{
		if (!ft_strncmp(line, (char *)ids[i], ft_strlen((char *)ids[i])))
		{
			if (map->tex[i].img.ptr || map->tex[i].col != NO_COLOR)
				return (put_error(ERROR_SYN, map->path), false);
			line += 2 - (i > 3);
			while (*line && ft_isspace(*line))
				line++;
			line[ft_strlen(line) - 1] = '\0';
			map->tex[i].col = line_to_color(line);
			map->tex[i].img = line_to_image(line, mlx_ptr);
			if (!map->tex[i].img.ptr && map->tex[i].col == NO_COLOR)
				return (put_error(ERROR_SYN, map->path), false);
			return (true);
		}
		i++;
	}
	return (put_error(ERROR_SYN, map->path), false);
}

bool	parse_map_texture(t_map *map, char *line, bool *done, void *mlx_ptr)
{
	*done = is_parse_texture_done(map);
	if (!*done)
		return (get_tex(map, line, mlx_ptr));
	return (true);
}
