/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:36:13 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 17:56:35 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_MATH_H
# define UTILS_MATH_H

# define PI_2	1.5708f

typedef struct s_vec2
{
	int		x;
	int		y;
}			t_vec2;

typedef struct s_vec3
{
	int		x;
	int		y;
	int		z;
}			t_vec3;

typedef struct s_vecf2
{
	float	x;
	float	y;
}			t_vecf2;

typedef struct s_vecf3
{
	float	x;
	float	y;
	float	z;
}			t_vecf3;

float	dot(t_vec2 a, t_vec2 b);
float	dotf(t_vecf2 a, t_vecf2 b);
float	mag(t_vec2 a);
float	magf(t_vecf2 a);
float	rmagf(t_vecf2 a);
float	heu(t_vec2 a, t_vec2 b);
float	heuf(t_vecf2 a, t_vecf2 b);

#endif
