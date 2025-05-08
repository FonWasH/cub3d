/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_spawn.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 05:06:33 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 00:36:30 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	spawn_enemies(t_data *d, t_list **enemies)
{
	int		count;
	t_vec2	i;

	add_enemy(d, enemies, (t_vecf3){21.5f, 12.5f, 0.0f}, false);
	count = 0;
	i.x = 0;
	while (i.x < MAP_SIZE_X)
	{
		i.y = 0;
		while (i.y < MAP_SIZE_Y)
		{
			if (d->game.map.elem[i.x][i.y].type == FLOOR
				&& !(i.x >= 1 && i.x <= 3 && i.y >= 14 && i.y <= 16)
				&& !(i.x >= 21 && i.x <= 26 && i.y >= 10 && i.y <= 15)
				&& get_rand(1, ENEMY_SPAWN_CHANCE, i.x + i.y) == 1)
			{
				add_enemy(d, enemies, (t_vecf3){(float)i.x + 0.5f,
					(float)i.y + 0.5f, 0.0f}, true);
				count++;
			}
			i.y++;
		}
		i.x++;
	}
	d->game.entities.player.kills = count;
}
