/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:36:13 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 05:14:21 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_MATH_H
# define UTILS_MATH_H

typedef struct s_vec2
{
	int		x;
	int		y;
}			t_vec2;

typedef struct s_vecf2
{
	float	x;
	float	y;
}			t_vecf2;

float	dot(t_vecf2 a, t_vecf2 b);
float	mag(t_vecf2 a);
float	rmag(t_vecf2 a);

#endif
