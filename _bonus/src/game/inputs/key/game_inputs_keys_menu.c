/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs_keys_menu.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:07:36 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 04:07:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_keys_menu(t_data *d)
{
	if (d->game.inputs.keys[KEY_ESCAP].released)
		exit_core(d);
	if (d->game.entities.player.state.dead
		|| d->game.entities.player.state.complete)
		return ;
	if (d->game.inputs.keys[KEY_ENTER].released)
	{
		d->game.inputs.keys[KEY_ENTER].released = false;
		d->game.pause = !d->game.pause;
		if (d->game.pause)
		{
			mla_stop_sound(d->engine.audio.sounds[A_MUSIC]);
			mla_stop_sound(d->engine.audio.sounds[A_AMBIENT]);
			mlx_mouse_show(d->mlx, d->win.ptr);
		}
		else
		{
			mla_start_sound(d->engine.audio.sounds[A_MUSIC]);
			mla_start_sound(d->engine.audio.sounds[A_AMBIENT]);
			mlx_mouse_hide(d->mlx, d->win.ptr);
		}
	}
}
