/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_fps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 06:42:11 by juperez           #+#    #+#             */
/*   Updated: 2025/04/11 02:33:01 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fps_int_str(float fps, char *s_int)
{
	int	fps_int;

	fps_int = (int)fps;
	if (fps_int > FPS_MAX)
		fps_int = FPS_MAX;
	if (fps_int < 0)
		fps_int = 0;
	s_int[0] = ' ';
	s_int[1] = ' ';
	s_int[2] = '0';
	if (fps_int >= 100)
		s_int[0] = fps_int / 100 + '0';
	if (fps_int >= 10)
		s_int[1] = (fps_int / 10) % 10 + '0';
	if (fps_int >= 1)
		s_int[2] = fps_int % 10 + '0';
	s_int[3] = '\0';
}

static void	fps_dec_str(float fps, char *s_dec)
{
	int	fps_int;
	int	fps_dec;

	fps_int = (int)fps;
	if (fps_int > FPS_MAX)
		fps_int = FPS_MAX;
	if (fps_int < 0)
		fps_int = 0;
	fps_dec = (int)((fps - fps_int) * 100);
	if (fps_dec < 0)
		fps_dec = 0;
	s_dec[0] = fps_dec / 10 + '0';
	s_dec[1] = fps_dec % 10 + '0';
	s_dec[2] = '\0';
}

void	show_fps(float delta_time, void *mlx_ptr, void *win_ptr)
{
	float		current_fps;
	char		s_int[4];
	char		s_dec[3];
	uint32_t	color;

	current_fps = fps(delta_time);
	color = set_color((t_color){255, 255, 255});
	if (current_fps >= 1.0f)
	{
		fps_int_str(current_fps, s_int);
		mlx_string_put(mlx_ptr, win_ptr, 10, 20, color, s_int);
	}
	else
	{
		fps_dec_str(current_fps, s_dec);
		mlx_string_put(mlx_ptr, win_ptr, 10, 20, color, "  0");
		mlx_string_put(mlx_ptr, win_ptr, 28, 20, color, ".");
		mlx_string_put(mlx_ptr, win_ptr, 34, 20, color, s_dec);
	}
}
