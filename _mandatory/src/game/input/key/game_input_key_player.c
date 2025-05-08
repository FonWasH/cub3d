/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input_key_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:15:54 by juperez           #+#    #+#             */
/*   Updated: 2025/04/10 05:24:48 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_action(t_key *key, t_player *player)
{
	if (key[KEY_SPACE].pressed && player->state.ground && !player->state.jump)
	{
		player->velocity = PLAYER_JUMP_VELOCITY;
		player->state.jump = true;
		player->state.ground = false;
		player->height = 0.0f;
		player->state.crouch = false;
		key[KEY_CTRL].released = false;
	}
	if (key[KEY_CTRL].pressed && player->state.ground && !player->state.jump
		&& !player->state.crouch)
	{
		player->height = PLAYER_CROUCH_HEIGHT;
		player->state.crouch = true;
	}
	if (key[KEY_CTRL].released && player->state.crouch)
	{
		player->height = 0.0f;
		player->state.crouch = false;
		key[KEY_CTRL].released = false;
	}
}

static void	player_move(t_key *key, t_player *player, float speed, t_map *map)
{
	t_vecf2	pos;

	pos = player->pos;
	if (key[KEY_W].pressed)
	{
		pos.x += player->cam.dir.x * speed;
		pos.y += player->cam.dir.y * speed;
	}
	if (key[KEY_S].pressed)
	{
		pos.x -= player->cam.dir.x * speed;
		pos.y -= player->cam.dir.y * speed;
	}
	if (key[KEY_A].pressed)
	{
		pos.x -= player->cam.plane.x * speed;
		pos.y -= player->cam.plane.y * speed;
	}
	if (key[KEY_D].pressed)
	{
		pos.x += player->cam.plane.x * speed;
		pos.y += player->cam.plane.y * speed;
	}
	set_player_pos(player, pos, map);
}

void	loop_key_player(t_game *game, float delta_time)
{
	float	speed;

	speed = delta_time * game->entity.player.speed;
	player_action(game->input.key, &game->entity.player);
	player_move(game->input.key, &game->entity.player, speed, &game->map);
}
