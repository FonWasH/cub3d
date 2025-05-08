/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_effects_hit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:05:04 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 15:21:45 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	apply_hit_effect(t_data *d)
{
	t_vec2	i;
	t_image	*frame;
	t_color	color;

	frame = &d->engine.graphic.frame;
	i.x = 0;
	while (i.x < frame->size.x)
	{
		i.y = 0;
		while (i.y < frame->size.y)
		{
			color = get_color(frame->data[i.y * frame->size.x + i.x]);
			color.r = (uint8_t)fminf(color.r * 1.5f, 255.0f);
			color.g = (uint8_t)(color.g * 0.5f);
			color.b = (uint8_t)(color.b * 0.5f);
			frame->data[i.y * frame->size.x + i.x] = set_color(color);
			i.y++;
		}
		i.x++;
	}
}
