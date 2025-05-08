/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_screen_load.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:17:35 by juperez           #+#    #+#             */
/*   Updated: 2025/05/02 16:09:33 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_screen(t_data *d)
{
	d->game.ui.screen.complete = open_img(d->mlx, SCREEN_COMPLETE);
	if (!d->game.ui.screen.complete.ptr)
		error(d, ERROR_IMG, SCREEN_COMPLETE);
	d->game.ui.screen.gameover = open_img(d->mlx, SCREEN_GAMEOVER);
	if (!d->game.ui.screen.gameover.ptr)
		error(d, ERROR_IMG, SCREEN_GAMEOVER);
	d->game.ui.screen.loading = open_img(d->mlx, SCREEN_LOADING);
	if (!d->game.ui.screen.loading.ptr)
		error(d, ERROR_IMG, SCREEN_LOADING);
	d->game.ui.screen.pause = open_img(d->mlx, SCREEN_MENU);
	if (!d->game.ui.screen.pause.ptr)
		error(d, ERROR_IMG, SCREEN_MENU);
}
