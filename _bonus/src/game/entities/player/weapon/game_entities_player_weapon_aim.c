/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_player_weapon_aim.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 23:28:34 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 05:37:36 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	weapon_aim(t_data *d, t_player *player,
	t_weapon *weapon, t_panims *anims)
{
	if (weapon->state == P_IDLE && weapon->aim)
	{
		mla_start_sound(d->engine.audio.sounds[A_AIM_IN]);
		player->weapon.state = P_AIMING;
	}
	else if (weapon->state == P_AIMING)
	{
		player->cam.zoom = PLAYER_ZOOM_FACTOR;
		player->cam.rzoom = PLAYER_RZOOM_FACTOR;
		player->cam.sensitivity = MOUSE_AIM_SENSITIVITY;
		weapon->state = P_IDLE_AIM;
	}
	else if (weapon->state == P_IDLE_AIM && !weapon->aim)
	{
		mla_start_sound(d->engine.audio.sounds[A_AIM_OUT]);
		player->cam.zoom = PLAYER_ZOOM;
		player->cam.rzoom = PLAYER_ZOOM;
		player->cam.sensitivity = MOUSE_SENSITIVITY;
		weapon->state = P_AIMING;
		weapon->lower = true;
		weapon->iframe = anims[weapon->state].frames - 1;
	}
}

void	player_aim(t_player *player)
{
	player->weapon.aim = true;
}

void	player_unaim(t_player *player)
{
	player->weapon.aim = false;
}
