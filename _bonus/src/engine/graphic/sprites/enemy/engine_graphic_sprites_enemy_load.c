/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_enemy_load.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:27:46 by juperez           #+#    #+#             */
/*   Updated: 2025/05/02 19:33:05 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "resources_sprites_enemy.h"

static void	load_enemy_anims_oriented(t_data *d, t_anims *anims,
	const char *paths[][ENEMY_MAX_DIRS], int frames)
{
	int	frame;
	int	dir;

	anims->oriented = true;
	anims->frames = frames;
	frame = 0;
	while (frame < frames)
	{
		dir = 0;
		while (dir < ENEMY_MAX_DIRS)
		{
			if (d->load.error)
				return ;
			anims->img[frame][dir] = open_img(d->mlx,
					(char *)paths[frame][dir]);
			if (!anims->img[frame][dir].ptr)
			{
				d->load.error = true;
				return (put_error(ERROR_IMG, (char *)paths[frame][dir]));
			}
			d->load.esprites_count++;
			dir++;
		}
		frame++;
	}
}

static void	load_sprites_enemy_oriented(t_data *d, t_esprites *enemy)
{
	const char	*idle_paths[][ENEMY_MAX_DIRS] = {
	{EI1A1, EI1A2, EI1A3, EI1A4, EI1A5, EI1A6, EI1A7, EI1A8},
	{EI1B1, EI1B2, EI1B3, EI1B4, EI1B5, EI1B6, EI1B7, EI1B8},
	{EI1C1, EI1C2, EI1C3, EI1C4, EI1C5, EI1C6, EI1C7, EI1C8}};
	const char	*walk_paths[][ENEMY_MAX_DIRS] = {
	{EW1A1, EW1A2, EW1A3, EW1A4, EW1A5, EW1A6, EW1A7, EW1A8},
	{EW1B1, EW1B2, EW1B3, EW1B4, EW1B5, EW1B6, EW1B7, EW1B8},
	{EW1C1, EW1C2, EW1C3, EW1C4, EW1C5, EW1C6, EW1C7, EW1C8},
	{EW1D1, EW1D2, EW1D3, EW1D4, EW1D5, EW1D6, EW1D7, EW1D8}};
	const char	*attack_1_paths[][ENEMY_MAX_DIRS] = {
	{EA1A1, EA1A2, EA1A3, EA1A4, EA1A5, EA1A6, EA1A7, EA1A8},
	{EA1B1, EA1B2, EA1B3, EA1B4, EA1B5, EA1B6, EA1B7, EA1B8},
	{EA1C1, EA1C2, EA1C3, EA1C4, EA1C5, EA1C6, EA1C7, EA1C8},
	{EA1D1, EA1D2, EA1D3, EA1D4, EA1D5, EA1D6, EA1D7, EA1D8}};
	const char	*attack_2_paths[][ENEMY_MAX_DIRS] = {
	{EA2A1, EA2A2, EA2A3, EA2A4, EA2A5, EA2A6, EA2A7, EA2A8},
	{EA2B1, EA2B2, EA2B3, EA2B4, EA2B5, EA2B6, EA2B7, EA2B8},
	{EA2C1, EA2C2, EA2C3, EA2C4, EA2C5, EA2C6, EA2C7, EA2C8},
	{EA2D1, EA2D2, EA2D3, EA2D4, EA2D5, EA2D6, EA2D7, EA2D8}};

	load_enemy_anims_oriented(d, &enemy->anims[IDLE], idle_paths, 3);
	load_enemy_anims_oriented(d, &enemy->anims[WALK], walk_paths, 4);
	load_enemy_anims_oriented(d, &enemy->anims[ATTACK_1], attack_1_paths, 4);
	load_enemy_anims_oriented(d, &enemy->anims[ATTACK_2], attack_2_paths, 4);
}

static void	load_enemy_anims_default(t_data *d, t_anims *anims,
	const char *paths[], int frames)
{
	int	frame;

	anims->oriented = false;
	anims->frames = frames;
	frame = 0;
	while (frame < frames)
	{
		if (d->load.error)
			return ;
		anims->img[frame][0] = open_img(d->mlx, (char *)paths[frame]);
		if (!anims->img[frame][0].ptr)
		{
			d->load.error = true;
			return (put_error(ERROR_IMG, (char *)paths[frame]));
		}
		d->load.esprites_count++;
		frame++;
	}
}

static void	load_sprites_enemy_default(t_data *d, t_esprites *enemy)
{
	const char	*die_1_paths[] = {ED1A1, ED1B1, ED1C1, ED1D1, ED1E1, ED1F1};
	const char	*die_2_paths[] = {ED2A1, ED2B1, ED2C1, ED2D1, ED2E1, ED2F1};

	load_enemy_anims_default(d, &enemy->anims[DIE_1], die_1_paths, 6);
	load_enemy_anims_default(d, &enemy->anims[DIE_2], die_2_paths, 6);
}

void	*load_sprites_enemy(void *arg)
{
	t_task_arg	*task;
	t_data		*d;
	t_esprites	*enemy;

	task = (t_task_arg *)arg;
	d = task->d;
	enemy = &d->engine.graphic.sprites.enemy;
	load_sprites_enemy_oriented(d, enemy);
	load_sprites_enemy_default(d, enemy);
	d->load.esprites_done = true;
	return (free(task), NULL);
}
