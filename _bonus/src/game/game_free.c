/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:55:59 by juperez           #+#    #+#             */
/*   Updated: 2025/05/02 13:32:30 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_data *d)
{
	free_ui(&d->game.ui, d->mlx);
	free_map(&d->game.map, d->mlx);
	free_entities(&d->game.entities);
}
