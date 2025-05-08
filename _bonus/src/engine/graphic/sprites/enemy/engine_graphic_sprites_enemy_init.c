/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_enemy_init.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:26:57 by juperez           #+#    #+#             */
/*   Updated: 2025/04/24 14:01:45 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprites_enemy(t_esprites *enemy)
{
	int	anim;
	int	frame;
	int	dir;

	anim = 0;
	while (anim < ENEMY_MAX_ANIMS)
	{
		enemy->anims[anim].frames = 0;
		enemy->anims[anim].oriented = false;
		frame = 0;
		while (frame < ENEMY_MAX_FRAMES)
		{
			dir = 0;
			while (dir < ENEMY_MAX_DIRS)
			{
				enemy->anims[anim].img[frame][dir].ptr = NULL;
				enemy->anims[anim].img[frame][dir].data = NULL;
				dir++;
			}
			frame++;
		}
		anim++;
	}
}
