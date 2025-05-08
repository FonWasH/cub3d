/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_player_weapon_fire.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:17:45 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 05:44:20 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	weapon_fire(t_data *d, t_weapon *weapon, t_panims *anims)
{
	if (weapon->state == P_FIRE)
	{
		weapon->state = P_IDLE;
		if (weapon->clip > 0)
			weapon->pump = true;
	}
	else if (weapon->state == P_FIRE_AIM)
		weapon->state = P_IDLE_AIM;
	else if (weapon->state == P_RAISE && weapon->pump)
	{
		mla_start_sound(d->engine.audio.sounds[A_PUMP]);
		weapon->state = P_PUMP;
		weapon->pump = false;
	}
	else if (weapon->state == P_PUMP)
	{
		mla_start_sound(d->engine.audio.sounds[A_SHELL_OUT]);
		weapon->state = P_RAISE;
		weapon->lower = true;
		weapon->iframe = anims[weapon->state].frames - 1;
	}
}

static bool	check_weapon_fire(t_data *d, t_weapon *weapon)
{
	if (weapon->state != P_IDLE && weapon->state != P_IDLE_AIM)
		return (false);
	if (weapon->clip <= 0)
	{
		mla_start_sound(d->engine.audio.sounds[A_DRY_FIRE]);
		return (false);
	}
	else
	{
		mla_start_sound(d->engine.audio.sounds[A_FIRE]);
		weapon->clip--;
		if (weapon->state == P_IDLE)
			weapon->state = P_FIRE;
		else if (weapon->state == P_IDLE_AIM)
			weapon->state = P_FIRE_AIM;
		return (true);
	}
	return (false);
}

static bool	is_targeted(t_data *d, t_enemy *e)
{
	t_vec2	cross_min;
	t_vec2	cross_max;
	t_vec2	start;
	t_vec2	end;
	t_vec2	range;

	range.x = d->win.half_w / PLAYER_FIRE_RADIUS;
	range.y = d->win.half_h / PLAYER_FIRE_RADIUS;
	cross_min.x = d->win.half_w - range.x;
	cross_max.x = d->win.half_w + range.x;
	cross_min.y = d->win.half_h - range.y;
	cross_max.y = d->win.half_h + range.y;
	start.x = -(e->r.w >> 1) + e->r.screen_x;
	end.x = (e->r.w >> 1) + e->r.screen_x;
	start.y = -(e->r.h >> 1) + d->win.half_h + e->r.h_offset;
	end.y = (e->r.h >> 1) + d->win.half_h + e->r.h_offset;
	if ((cross_max.x >= start.x) && (cross_min.x <= end.x)
		&& (cross_max.y >= start.y) && (cross_min.y <= end.y)
		&& e->r.dist <= PLAYER_FIRE_DISTANCE && e->r.tran.y > 0.01f
		&& e->r.tran.y <= d->engine.graphic.zbuffer[
			d->win.half_w][d->win.half_h])
		return (true);
	return (false);
}

static void	shot_enemy(t_data *d, t_enemy *enemy)
{
	enemy->state = get_rand(DIE_1, DIE_2,
			(int)(d->time.current + enemy->id));
	d->game.entities.player.money += PLAYER_REWARD;
	if (d->game.entities.player.money > PLAYER_MAX_MONEY)
		d->game.entities.player.money = PLAYER_MAX_MONEY;
	d->game.entities.player.kills--;
}

void	player_fire(t_data *d)
{
	t_weapon	*weapon;
	t_enemy		*enemy;
	t_list		*tmp;

	weapon = &d->game.entities.player.weapon;
	if (!check_weapon_fire(d, weapon))
		return ;
	tmp = d->game.entities.enemies.list;
	while (tmp)
	{
		enemy = tmp->data;
		if (is_targeted(d, enemy)
			&& enemy->state != DIE_1 && enemy->state != DIE_2)
			shot_enemy(d, enemy);
		tmp = tmp->next;
	}
}
