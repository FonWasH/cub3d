/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_physic_enemies_render_2.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 06:44:41 by juperez           #+#    #+#             */
/*   Updated: 2025/05/04 05:32:02 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_enemy_frame(t_data *d, t_enemy *enemy, t_anims *anims)
{
	enemy->r.frame_count = 0.0f;
	enemy->r.iframe++;
	if (enemy->r.iframe >= anims[enemy->state].frames)
	{
		if (enemy->state == ATTACK_1 || enemy->state == ATTACK_2)
			set_player_damage(d, enemy);
		if (enemy->state != DIE_1 && enemy->state != DIE_2)
			enemy->r.iframe = 0;
		else
			enemy->r.iframe = anims[enemy->state].frames - 1;
	}
}

static void	update_enemy_frame(t_data *d, t_enemy *enemy, t_anims *anims)
{
	int	rand;

	if (enemy->state == IDLE)
		return ;
	else if (enemy->state == DIE_1 || enemy->state == DIE_2)
		rand = 3;
	else
		rand = get_rand(2, 4, (int)(d->time.current + enemy->id));
	enemy->r.frame_count += (float)rand * d->time.delta;
	if (enemy->r.frame_count >= ENEMY_MAX_FRAMECOUNT)
		handle_enemy_frame(d, enemy, anims);
}

static void	calc_h_offset(t_enemy *enemy, t_player *player, int height)
{
	int	h_offset;
	int	z_offset;
	int	enemy_h;
	int	diff_h;

	h_offset = (int)(player->pos.z * height / enemy->r.tran.y);
	enemy_h = (int)((height / enemy->r.tran.y) * player->cam.rzoom);
	diff_h = enemy_h - enemy->r.h;
	h_offset += diff_h >> 1;
	z_offset = 0;
	if (enemy->pos.z != 0.0f)
		z_offset = (int)((enemy->pos.z * height) / enemy->r.tran.y);
	enemy->r.h_offset = player->cam.p_offset + h_offset - z_offset;
}

void	calc_render_enemy_2(t_data *d, t_enemy *enemy)
{
	t_anims	*anims;
	t_image	sprite;

	anims = d->engine.graphic.sprites.enemy.anims;
	update_enemy_frame(d, enemy, anims);
	sprite = anims[enemy->state].img[enemy->r.iframe][enemy->r.idir];
	enemy->r.h = (int)(((d->win.size.y / enemy->r.tran.y)
				* d->game.entities.player.cam.rzoom) * ENEMY_SCALE);
	enemy->r.w = (int)((float)enemy->r.h * ((float)sprite.size.x
				/ sprite.size.y));
	enemy->r.screen_x = (int)((d->win.half_w) * (1 + enemy->r.tran.x
				/ enemy->r.tran.y));
	calc_h_offset(enemy, &d->game.entities.player, d->win.size.y);
}
