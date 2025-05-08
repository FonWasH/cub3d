/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_pdoor_open.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:48:34 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 04:47:26 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_pdoor(t_data *d, t_emap *elem)
{
	if (elem->type == PDOOR && elem->collision == BLOCK_RAY)
	{
		mla_start_sound(d->engine.audio.sounds[A_DOOR]);
		elem->collision = BLOCK_ENEMY;
	}
}
