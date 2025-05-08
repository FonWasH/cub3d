/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs_mouse_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:22:47 by juperez           #+#    #+#             */
/*   Updated: 2025/05/02 23:40:11 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_attack(t_data *d, t_mouse *mouse)
{
	if (mouse->buttons[BTN_LEFT].pressed)
	{
		player_fire(d);
		mouse->buttons[BTN_LEFT].released = false;
	}
}

void	loop_mouse_player(t_data *d, t_game *game)
{
	player_attack(d, &game->inputs.mouse);
}
