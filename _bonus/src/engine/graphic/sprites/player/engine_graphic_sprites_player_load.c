/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_player_load.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:53:00 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 01:22:27 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "resources_sprites_player.h"

static void	load_player_anims(t_data *d, t_panims *anims,
	const char *paths[], int frames)
{
	int	frame;

	anims->frames = frames;
	frame = 0;
	while (frame < frames)
	{
		if (d->load.error)
			return ;
		anims->img[frame] = open_img(d->mlx, (char *)paths[frame]);
		if (!anims->img[frame].ptr)
		{
			d->load.error = true;
			return (put_error(ERROR_IMG, (char *)paths[frame]));
		}
		d->load.psprites_count++;
		frame++;
	}
}

static void	load_sprites_player_1(t_data *d, t_psprites *player)
{
	const char	*aiming[] = {PA1, PA1};
	const char	*fire[] = {PF1, PF2, PF3, PF4, PF5, PF6};
	const char	*fire_aim[] = {PFA0, PFA1, PFA2, PFA3, PFA4, PFA5, PFA6, PFA7,
		PFA8, PFA9, PFA10, PFA11};
	const char	*idle[] = {PI1};

	load_player_anims(d, &player->anims[P_AIMING], aiming, 1);
	load_player_anims(d, &player->anims[P_FIRE], fire, 6);
	load_player_anims(d, &player->anims[P_FIRE_AIM], fire_aim, 12);
	load_player_anims(d, &player->anims[P_IDLE], idle, 1);
}

static void	load_sprites_player_2(t_data *d, t_psprites *player)
{
	const char	*idle_aim[] = {PIA1};
	const char	*pump[] = {PP1, PP2, PP3, PP4, PP5, PP6, PP7, PP8, PP9,
		PP10, PP11, PP12, PP13, PP14, PP15, PP16, PP17, PP18, PP19, PP20};
	const char	*raise[] = {PR1, PR1, PR3};
	const char	*reload[] = {PRE1, PRE2, PRE3, PRE4, PRE5, PRE6,
		PRE7, PRE8, PRE9};

	load_player_anims(d, &player->anims[P_IDLE_AIM], idle_aim, 1);
	load_player_anims(d, &player->anims[P_PUMP], pump, 20);
	load_player_anims(d, &player->anims[P_RAISE], raise, 3);
	load_player_anims(d, &player->anims[P_RELOAD], reload, 9);
}

void	*load_sprites_player(void *arg)
{
	t_task_arg	*task;
	t_data		*d;
	t_psprites	*player;

	task = (t_task_arg *)arg;
	d = task->d;
	player = &d->engine.graphic.sprites.player;
	load_sprites_player_1(d, player);
	load_sprites_player_2(d, player);
	d->load.psprites_done = true;
	return (free(task), NULL);
}
