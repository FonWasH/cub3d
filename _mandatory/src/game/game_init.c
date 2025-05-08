/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:16:49 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:43:41 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_data *d, char *path)
{
	if (!init_map(&d->game.map, path, d->mlx))
		error(d, NULL, NULL);
	init_input(&d->game.input);
	init_entity(&d->game.entity, d->game.map.spawn);
	d->game.menu = false;
}
