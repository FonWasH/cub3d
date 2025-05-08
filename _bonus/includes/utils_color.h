/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:43:07 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 12:47:04 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_COLOR_H
# define UTILS_COLOR_H

# define BLACK		0x000000
# define GRAY		0x808080
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define CYAN		0x00FFFF

typedef struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}			t_color;

t_color		get_color(uint32_t color);
uint32_t	set_color(t_color color);

#endif
