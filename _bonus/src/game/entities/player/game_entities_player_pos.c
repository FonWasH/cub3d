/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_player_pos.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:54:24 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 04:10:45 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_enemies_collision(t_data *d, t_vecf3 pos)
{
	t_enemy	*enemy;
	t_list	*tmp;

	tmp = d->game.entities.enemies.list;
	while (tmp)
	{
		enemy = tmp->data;
		if ((enemy->state != DIE_1 && enemy->state != DIE_2)
			&& pos.x >= enemy->pos.x - PLAYER_BOX
			&& pos.x <= enemy->pos.x + PLAYER_BOX
			&& pos.y >= enemy->pos.y - PLAYER_BOX
			&& pos.y <= enemy->pos.y + PLAYER_BOX)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	set_player_pos(t_data *d, t_player *player, t_vecf3 pos, t_map *map)
{
	bool	move;

	move = false;
	if (!player->state.crouch && !check_enemies_collision(d, pos))
		return ;
	if (pos.x >= 0.0f && pos.x < (float)MAP_SIZE_X
		&& (map->elem[(int)pos.x][(int)player->pos.y].collision == BLOCK_NONE))
	{
		player->pos.x = pos.x;
		move = true;
	}
	if (pos.y >= 0.0f && pos.y < (float)MAP_SIZE_Y
		&& (map->elem[(int)player->pos.x][(int)pos.y].collision == BLOCK_NONE))
	{
		player->pos.y = pos.y;
		move = true;
	}
	player->state.move = move;
	if (move && !player->state.jump && player->state.ground)
	{
		if (player->state.sprint)
			mla_start_sound(d->engine.audio.sounds[A_SPRINT]);
		else
			mla_start_sound(d->engine.audio.sounds[A_WALK]);
	}
}
