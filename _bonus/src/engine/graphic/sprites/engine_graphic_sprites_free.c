/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_free.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:28:49 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 20:12:57 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_sprites(t_sprites *sprites, void *mlx_ptr)
{
	free_sprites_enemy(&sprites->enemy, mlx_ptr);
	free_sprites_hud(&sprites->hud, mlx_ptr);
	free_sprites_player(&sprites->player, mlx_ptr);
}
