/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_init.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:37:03 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 20:12:49 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprites(t_sprites *sprites)
{
	init_sprites_enemy(&sprites->enemy);
	init_sprites_hud(&sprites->hud);
	init_sprites_player(&sprites->player);
}
