/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:48:23 by juperez           #+#    #+#             */
/*   Updated: 2025/05/04 05:00:48 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_map(t_data *d)
{
	t_vec2	i;

	if (d->game.pause || d->game.entities.player.state.dead
		|| d->game.entities.player.state.complete)
		return ;
	i.x = 0;
	while (i.x < MAP_SIZE_X)
	{
		i.y = 0;
		while (i.y < MAP_SIZE_Y)
		{
			update_pdoor_anim(&d->game.map.elem[i.x][i.y]);
			update_shop_anim(&d->game.map.elem[i.x][i.y]);
			i.y++;
		}
		i.x++;
	}
}
