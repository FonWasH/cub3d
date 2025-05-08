/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:17:26 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 18:32:24 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	dot(t_vec2 a, t_vec2 b)
{
	return (a.x * b.x + a.y * b.y);
}

float	dotf(t_vecf2 a, t_vecf2 b)
{
	return (a.x * b.x + a.y * b.y);
}

float	mag(t_vec2 a)
{
	return (sqrtf(dot(a, a)));
}

float	magf(t_vecf2 a)
{
	return (sqrtf(dotf(a, a)));
}

float	rmagf(t_vecf2 a)
{
	return (1.0f / magf(a));
}
