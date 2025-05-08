/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_screen_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:17:32 by juperez           #+#    #+#             */
/*   Updated: 2025/05/02 16:09:24 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_screen(t_screen *screen, void *mlx_ptr)
{
	if (screen->complete.ptr)
		mlx_destroy_image(mlx_ptr, screen->complete.ptr);
	if (screen->gameover.ptr)
		mlx_destroy_image(mlx_ptr, screen->gameover.ptr);
	if (screen->loading.ptr)
		mlx_destroy_image(mlx_ptr, screen->loading.ptr);
	if (screen->pause.ptr)
		mlx_destroy_image(mlx_ptr, screen->pause.ptr);
}
