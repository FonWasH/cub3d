/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_rays_init.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:12:50 by juperez           #+#    #+#             */
/*   Updated: 2025/04/23 04:43:16 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_rays *rays, int width)
{
	int		i;
	float	calc_cam;

	i = 0;
	while (i < width)
	{
		calc_cam = (float)(2.0f * i / width - 1.0f);
		rays->cam[i] = calc_cam;
		rays->lut[i].x = 0.0f;
		rays->lut[i].y = 0.0f;
		i++;
	}
}
