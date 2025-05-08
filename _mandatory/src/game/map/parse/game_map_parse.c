/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 01:32:48 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 17:28:05 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_map(t_map *map, void *mlx_ptr)
{
	int		fd;
	char	*line;
	bool	done;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		return (put_error(strerror(errno), map->path), false);
	if (read(fd, 0, 0) < 0)
		return (put_error(strerror(errno), map->path), false);
	done = false;
	line = get_next_line(fd);
	while (line)
	{
		if (*line && *line != '\n')
		{
			if (!done && !parse_map_texture(map, line, &done, mlx_ptr))
				return (close(fd), free(line), false);
			if (done && !parse_map_elem(map, line))
				return (close(fd), free(line), false);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (check_map(map));
}
