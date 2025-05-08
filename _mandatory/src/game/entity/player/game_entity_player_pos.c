/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entity_player_pos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:54:24 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:40:11 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_pos(t_player *player, t_vecf2 pos, t_map *map)
{
	if (pos.x >= 0.0f && pos.x < (float)map->size.x
		&& (map->elem[(int)pos.x][(int)player->pos.y] == FLOOR
		|| map->elem[(int)pos.x][(int)player->pos.y] == SPAWN))
		player->pos.x = pos.x;
	if (pos.y >= 0.0f && pos.y < (float)map->size.y
		&& (map->elem[(int)player->pos.x][(int)pos.y] == FLOOR
		|| map->elem[(int)player->pos.x][(int)pos.y] == SPAWN))
		player->pos.y = pos.y;
}
