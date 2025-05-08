/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_screen_loading_draw.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:49:49 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 04:02:47 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_loading_text(t_data *d)
{
	static char	str[] = "Loading...   0%";
	t_vec2		pos;
	int			pourcent;

	pos.x = 10;
	pos.y = d->win.size.y - 10;
	pourcent = (d->load.audio_count + d->load.textures_count
			+ d->load.esprites_count + d->load.hsprites_count
			+ d->load.psprites_count) * 100
		/ (MAX_AUDIO + TEXTURES_COUNT + ESPRITES_COUNT
			+ HSPRITES_COUNT + PSRITES_COUNT);
	if (pourcent >= 100)
		str[11] = pourcent / 100 + '0';
	if (pourcent >= 10)
		str[12] = (pourcent / 10) % 10 + '0';
	if (pourcent >= 1)
		str[13] = pourcent % 10 + '0';
	mlx_string_put(d->mlx, d->win.ptr, pos.x, pos.y, WHITE, str);
}

void	draw_loading_screen(t_data *d)
{
	itoi(&d->game.ui.screen.loading, &d->engine.graphic.frame);
	mlx_put_image_to_window(d->mlx, d->win.ptr,
		d->engine.graphic.frame.ptr, 0, 0);
	print_loading_text(d);
}
