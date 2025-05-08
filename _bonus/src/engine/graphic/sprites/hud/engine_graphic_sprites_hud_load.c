/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_hud_load.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:18:51 by juperez           #+#    #+#             */
/*   Updated: 2025/05/04 02:36:52 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "resources_sprites_hud.h"

static void	load_hud_images(t_data *d, t_helem *elem,
	const char *paths[], int count)
{
	int	img;

	elem->count = count;
	img = 0;
	while (img < count)
	{
		if (d->load.error)
			return ;
		elem->imgs[img] = open_img(d->mlx, (char *)paths[img]);
		if (!elem->imgs[img].ptr)
		{
			d->load.error = true;
			return (put_error(ERROR_IMG, (char *)paths[img]));
		}
		d->load.hsprites_count++;
		img++;
	}
}

static void	load_hud_sprites(t_data *d, t_hsprites *hud)
{
	const char	*digit_a[] = {DA0, DA1, DA2, DA3, DA4, DA5, DA6, DA7, DA8, DA9};
	const char	*digit_m[] = {DM0, DM1, DM2, DM3, DM4, DM5, DM6, DM7, DM8, DM9};
	const char	*status[] = {ST0, ST1, ST2};
	const char	*ammo[] = {AM0};

	load_hud_images(d, &hud->elems[HUD_DA], digit_a, 10);
	load_hud_images(d, &hud->elems[HUD_DM], digit_m, 10);
	load_hud_images(d, &hud->elems[HUD_STATUS], status, 3);
	load_hud_images(d, &hud->elems[HUD_AMMO], ammo, 1);
}

void	*load_sprites_hud(void *arg)
{
	t_task_arg	*task;
	t_data		*d;
	t_hsprites	*hud;

	task = (t_task_arg *)arg;
	d = task->d;
	hud = &d->engine.graphic.sprites.hud;
	load_hud_sprites(d, hud);
	d->load.hsprites_done = true;
	return (free(task), NULL);
}
