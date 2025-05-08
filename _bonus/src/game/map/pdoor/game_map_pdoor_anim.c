/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_pdoor_anim.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:41:24 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 11:49:30 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_pdoor_anim(t_emap *elem)
{
	if (elem->type != PDOOR || elem->collision == BLOCK_RAY
		|| elem->itex >= MAP_MAX_TEXTURE_ANIM)
		return ;
	elem->fcount++;
	if (elem->fcount >= MAP_MAX_FRAMECOUNT)
	{
		elem->fcount = 0;
		elem->itex++;
		if (elem->itex >= MAP_MAX_TEXTURE_ANIM)
		{
			elem->collision = BLOCK_NONE;
			elem->itex = MAP_MAX_TEXTURE_ANIM - 1;
		}
	}
}
