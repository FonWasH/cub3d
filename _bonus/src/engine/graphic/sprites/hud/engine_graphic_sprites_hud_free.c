/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_hud_free.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:18:46 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 19:39:49 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_sprites_hud(t_hsprites *hud, void *mlx_ptr)
{
	int	elem;
	int	img;

	elem = 0;
	while (elem < HUD_MAX_ELEMS)
	{
		img = 0;
		while (img < HUD_MAX_IMAGES)
		{
			if (hud->elems[elem].imgs[img].ptr)
				mlx_destroy_image(mlx_ptr,
					hud->elems[elem].imgs[img].ptr);
			img++;
		}
		elem++;
	}
}
