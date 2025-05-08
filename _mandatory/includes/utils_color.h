/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:43:07 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 08:10:29 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_COLOR_H
# define UTILS_COLOR_H

# define NO_COLOR	-1

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}			t_color;

t_color		get_color(uint32_t color);
uint32_t	set_color(t_color color);

#endif
