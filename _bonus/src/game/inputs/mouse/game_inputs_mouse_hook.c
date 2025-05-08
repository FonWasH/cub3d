/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs_mouse_hook.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:12:36 by juperez           #+#    #+#             */
/*   Updated: 2025/05/02 13:59:00 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hook_btn_press(int button, int x, int y, void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (button > 0 && button < MOUSE_BUTTON_NB)
	{
		d->game.inputs.mouse.buttons[button].pressed = true;
		d->game.inputs.mouse.buttons[button].released = false;
		d->game.inputs.mouse.buttons[button].pos.x = x;
		d->game.inputs.mouse.buttons[button].pos.y = y;
	}
	return (0);
}

int	hook_btn_release(int button, int x, int y, void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (button > 0 && button < MOUSE_BUTTON_NB)
	{
		d->game.inputs.mouse.buttons[button].pressed = false;
		d->game.inputs.mouse.buttons[button].released = true;
		d->game.inputs.mouse.buttons[button].pos.x = x;
		d->game.inputs.mouse.buttons[button].pos.y = y;
	}
	return (0);
}

int	hook_motion(int x, int y, void *data)
{
	t_data	*d;
	t_vec2	delta;

	d = (t_data *)data;
	if (x == d->win.half_w && y == d->win.half_h)
		return (0);
	delta.x = x - d->win.half_w;
	delta.y = y - d->win.half_h;
	d->game.inputs.mouse.delta.x += delta.x;
	d->game.inputs.mouse.delta.y += delta.y;
	if (!d->game.pause && (delta.x != 0 || delta.y != 0))
		mlx_mouse_move(d->mlx, d->win.ptr, d->win.half_w, d->win.half_h);
	return (0);
}
