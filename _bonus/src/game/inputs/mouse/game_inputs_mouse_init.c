/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs_mouse_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:41:24 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 10:28:58 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mouse(t_mouse *mouse, void *mlx_ptr, void *win_ptr)
{
	int	i;

	i = 0;
	while (i < MOUSE_BUTTON_NB)
	{
		mouse->buttons[i].pressed = false;
		mouse->buttons[i].released = false;
		mouse->buttons[i].pos.x = 0;
		mouse->buttons[i].pos.y = 0;
		i++;
	}
	mouse->delta.x = 0.0f;
	mouse->delta.y = 0.0f;
	mlx_mouse_hide(mlx_ptr, win_ptr);
	mlx_mouse_move(mlx_ptr, win_ptr, WIN_WIDTH >> 1, WIN_HEIGHT >> 1);
}
