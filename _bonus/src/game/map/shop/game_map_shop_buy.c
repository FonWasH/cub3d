/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_shop_buy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 03:35:20 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 04:49:36 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	buy_ammo(t_data *d, t_emap *elem, t_player *player)
{
	if (player->money < MAP_AMMO_PRICE)
	{
		mla_start_sound(d->engine.audio.sounds[A_FAIL]);
		elem->itex = 2;
		return ;
	}
	mla_start_sound(d->engine.audio.sounds[A_AMMO]);
	player->money -= MAP_AMMO_PRICE;
	player->weapon.ammo += PLAYER_MAX_AMMO >> 1;
	if (player->weapon.ammo > PLAYER_MAX_AMMO)
		player->weapon.ammo = PLAYER_MAX_AMMO;
	elem->itex = 1;
}

static void	buy_medkit(t_data *d, t_emap *elem, t_player *player)
{
	if (player->money < MAP_MEDKIT_PRICE)
	{
		mla_start_sound(d->engine.audio.sounds[A_FAIL]);
		elem->itex = 5;
		return ;
	}
	mla_start_sound(d->engine.audio.sounds[A_MEDKIT]);
	player->money -= MAP_MEDKIT_PRICE;
	player->health += PLAYER_MAX_HEALTH;
	if (player->health > PLAYER_MAX_HEALTH)
		player->health = PLAYER_MAX_HEALTH;
	elem->itex = 4;
}

void	buy_shop(t_data *d, t_emap *elem, t_player *player)
{
	if (elem->type != SHOP)
		return ;
	if (elem->itex == AMMO)
		buy_ammo(d, elem, player);
	else if (elem->itex == MEDKIT)
		buy_medkit(d, elem, player);
}
