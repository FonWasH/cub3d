/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_shop_anim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 04:21:56 by juperez           #+#    #+#             */
/*   Updated: 2025/05/04 04:40:08 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_shop_anim(t_emap *elem)
{
	if (elem->type != SHOP || elem->itex == AMMO || elem->itex == MEDKIT)
		return ;
	elem->fcount++;
	if (elem->fcount >= SHOP_MAX_FRAMECOUNT)
	{
		elem->fcount = 0;
		if (elem->itex == 5 || elem->itex == 4)
			elem->itex = MEDKIT;
		else if (elem->itex == 1 || elem->itex == 2)
			elem->itex = AMMO;
	}
}
