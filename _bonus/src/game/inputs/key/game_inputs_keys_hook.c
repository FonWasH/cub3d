/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs_key_hook.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:02:10 by juperez           #+#    #+#             */
/*   Updated: 2025/04/23 05:06:02 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hook_key_press(int key_code, void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (key_code >= 0 && key_code < KEY_NB)
	{
		if (DEBUG)
			printf("key_code press = %d\n", key_code);
		d->game.inputs.keys[key_code].pressed = true;
		d->game.inputs.keys[key_code].released = false;
	}
	return (0);
}

int	hook_key_release(int key_code, void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (key_code >= 0 && key_code < KEY_NB)
	{
		if (DEBUG)
			printf("key_code release = %d\n", key_code);
		d->game.inputs.keys[key_code].pressed = false;
		d->game.inputs.keys[key_code].released = true;
	}
	return (0);
}
