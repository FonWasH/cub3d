/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_floor_init.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:41:11 by juperez           #+#    #+#             */
/*   Updated: 2025/04/23 04:56:18 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_floor(t_floor *floor)
{
	int	i;

	floor->fz_offset = 0.0f;
	floor->cz_offset = 0.0f;
	floor->dir_rmag = 0.0f;
	i = 0;
	while (i < MAX_WIDTH)
	{
		floor->rays_rmag[i] = 0.0f;
		floor->angle[i] = 0.0f;
		i++;
	}
}
