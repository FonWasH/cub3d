/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_fog_apply.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 03:44:01 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 22:22:06 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	apply_fog(t_fog *fog, uint32_t *color, float distance)
{
	int		i;
	uint8_t	fog_factor;
	t_color	c;

	i = (int)((distance * fog->rdistance) * (FOG_LUT_SIZE - 1));
	if (i >= FOG_LUT_SIZE)
		i = FOG_LUT_SIZE - 1;
	if (i < 0)
		i = 0;
	fog_factor = fog->lut[i];
	c = get_color(*color);
	c.r = (c.r * fog_factor) >> BYTE;
	c.g = (c.g * fog_factor) >> BYTE;
	c.b = (c.b * fog_factor) >> BYTE;
	*color = set_color(c);
}
