/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:32:25 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 19:11:17 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	heu(t_vec2 a, t_vec2 b)
{
	t_vec2	d;

	d.x = b.x - a.x;
	d.y = b.y - a.y;
	return (mag(d));
}

float	heuf(t_vecf2 a, t_vecf2 b)
{
	t_vecf2	d;

	d.x = b.x - a.x;
	d.y = b.y - a.y;
	return (magf(d));
}
