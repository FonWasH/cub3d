/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:16:49 by juperez           #+#    #+#             */
/*   Updated: 2025/05/02 13:58:36 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_data *d)
{
	init_inputs(&d->game.inputs, d->mlx, d->win.ptr);
	init_entities(&d->game.entities);
	init_ui(d);
	d->game.pause = false;
}
