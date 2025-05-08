/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input_key_camera.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:23:51 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 18:19:35 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cam_pitch(t_key *key, t_pcam *cam, float speed, int height)
{
	float			pitch;

	if (key[KEY_UP].pressed)
	{
		pitch = cam->pitch + speed;
		if (pitch > PLAYER_MAX_PITCH)
			pitch = PLAYER_MAX_PITCH;
		cam->pitch = pitch;
		cam->poffset = (int)(pitch * height);
	}
	if (key[KEY_DOWN].pressed)
	{
		pitch = cam->pitch - speed;
		if (pitch < -PLAYER_MAX_PITCH)
			pitch = -PLAYER_MAX_PITCH;
		cam->pitch = pitch;
		cam->poffset = (int)(pitch * height);
	}
}

static void	cam_yaw(t_key *key, t_pcam *cam)
{
	t_vecf2			dir;
	t_vecf2			plane;

	if (key[KEY_LEFT].pressed)
	{
		dir.x = cam->dir.x * cam->rot.cos.x - cam->dir.y * cam->rot.sin.x;
		dir.y = cam->dir.x * cam->rot.sin.x + cam->dir.y * cam->rot.cos.x;
		plane.x = cam->plane.x * cam->rot.cos.x - cam->plane.y * cam->rot.sin.x;
		plane.y = cam->plane.x * cam->rot.sin.x + cam->plane.y * cam->rot.cos.x;
		cam->dir = dir;
		cam->plane = plane;
	}
	if (key[KEY_RIGHT].pressed)
	{
		dir.x = cam->dir.x * cam->rot.cos.y - cam->dir.y * cam->rot.sin.y;
		dir.y = cam->dir.x * cam->rot.sin.y + cam->dir.y * cam->rot.cos.y;
		plane.x = cam->plane.x * cam->rot.cos.y - cam->plane.y * cam->rot.sin.y;
		plane.y = cam->plane.x * cam->rot.sin.y + cam->plane.y * cam->rot.cos.y;
		cam->dir = dir;
		cam->plane = plane;
	}
}

static void	cam_zoom(t_key *key, t_player *player)
{
	if (key[KEY_E].pressed && !player->state.aim)
	{
		player->cam.zoom = PLAYER_ZOOM_FACTOR;
		player->cam.rzoom = PLAYER_RZOOM_FACTOR;
		player->state.aim = true;
	}
	if (key[KEY_E].released && player->state.aim)
	{
		player->cam.zoom = PLAYER_ZOOM;
		player->cam.rzoom = PLAYER_ZOOM;
		player->state.aim = false;
		key[KEY_E].released = false;
	}
}

void	loop_key_camera(t_game *game, float delta_time, int height)
{
	float	speed;

	speed = delta_time * PLAYER_ROTATION_SPEED;
	if (game->input.key[KEY_UP].pressed || game->input.key[KEY_DOWN].pressed)
		cam_pitch(game->input.key, &game->entity.player.cam, speed, height);
	if (game->input.key[KEY_LEFT].pressed || game->input.key[KEY_RIGHT].pressed)
	{
		game->entity.player.cam.rot.cos.x = cosf(speed);
		game->entity.player.cam.rot.cos.y = cosf(-speed);
		game->entity.player.cam.rot.sin.x = sinf(speed);
		game->entity.player.cam.rot.sin.y = sinf(-speed);
		cam_yaw(game->input.key, &game->entity.player.cam);
	}
	cam_zoom(game->input.key, &game->entity.player);
}
