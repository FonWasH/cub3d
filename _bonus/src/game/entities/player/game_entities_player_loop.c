/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_player_loop.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:06:51 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 04:16:32 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	calc_player_velocity(t_data *d, t_player *player)
{
	float	velocity;

	velocity = (PLAYER_JUMP_VELOCITY
			* (!player->state.move * 1.0f)
			+ (player->state.move * (player->speed - player->state.sprint)))
		* (float)(player->stamina > PLAYER_JUMP_COST);
	if (velocity > 0.0f)
	{
		mla_start_sound(d->engine.audio.sounds[A_JUMP_IN]);
		player->stamina -= PLAYER_JUMP_COST;
		if (player->stamina <= 0)
		{
			player->stamina = 0;
			player->speed = PLAYER_MOVE_SPEED;
			player->state.sprint = false;
		}
		player->state.jump = true;
		player->state.ground = false;
	}
	return (velocity);
}

static void	player_hit_effects(t_player *player)
{
	if (player->state.damage)
	{
		player->frame_count++;
		if (player->frame_count >= PLAYER_HIT_FRAME_MAX)
		{
			player->frame_count = 0;
			player->state.damage = false;
		}
	}
}

static void	check_complete(t_data *d, t_player *player)
{
	if (player->kills <= 0)
	{
		player->complete_count++;
		if (player->complete_count >= PLAYER_COMPLETE_COUNT)
		{
			player->state.complete = true;
			mla_stop_sound(d->engine.audio.sounds[A_MUSIC]);
			mla_stop_sound(d->engine.audio.sounds[A_AMBIENT]);
		}
	}
}

void	loop_player(t_data *d, t_player *player)
{
	if (d->game.pause || player->state.dead || player->state.complete)
		return ;
	check_complete(d, player);
	if (player->state.move && player->state.sprint)
		player->stamina -= PLAYER_SPRINT_COST;
	else if (player->state.move && !player->state.sprint)
		player->stamina += PLAYER_STAMINA_REGEN >> 1;
	else if (!player->state.move && !player->state.sprint)
		player->stamina += PLAYER_STAMINA_REGEN;
	if (player->stamina > PLAYER_MAX_STAMINA)
		player->stamina = PLAYER_MAX_STAMINA;
	if (player->stamina <= 0)
	{
		mla_start_sound(d->engine.audio.sounds[A_TIRED]);
		player->stamina = 0;
		player->speed = PLAYER_MOVE_SPEED;
		player->state.sprint = false;
	}
	player_hit_effects(player);
}
