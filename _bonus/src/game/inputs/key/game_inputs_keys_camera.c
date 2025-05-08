/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs_keys_camera.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:23:51 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 10:31:50 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cam_pitch(t_key *keys, t_pcam *cam, float speed, int height)
{
	float	pitch;

	pitch = cam->pitch;
	if (keys[KEY_UP].pressed)
		pitch += speed;
	if (keys[KEY_DOWN].pressed)
		pitch -= speed;
	if (pitch > PLAYER_MAX_PITCH)
		pitch = PLAYER_MAX_PITCH;
	if (pitch < -PLAYER_MAX_PITCH)
		pitch = -PLAYER_MAX_PITCH;
	cam->pitch = pitch;
	cam->p_offset = (int)(pitch * height);
}

static void	cam_yaw(t_key *keys, t_pcam *cam, float speed)
{
	t_vecf2	dir;
	t_vecf2	plane;
	float	dcos;
	float	dsin;

	dcos = 0.0f;
	dsin = 0.0f;
	if (keys[KEY_LEFT].pressed)
	{
		dcos = cosf(speed);
		dsin = sinf(speed);
	}
	if (keys[KEY_RIGHT].pressed)
	{
		dcos = cosf(-speed);
		dsin = sinf(-speed);
	}
	dir.x = cam->dir.x * dcos - cam->dir.y * dsin;
	dir.y = cam->dir.x * dsin + cam->dir.y * dcos;
	plane.x = cam->plane.x * dcos - cam->plane.y * dsin;
	plane.y = cam->plane.x * dsin + cam->plane.y * dcos;
	cam->dir = dir;
	cam->plane = plane;
}

void	loop_keys_camera(t_game *game, float delta_time, int height)
{
	float	speed;

	speed = delta_time * PLAYER_ROTATION_SPEED;
	if (game->inputs.keys[KEY_UP].pressed
		|| game->inputs.keys[KEY_DOWN].pressed)
		cam_pitch(game->inputs.keys, &game->entities.player.cam, speed, height);
	if (game->inputs.keys[KEY_LEFT].pressed
		|| game->inputs.keys[KEY_RIGHT].pressed)
		cam_yaw(game->inputs.keys, &game->entities.player.cam, speed);
}
