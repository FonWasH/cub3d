/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:21:10 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 20:12:40 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_SPRITES_H
# define ENGINE_GRAPHIC_SPRITES_H

# include "engine_graphic_sprites_enemy.h"
# include "engine_graphic_sprites_hud.h"
# include "engine_graphic_sprites_player.h"

typedef struct s_sprites
{
	t_esprites	enemy;
	t_psprites	player;
	t_hsprites	hud;
}				t_sprites;

void	init_sprites(t_sprites *sprites);
void	free_sprites(t_sprites *sprites, void *mlx_ptr);

#endif
