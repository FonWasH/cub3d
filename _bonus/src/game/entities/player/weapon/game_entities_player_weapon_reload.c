/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_player_weapon_reload.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:16:44 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 05:36:52 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	manage_reload(t_data *d, t_weapon *weapon, t_panims *anims)
{
	weapon->ammo--;
	weapon->clip++;
	mla_start_sound(d->engine.audio.sounds[A_RELOAD]);
	if (weapon->clip >= PLAYER_MAX_CLIP)
	{
		weapon->clip = PLAYER_MAX_CLIP;
		weapon->state = P_RAISE;
		weapon->lower = true;
		weapon->iframe = anims[weapon->state].frames - 1;
	}
	else if (weapon->ammo >= 1)
		weapon->iframe = 1;
	else
	{
		weapon->state = P_RAISE;
		weapon->lower = true;
		weapon->iframe = anims[weapon->state].frames - 1;
	}
}

void	weapon_reload(t_data *d, t_weapon *weapon, t_panims *anims)
{
	if (weapon->state == P_IDLE && weapon->reload)
		weapon->state = P_RAISE;
	else if (weapon->state == P_RAISE && weapon->reload)
	{
		weapon->state = P_RELOAD;
		weapon->reload = false;
	}
	else if (weapon->state == P_RELOAD)
		manage_reload(d, weapon, anims);
}

void	player_reload(t_player *player, t_weapon *weapon, t_panims *anims)
{
	if (weapon->clip >= PLAYER_MAX_CLIP || weapon->ammo <= 0
		|| (weapon->state != P_IDLE && weapon->state != P_IDLE_AIM))
		return ;
	weapon->reload = true;
	if (weapon->state == P_IDLE_AIM)
	{
		player->cam.zoom = PLAYER_ZOOM;
		player->cam.rzoom = PLAYER_ZOOM;
		player->cam.sensitivity = MOUSE_SENSITIVITY;
		weapon->state = P_AIMING;
		weapon->lower = true;
		weapon->iframe = anims[weapon->state].frames - 1;
	}
	else
		weapon->state = P_RAISE;
}
