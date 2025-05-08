/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_fog.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:18:20 by juperez           #+#    #+#             */
/*   Updated: 2025/04/22 11:19:57 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_FOG_H
# define ENGINE_GRAPHIC_FOG_H

# define FOG_INTENSITY		0.25f
# define FOG_MAX_DISTANCE	32.0f
# define FOG_LUT_SIZE		1024
# define FOG_MAX_COLOR		255.0f

typedef struct s_fog
{
	uint8_t		lut[FOG_LUT_SIZE];
	float		intensity;
	float		rdistance;
}				t_fog;

void	init_fog(t_fog *fog);
void	apply_fog(t_fog *fog, uint32_t *color, float distance);

#endif
