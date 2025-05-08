/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_enemy_free.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:34:08 by juperez           #+#    #+#             */
/*   Updated: 2025/04/24 14:01:42 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_sprites_enemy(t_esprites *enemy, void *mlx_ptr)
{
	int	anim;
	int	frame;
	int	dir;

	anim = 0;
	while (anim < ENEMY_MAX_ANIMS)
	{
		frame = 0;
		while (frame < ENEMY_MAX_FRAMES)
		{
			dir = 0;
			while (dir < ENEMY_MAX_DIRS)
			{
				if (enemy->anims[anim].img[frame][dir].ptr)
					mlx_destroy_image(mlx_ptr,
						enemy->anims[anim].img[frame][dir].ptr);
				dir++;
			}
			frame++;
		}
		anim++;
	}
}
