/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs_keys_player.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:15:54 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 04:46:20 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_action_1(t_data *d, t_key *key, t_player *player)
{
	if (key[KEY_SPACE].pressed && player->state.ground
		&& !player->state.jump && !player->state.crouch)
	{
		player->velocity = calc_player_velocity(d, player);
		key[KEY_CTRL].released = false;
	}
	if (key[KEY_CTRL].pressed && player->state.ground && !player->state.jump
		&& !player->state.crouch && !player->state.sprint)
	{
		player->pos.z = PLAYER_CROUCH_HEIGHT;
		player->speed = PLAYER_CROUCH_SPEED;
		player->state.crouch = true;
	}
	if (key[KEY_CTRL].released && player->state.crouch)
	{
		player->pos.z = 0.0f;
		player->speed = PLAYER_MOVE_SPEED;
		player->state.crouch = false;
		key[KEY_CTRL].released = false;
	}
}

static void	player_action_2(t_key *key, t_player *player)
{
	if (key[KEY_SHIFT].pressed && !player->state.sprint
		&& !player->state.crouch && player->stamina)
	{
		player->speed = PLAYER_SPRINT_SPEED;
		player->state.sprint = true;
	}
	if (key[KEY_SHIFT].released && player->state.sprint && player->stamina)
	{
		player->speed = PLAYER_MOVE_SPEED;
		player->state.sprint = false;
		key[KEY_SHIFT].released = false;
	}
}

static void	player_move(t_data *d, t_key *key, t_player *player, float speed)
{
	t_vecf3	pos;

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
	if (pos.x != player->pos.x || pos.y != player->pos.y)
		set_player_pos(d, player, pos, &d->game.map);
}

static void	player_special(t_data *d, t_key *key,
	t_player *player, t_game *game)
{
	t_vec2	pos;

	if (key[KEY_E].pressed)
	{
		pos.x = (int)(player->pos.x + player->cam.dir.x);
		pos.y = (int)(player->pos.y + player->cam.dir.y);
		check_map_interact(d, pos, &game->map, player);
	}
	if (key[KEY_R].pressed)
		player_reload(player, &player->weapon,
			d->engine.graphic.sprites.player.anims);
}

void	loop_keys_player(t_data *d, t_game *game, float delta_time)
{
	float	speed;

	speed = delta_time * game->entities.player.speed;
	player_action_1(d, game->inputs.keys, &game->entities.player);
	player_action_2(game->inputs.keys, &game->entities.player);
	game->entities.player.state.move = false;
	player_move(d, game->inputs.keys, &game->entities.player, speed);
	player_special(d, game->inputs.keys, &game->entities.player, game);
}
