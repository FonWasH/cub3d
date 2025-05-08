/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_player_free.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:49:47 by juperez           #+#    #+#             */
/*   Updated: 2025/05/02 18:50:54 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_sprites_player(t_psprites *player, void *mlx_ptr)
{
	int	anim;
	int	frame;

	anim = 0;
	while (anim < PLAYER_MAX_ANIMS)
	{
		frame = 0;
		while (frame < PLAYER_MAX_FRAMES)
		{
			if (player->anims[anim].img[frame].ptr)
				mlx_destroy_image(mlx_ptr,
					player->anims[anim].img[frame].ptr);
			frame++;
		}
		anim++;
	}
}
