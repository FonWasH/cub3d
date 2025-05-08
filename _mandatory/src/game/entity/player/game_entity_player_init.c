/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entity_player_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:16:52 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 18:18:51 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player_cam(t_pcam *cam)
{
	cam->dir.x = 0.0f;
	cam->dir.y = 0.0f;
	cam->plane.x = 0.0f;
	cam->plane.y = 0.0f;
	cam->zoom = PLAYER_ZOOM;
	cam->rzoom = PLAYER_ZOOM;
	cam->pitch = 0.0f;
	cam->poffset = 0;
	cam->rot.cos.x = 0.0f;
	cam->rot.cos.y = 0.0f;
	cam->rot.sin.x = 0.0f;
	cam->rot.sin.y = 0.0f;
}

static void	init_player_state(t_player *player)
{
	player->state.aim = false;
	player->state.ground = true;
	player->state.jump = false;
	player->state.crouch = false;
}

static void	init_player_spawn(t_player *player, char dir, t_vec2 pos)
{
	player->pos.x = (float)pos.x + 0.5f;
	player->pos.y = (float)pos.y + 0.5f;
	player->cam.dir.x = 0.0f
		+ ((dir == 'N') * -1.0f) + ((dir == 'S') * 1.0f);
	player->cam.plane.y = 0.0f
		+ ((dir == 'N') * PLAYER_PLANE) + ((dir == 'S') * -PLAYER_PLANE);
	player->cam.dir.y = 0.0f
		+ ((dir == 'W') * -1.0f) + ((dir == 'E') * 1.0f);
	player->cam.plane.x = 0.0f
		+ ((dir == 'W') * -PLAYER_PLANE) + ((dir == 'E') * PLAYER_PLANE);
}

void	init_player(t_player *player, t_spwn spawn)
{
	player->pos.x = 0.0f;
	player->pos.y = 0.0f;
	player->speed = PLAYER_MOVE_SPEED;
	player->height = 0.0f;
	player->velocity = 0.0f;
	init_player_cam(&player->cam);
	init_player_state(player);
	init_player_spawn(player, spawn.dir, spawn.pos);
}
