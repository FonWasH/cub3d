/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:14:47 by juperez           #+#    #+#             */
/*   Updated: 2025/04/24 16:16:51 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_rand(int min, int max, int seed)
{
	int	x;
	int	tmp;
	int	range;

	if (min > max)
	{
		tmp = min;
		min = max;
		max = tmp;
	}
	range = max - min + 1;
	if (range == 1)
		return (min);
	x = seed;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return (min + ((x % range + range) % range));
}
