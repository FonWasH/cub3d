/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_fog_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:35:08 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 08:24:04 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_fog(t_fog *fog)
{
	int		i;
	float	distance;
	float	fog_factor;

	fog->intensity = FOG_INTENSITY;
	fog->rdistance = 1.0f / FOG_MAX_DISTANCE;
	i = 0;
	while (i < FOG_LUT_SIZE)
	{
		distance = (float)i / (FOG_LUT_SIZE - 1) * FOG_MAX_DISTANCE;
		fog_factor = 1.0f / (1.0f + distance * distance * fog->intensity);
		if (fog_factor > 1.0f)
			fog_factor = 1.0f;
		if (fog_factor < 0.0f)
			fog_factor = 0.0f;
		fog->lut[i] = (uint8_t)(fog_factor * FOG_MAX_COLOR);
		i++;
	}
}
