/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_rays.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:09:51 by juperez           #+#    #+#             */
/*   Updated: 2025/04/23 04:43:25 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_RAYS_H
# define ENGINE_GRAPHIC_RAYS_H

typedef struct s_rays
{
	float		cam[MAX_WIDTH];
	t_vecf2		lut[MAX_WIDTH];
}				t_rays;

void	init_ray(t_rays *rays, int width);
void	*calc_ray(void *arg);

#endif
