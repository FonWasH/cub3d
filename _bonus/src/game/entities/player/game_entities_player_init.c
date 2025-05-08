/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_player_init.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:16:52 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 05:35:52 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_cam(t_pcam *cam)
{
	cam->dir.x = 1.0f;
	cam->dir.y = 0.0f;
	cam->plane.x = 0.0f;
	cam->plane.y = -PLAYER_PLANE;
	cam->zoom = PLAYER_ZOOM;
	cam->rzoom = PLAYER_ZOOM;
	cam->pitch = 0.0f;
	cam->p_offset = 0;
	cam->sensitivity = MOUSE_SENSITIVITY;
}

static void	init_player_state(t_player *player)
{
	player->state.move = false;
	player->state.ground = true;
	player->state.jump = false;
	player->state.crouch = false;
	player->state.dead = false;
	player->state.sprint = false;
	player->state.damage = false;
	player->state.complete = false;
}

static void	init_player_weapon(t_weapon *weapon)
{
	weapon->state = P_IDLE;
	weapon->clip = PLAYER_MAX_CLIP;
	weapon->ammo = PLAYER_MAX_AMMO >> 1;
	weapon->frame_count = 0.0f;
	weapon->iframe = 0;
	weapon->reload = false;
	weapon->lower = false;
	weapon->pump = false;
	weapon->aim = false;
}

void	init_player(t_player *player)
{
	player->pos.x = PLAYER_SPAWN_POS_X;
	player->pos.y = PLAYER_SPAWN_POS_Y;
	player->pos.z = 0.0f;
	player->speed = PLAYER_MOVE_SPEED;
	player->velocity = 0.0f;
	player->health = PLAYER_MAX_HEALTH;
	player->stamina = PLAYER_MAX_STAMINA;
	player->money = 0;
	player->kills = 0;
	player->frame_count = 0;
	player->complete_count = 0;
	init_player_cam(&player->cam);
	init_player_state(player);
	init_player_weapon(&player->weapon);
}
