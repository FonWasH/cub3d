/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:37:06 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 08:12:29 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint8_t	red(uint32_t color)
{
	return ((color >> 16) & 0xFF);
}

static uint8_t	green(uint32_t color)
{
	return ((color >> 8) & 0xFF);
}

static uint8_t	blue(uint32_t color)
{
	return (color & 0xFF);
}

t_color	get_color(uint32_t color)
{
	t_color	new;

	new.r = red(color);
	new.g = green(color);
	new.b = blue(color);
	return (new);
}

uint32_t	set_color(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}
