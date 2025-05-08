/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs_mouse_camera.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 07:22:40 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 05:38:14 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cam_pitch(t_mouse *mouse, t_pcam *cam, float speed, int height)
{
	float	pitch;
	float	delta;

	delta = -mouse->delta.y * speed * cam->sensitivity;
	if (delta != 0)
	{
		pitch = cam->pitch + delta;
		if (pitch > PLAYER_MAX_PITCH)
			pitch = PLAYER_MAX_PITCH;
		if (pitch < -PLAYER_MAX_PITCH)
			pitch = -PLAYER_MAX_PITCH;
		cam->pitch = pitch;
		cam->p_offset = (int)(pitch * height);
	}
	mouse->delta.y *= MOUSE_SMOOTH;
	if (fabsf(mouse->delta.y) < 0.1f)
		mouse->delta.y = 0;
}

static void	cam_yaw(t_mouse *mouse, t_pcam *cam, float speed)
{
	t_vecf2	dir;
	t_vecf2	plane;
	float	delta;
	float	dcos;
	float	dsin;

	delta = -mouse->delta.x * speed * cam->sensitivity;
	if (delta != 0)
	{
		dcos = cosf(delta);
		dsin = sinf(delta);
		dir.x = cam->dir.x * dcos - cam->dir.y * dsin;
		dir.y = cam->dir.x * dsin + cam->dir.y * dcos;
		plane.x = cam->plane.x * dcos - cam->plane.y * dsin;
		plane.y = cam->plane.x * dsin + cam->plane.y * dcos;
		cam->dir = dir;
		cam->plane = plane;
	}
	mouse->delta.x *= MOUSE_SMOOTH;
	if (fabsf(mouse->delta.x) < 0.1f)
		mouse->delta.x = 0;
}

static void	cam_zoom(t_mouse *mouse, t_player *player)
{
	if (mouse->buttons[BTN_RIGHT].pressed && !player->weapon.aim)
		player_aim(player);
	if (mouse->buttons[BTN_RIGHT].released && player->weapon.aim)
	{
		player_unaim(player);
		mouse->buttons[BTN_RIGHT].released = false;
	}
}

void	loop_mouse_camera(t_game *game, float delta_time, int height)
{
	float	speed;

	speed = delta_time * PLAYER_ROTATION_SPEED;
	if (game->inputs.mouse.delta.y != 0)
		cam_pitch(&game->inputs.mouse,
			&game->entities.player.cam, speed, height);
	if (game->inputs.mouse.delta.x != 0)
		cam_yaw(&game->inputs.mouse, &game->entities.player.cam, speed);
	cam_zoom(&game->inputs.mouse, &game->entities.player);
}
