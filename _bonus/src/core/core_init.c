/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 07:01:44 by juperez           #+#    #+#             */
/*   Updated: 2025/05/06 12:41:43 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_win_size(t_data *d, int width, int height)
{
	d->win.size.x = width;
	d->win.size.y = height;
	d->win.half_w = width >> 1;
	d->win.half_h = height >> 1;
}

static void	init_time(t_data *d)
{
	d->time.current = get_time();
	d->time.old = 0.0f;
	d->time.delta = 0.0f;
}

static void	init_load(t_data *d)
{
	d->load.error = false;
	d->load.loaded = false;
	d->load.loading = false;
	d->load.audio_done = false;
	d->load.textures_done = false;
	d->load.esprites_done = false;
	d->load.hsprites_done = false;
	d->load.psprites_done = false;
	d->load.audio_count = 0;
	d->load.textures_count = 0;
	d->load.esprites_count = 0;
	d->load.hsprites_count = 0;
	d->load.psprites_count = 0;
}

static void	init_ptr(t_data *d)
{
	d->mlx = NULL;
	d->win.ptr = NULL;
	d->engine.graphic.frame.ptr = NULL;
	d->engine.graphic.frame.data = NULL;
	d->engine.graphic.zbuffer = NULL;
	d->engine.threads.initialized = false;
	d->game.entities.enemies.list = NULL;
	init_screen(&d->game.ui.screen);
	init_audio(&d->engine.audio);
	init_sprites(&d->engine.graphic.sprites);
}

void	init_core(t_data *d)
{
	XInitThreads();
	init_ptr(d);
	init_map(d, &d->game.map);
	d->mlx = mlx_init();
	if (!d->mlx)
		error(d, ERROR_MLX, NULL);
	d->win.ptr = mlx_new_window(d->mlx, WIN_WIDTH, WIN_HEIGHT, NAME);
	if (!d->win.ptr)
		error(d, ERROR_WIN, NULL);
	init_win_size(d, WIN_WIDTH, WIN_HEIGHT);
	init_game(d);
	init_engine(d);
	init_time(d);
	init_load(d);
	spawn_enemies(d, &d->game.entities.enemies.list);
}
