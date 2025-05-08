/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_player.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:47:45 by juperez           #+#    #+#             */
/*   Updated: 2025/05/04 01:09:51 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_SPRITES_PLAYER_H
# define ENGINE_GRAPHIC_SPRITES_PLAYER_H

# define PLAYER_MAX_ANIMS		8
# define PLAYER_MAX_FRAMES		20
# define PLAYER_MAX_FRAMECOUNT	0.035f //0.05f

typedef struct s_panims
{
	int			frames;
	t_image		img[PLAYER_MAX_FRAMES];
}				t_panims;

typedef struct s_psprites
{
	t_panims	anims[PLAYER_MAX_ANIMS];
}				t_psprites;

void	init_sprites_player(t_psprites *player);
void	free_sprites_player(t_psprites *player, void *mlx_ptr);
void	*load_sprites_player(void *arg);
void	draw_sprite_player(t_data *d, t_player *player);

#endif