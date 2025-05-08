/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_render_wall_texture.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:29:48 by juperez           #+#    #+#             */
/*   Updated: 2025/04/08 07:33:01 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_itex	wall_tex_index(bool is_side, t_vecf2 ray)
{
	if (!is_side)
	{
		if (ray.x > 0.0f)
			return (SO);
		if (ray.x < 0.0f)
			return (NO);
	}
	else if (is_side)
	{
		if (ray.y > 0.0f)
			return (EA);
		if (ray.y < 0.0f)
			return (WE);
	}
	return (SO);
}
