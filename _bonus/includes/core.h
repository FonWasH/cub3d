/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 08:18:57 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 15:34:42 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# define NAME			"cub3D"

# define ERROR			"ERROR\n"
# define ERROR_MLX		"Failed to initialize MiniLibX"
# define ERROR_WIN		"Failed to create window"
# define ERROR_MEM		"Failed to allocate memory"
# define ERROR_IMG		"Failed to create image"
# define ERROR_THD		"Failed to create thread"
# define ERROR_SYN		"Syntax error in scene file"
# define ERROR_CFG		"Configuration error in MiniLibX window"

# define USAGE			"Usage: ./cub3D"

# ifndef DEBUG
#  define DEBUG		0
# endif

# define WIN_WIDTH		1920
# define WIN_HEIGHT		1080
# define MAX_WIDTH		3840
# define MAX_HEIGHT		2160
# define TEXTURES_COUNT	69
# define ESPRITES_COUNT	132
# define HSPRITES_COUNT	24
# define PSRITES_COUNT	54

# define BYTE			8
# define FLT_MAX		3.402823466e+38F

# include "game.h"
# include "engine.h"

typedef struct s_win
{
	void		*ptr;
	t_vec2		size;
	int			half_w;
	int			half_h;
}				t_win;

typedef struct s_time
{
	long		current;
	long		old;
	float		delta;
}				t_time;

typedef struct s_load
{
	bool		loaded;
	bool		loading;
	bool		error;
	bool		audio_done;
	bool		textures_done;
	bool		esprites_done;
	bool		hsprites_done;
	bool		psprites_done;
	int			audio_count;
	int			textures_count;
	int			esprites_count;
	int			hsprites_count;
	int			psprites_count;
}				t_load;

typedef struct s_data
{
	void		*mlx;
	t_win		win;
	t_game		game;
	t_engine	engine;
	t_time		time;
	t_load		load;
}				t_data;

void	init_win_size(t_data *d, int height, int width);
void	init_core(t_data *d);
void	load_core(t_data *d);
void	free_core(t_data *d);
int		loop_core(void *data);
void	hook_core(t_data *d);
int		exit_core(t_data *d);
void	error(t_data *d, char *error, char *extra);
void	put_error(char *error, char *extra);

#endif
