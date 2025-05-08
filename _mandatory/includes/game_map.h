/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:02:21 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:26:47 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MAP_H
# define GAME_MAP_H

# define MAP_TEXTURE_NB	6

typedef enum e_emap
{
	FLOOR,
	WALL,
	SPAWN,
	EMPTY,
	NILL
}	t_emap;

typedef enum e_itex
{
	NO,
	SO,
	EA,
	WE,
	F,
	C
}	t_itex;

typedef struct s_mtex
{
	t_image	img;
	int		col;
}			t_mtex;

typedef struct s_spwn
{
	t_vec2	pos;
	char	dir;
}			t_spwn;

typedef struct s_map
{
	char	*path;
	t_emap	**elem;
	t_vec2	size;
	t_spwn	spawn;
	t_mtex	tex[MAP_TEXTURE_NB];
}			t_map;

bool	init_map(t_map *map, char *path, void *mlx_ptr);
void	free_map(t_map *map, void *mlx_ptr);
void	put_map(t_map *map);
bool	parse_map(t_map *map, void *mlx_ptr);
bool	parse_map_texture(t_map *map, char *line, bool *done, void *mlx_ptr);
bool	parse_map_elem(t_map *map, char *line);
bool	check_map(t_map *map);
int		line_to_color(char *line);
t_image	line_to_image(char *line, void *mlx_ptr);

#endif