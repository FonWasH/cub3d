/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs_mouse_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 07:23:15 by juperez           #+#    #+#             */
/*   Updated: 2025/05/04 05:03:31 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_mouse(t_data *d)
{
	if (d->game.pause || d->game.entities.player.state.dead
		|| d->game.entities.player.state.complete)
		return ;
	loop_mouse_camera(&d->game, d->time.delta, d->win.size.y);
	loop_mouse_player(d, &d->game);
}
