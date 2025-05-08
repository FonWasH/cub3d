/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_hud.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:19:34 by juperez           #+#    #+#             */
/*   Updated: 2025/05/04 00:18:07 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_SPRITES_HUD_H
# define ENGINE_GRAPHIC_SPRITES_HUD_H

# define HUD_MAX_ELEMS	4
# define HUD_MAX_IMAGES	10

typedef struct t_helem
{
	int			count;
	t_image		imgs[HUD_MAX_IMAGES];
}				t_helem;

typedef struct s_hsprites
{
	t_helem		elems[HUD_MAX_ELEMS];
}				t_hsprites;

void	init_sprites_hud(t_hsprites *hud);
void	free_sprites_hud(t_hsprites *hud, void *mlx_ptr);
void	*load_sprites_hud(void *arg);
void	draw_sprite_hud(t_data *d, t_player *player);

#endif
