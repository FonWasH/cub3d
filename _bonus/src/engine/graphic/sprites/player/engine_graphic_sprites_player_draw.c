/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_player_draw.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:41:43 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 05:57:32 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_weapon_state(t_data *d, t_player *player,
	t_weapon *weapon, t_panims *anims)
{
	weapon->iframe = 0;
	weapon_fire(d, weapon, anims);
	weapon_reload(d, weapon, anims);
	weapon_aim(d, player, weapon, anims);
}

static void	weapon_lower(t_weapon *weapon)
{
	weapon->iframe--;
	if (weapon->iframe <= 0)
	{
		weapon->iframe = 0;
		weapon->lower = false;
		weapon->state = P_IDLE;
		if (weapon->aim && !weapon->reload)
			weapon->state = P_AIMING;
	}
}

static void	complete_fire_aim_sound(t_data *d, t_player *player)
{
	if (player->weapon.state != P_FIRE_AIM)
		return ;
	if (player->weapon.iframe == 4)
		mla_start_sound(d->engine.audio.sounds[A_PUMP]);
	if (player->weapon.iframe == 8)
		mla_start_sound(d->engine.audio.sounds[A_SHELL_OUT]);
}

void	draw_sprite_player(t_data *d, t_player *player)
{
	t_panims	*anims;

	anims = d->engine.graphic.sprites.player.anims;
	player->weapon.frame_count += 1.0f * d->time.delta;
	if (player->weapon.frame_count >= PLAYER_MAX_FRAMECOUNT)
	{
		player->weapon.frame_count = 0.0f;
		if (player->weapon.lower)
			weapon_lower(&player->weapon);
		else
		{
			complete_fire_aim_sound(d, player);
			player->weapon.iframe++;
			if (player->weapon.iframe >= anims[player->weapon.state].frames)
				update_weapon_state(d, player, &player->weapon, anims);
		}
	}
	itoi(&anims[player->weapon.state].img[player->weapon.iframe],
		&d->engine.graphic.frame);
	if (player->weapon.pump)
		player->weapon.state = P_RAISE;
}
