/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_player_damage.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:45:43 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 04:19:29 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_damage(t_data *d, t_enemy *enemy)
{
	t_player	*player;

	player = &d->game.entities.player;
	if (check_range_player(enemy))
	{
		player->health -= ENEMY_DAMAGE;
		player->state.damage = true;
		mla_start_sound(d->engine.audio.sounds[A_PAIN]);
		if (player->health <= 0)
		{
			player->state.dead = true;
			mla_stop_sound(d->engine.audio.sounds[A_MUSIC]);
			mla_stop_sound(d->engine.audio.sounds[A_AMBIENT]);
		}
	}
}
