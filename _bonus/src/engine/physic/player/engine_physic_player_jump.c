/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_physic_player_jump.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 02:30:36 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 04:17:13 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	physic_jump(t_data *d, t_player *player, float delta_time)
{
	if (player->state.jump)
	{
		player->velocity -= GRAVITY * delta_time;
		player->pos.z += player->velocity * delta_time;
		if (player->pos.z >= PLAYER_JUMP_MAX_HEIGHT)
		{
			player->pos.z = PLAYER_JUMP_MAX_HEIGHT;
			player->velocity = 0.0f;
		}
		if (player->pos.z <= 0.0f)
		{
			player->pos.z = 0.0f;
			player->velocity = 0.0f;
			player->state.jump = false;
			player->state.ground = true;
			mla_start_sound(d->engine.audio.sounds[A_WALK]);
			mla_start_sound(d->engine.audio.sounds[A_JUMP_OUT]);
		}
	}
}
