/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input_key_loop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:31:37 by juperez           #+#    #+#             */
/*   Updated: 2025/04/10 06:18:34 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_key(t_data *d)
{
	loop_key_menu(d);
	if (!d->game.menu)
	{
		loop_key_camera(&d->game, d->time.delta, d->win.size.y);
		loop_key_player(&d->game, d->time.delta);
	}
}
