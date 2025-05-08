/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:33:42 by juperez           #+#    #+#             */
/*   Updated: 2025/04/11 00:28:38 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

float	deltatime(long time, long old_time)
{
	float	delta_time;

	delta_time = (time - old_time) / 1000.0f;
	if (delta_time <= 0.0f)
		delta_time = 0.01f;
	return (delta_time);
}

float	fps(float delta_time)
{
	return (1.0f / delta_time);
}
