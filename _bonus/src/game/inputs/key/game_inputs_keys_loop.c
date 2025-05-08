/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs_keys_loop.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:31:37 by juperez           #+#    #+#             */
/*   Updated: 2025/05/04 05:03:15 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_keys(t_data *d)
{
	loop_keys_menu(d);
	if (d->game.pause || d->game.entities.player.state.dead
		|| d->game.entities.player.state.complete)
		return ;
	loop_keys_camera(&d->game, d->time.delta, d->win.size.y);
	loop_keys_player(d, &d->game, d->time.delta);
}
