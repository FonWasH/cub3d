/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_interact.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:27:47 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 04:46:53 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_interact(t_data *d, t_vec2 pos, t_map *map, t_player *player)
{
	t_emap	*elem;

	if (pos.x < 0 || pos.x >= MAP_SIZE_X || pos.y < 0 || pos.y >= MAP_SIZE_Y)
		return ;
	elem = &map->elem[pos.x][pos.y];
	open_pdoor(d, elem);
	buy_shop(d, elem, player);
}
