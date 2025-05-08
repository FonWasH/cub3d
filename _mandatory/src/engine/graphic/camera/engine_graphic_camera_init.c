/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_camera_init.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:36:02 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 08:23:43 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cam(t_cam *cam, int width)
{
	int		i;
	float	calc_cam;

	cam->fhoffset = 0.0f;
	cam->choffset = 0.0f;
	i = 0;
	while (i < width)
	{
		calc_cam = (float)(2.0f * i / width - 1.0f);
		cam->lut[i] = calc_cam;
		i++;
	}
}
