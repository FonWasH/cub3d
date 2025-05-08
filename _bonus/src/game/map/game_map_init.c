/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:38:01 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 10:44:59 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_map_textures(t_map *map)
{
	t_vec2	i;

	i.x = 0;
	while (i.x < MAP_MAX_TYPE)
	{
		i.y = 0;
		while (i.y < MAP_MAX_TEXTURE_TYPE)
		{
			map->tex[i.x][i.y].ptr = NULL;
			map->tex[i.x][i.y].data = NULL;
			i.y++;
		}
		i.x++;
	}
}

static void	get_elem_type(t_emap *emap, char c)
{
	if (c == 'F')
		emap->type = FLOOR;
	if (c == 'W')
		emap->type = WALL;
	if (c == 'S')
		emap->type = SHOP;
	if (c == 'P')
		emap->type = PDOOR;
	if (c == 'E')
		emap->type = EDOOR;
	if (emap->type == WALL || emap->type == SHOP || emap->type == PDOOR)
		emap->collision = BLOCK_RAY;
	if (emap->type == EDOOR)
		emap->collision = BLOCK_ENEMY;
}

static void	parse_map_elem(t_data *d, t_map *map, char *line, int x)
{
	int	y;

	y = 0;
	while (line && *line && y < MAP_SIZE_Y)
	{
		get_elem_type(&map->elem[x][y], *line);
		line++;
		map->elem[x][y].itex = (int)ft_atol(line);
		line += 4;
		y++;
	}
	if (y != MAP_SIZE_Y)
		error(d, ERROR_SYN, SCENE_PATH);
}

static void	parse_map_data(t_data *d, t_map *map)
{
	int		fd;
	char	*line;
	int		x;

	fd = open(SCENE_PATH, O_RDONLY);
	if (fd < 0)
		error(d, strerror(errno), SCENE_PATH);
	x = 0;
	line = get_next_line(fd);
	while (line && *line && x < MAP_SIZE_X)
	{
		parse_map_elem(d, map, line, x);
		x++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (x != MAP_SIZE_X)
		error(d, ERROR_SYN, SCENE_PATH);
}

void	init_map(t_data *d, t_map *map)
{
	t_vec2	i;

	init_map_textures(map);
	i.x = 0;
	while (i.x < MAP_SIZE_X)
	{
		i.y = 0;
		while (i.y < MAP_SIZE_Y)
		{
			map->elem[i.x][i.y].type = NONE;
			map->elem[i.x][i.y].itex = 0;
			map->elem[i.x][i.y].collision = BLOCK_NONE;
			map->elem[i.x][i.y].fcount = 0;
			i.y++;
		}
		i.x++;
	}
	parse_map_data(d, map);
}
