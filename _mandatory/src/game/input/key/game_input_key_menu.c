/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input_key_menu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:07:36 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:42:26 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_key_menu(t_data *d)
{
	if (d->game.input.key[KEY_ESCAP].released)
		exit_core(d);
	if (d->game.input.key[KEY_ENTER].released)
	{
		d->game.input.key[KEY_ENTER].released = false;
		d->game.menu = !d->game.menu;
	}
}
