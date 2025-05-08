/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:21:25 by juperez           #+#    #+#             */
/*   Updated: 2025/05/04 04:57:06 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_ui(t_data *d)
{
	if (d->game.entities.player.state.dead)
	{
		itoi(&d->game.ui.screen.gameover, &d->engine.graphic.frame);
		return ;
	}
	if (d->game.entities.player.state.complete)
	{
		itoi(&d->game.ui.screen.complete, &d->engine.graphic.frame);
		return ;
	}
	if (d->game.pause)
	{
		itoi(&d->game.ui.screen.pause, &d->engine.graphic.frame);
		return ;
	}
	draw_minimap(d);
}
