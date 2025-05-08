/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 08:18:57 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 15:34:39 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# define NAME		"cub3D"

# define ERROR		"ERROR\n"
# define ERROR_MLX	"Failed to initialize MiniLibX"
# define ERROR_WIN	"Failed to create window"
# define ERROR_MEM	"Failed to allocate memory"
# define ERROR_IMG	"Failed to create image"
# define ERROR_THD	"Failed to create thread"
# define ERROR_SYN	"Syntax error in scene file"
# define ERROR_CFG	"Configuration error in MiniLibX window"

# define USAGE		"Usage: ./cub3D <scene_file>.cub"

# ifndef DEBUG
#  define DEBUG		0
# endif

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define MAX_WIDTH	3840
# define MAX_HEIGHT	2160

# define BYTE		8

# include "game.h"
# include "engine.h"

typedef struct s_win
{
	void		*ptr;
	t_vec2		size;
	int			half_h;
}				t_win;

typedef struct s_time
{
	long		current;
	long		old;
	float		delta;
}				t_time;

typedef struct s_data
{
	void		*mlx;
	t_win		win;
	t_game		game;
	t_engine	engine;
	t_time		time;
}				t_data;

void	init_core(t_data *d, char *path);
void	free_core(t_data *d);
int		loop_core(void *data);
void	hook_core(t_data *d);
int		exit_core(t_data *d);
void	error(t_data *d, char *error, char *extra);
void	put_error(char *error, char *extra);

#endif
