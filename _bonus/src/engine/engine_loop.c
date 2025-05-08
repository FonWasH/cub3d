/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 04:08:05 by juperez           #+#    #+#             */
/*   Updated: 2025/05/04 04:56:36 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_engine(t_data *d)
{
	if (d->game.pause || d->game.entities.player.state.dead
		|| d->game.entities.player.state.complete)
		return ;
	loop_physic(d);
	loop_graphic(d);
}
