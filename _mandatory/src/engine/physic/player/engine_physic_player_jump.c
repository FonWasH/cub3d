/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_physic_player_jump.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 02:30:36 by juperez           #+#    #+#             */
/*   Updated: 2025/04/08 07:50:42 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	physic_jump(t_player *player, float delta_time)
{
	if (player->state.jump)
	{
		player->velocity -= GRAVITY * delta_time;
		player->height += player->velocity * delta_time;
		if (player->height >= PLAYER_JUMP_MAX_HEIGHT)
		{
			player->height = PLAYER_JUMP_MAX_HEIGHT;
			player->velocity = 0.0f;
		}
		if (player->height <= 0.0f)
		{
			player->height = 0.0f;
			player->velocity = 0.0f;
			player->state.jump = false;
			player->state.ground = true;
		}
	}
}
