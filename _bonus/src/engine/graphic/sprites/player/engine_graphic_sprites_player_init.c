/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_player_init.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:44:51 by juperez           #+#    #+#             */
/*   Updated: 2025/05/02 18:47:07 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprites_player(t_psprites *player)
{
	int	anim;
	int	frame;

	anim = 0;
	while (anim < PLAYER_MAX_ANIMS)
	{
		player->anims[anim].frames = 0;
		frame = 0;
		while (frame < PLAYER_MAX_FRAMES)
		{
			player->anims[anim].img[frame].ptr = NULL;
			player->anims[anim].img[frame].data = NULL;
			frame++;
		}
		anim++;
	}
}
