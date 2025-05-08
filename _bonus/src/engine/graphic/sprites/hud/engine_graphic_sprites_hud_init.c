/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_hud_init.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:18:48 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 19:39:45 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprites_hud(t_hsprites *hud)
{
	int	elem;
	int	img;

	elem = 0;
	while (elem < HUD_MAX_ELEMS)
	{
		hud->elems[elem].count = 0;
		img = 0;
		while (img < HUD_MAX_IMAGES)
		{
			hud->elems[elem].imgs[img].ptr = NULL;
			hud->elems[elem].imgs[img].data = NULL;
			img++;
		}
		elem++;
	}
}
