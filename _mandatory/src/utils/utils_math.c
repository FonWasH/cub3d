/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:17:26 by juperez           #+#    #+#             */
/*   Updated: 2025/04/04 15:41:34 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	dot(t_vecf2 a, t_vecf2 b)
{
	return (a.x * b.x + a.y * b.y);
}

float	mag(t_vecf2 a)
{
	return (sqrtf(dot(a, a)));
}

float	rmag(t_vecf2 a)
{
	return (1.0f / mag(a));
}
