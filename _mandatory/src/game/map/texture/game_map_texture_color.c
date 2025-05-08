/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_texture_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:45:14 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 17:55:16 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_color_value(char *line, int *count)
{
	int		n;
	int		i;
	bool	has_digit;

	has_digit = false;
	i = 0;
	while (line[i] && line[i] != ',' && line[i] != '\n')
	{
		if (!ft_isdigit(line[i]))
			return (false);
		if (ft_isdigit(line[i]))
			has_digit = true;
		i++;
	}
	if (!has_digit)
		return (false);
	n = (int)ft_atol(line);
	if (n > 255 || n < 0)
		return (false);
	*count += 1;
	return (true);
}

static bool	is_line_color(char *line)
{
	int	count;
	int	i;

	count = 0;
	if (!check_color_value(line, &count))
		return (false);
	i = 0;
	while (line[i] && line[i] != ',')
		i++;
	if (line[i] != ',')
		return (false);
	if (!check_color_value(line + ++i, &count))
		return (false);
	while (line[i] && line[i] != ',')
		i++;
	if (line[i] != ',')
		return (false);
	if (!check_color_value(line + ++i, &count))
		return (false);
	if (count != 3)
		return (false);
	return (true);
}

int	line_to_color(char *line)
{
	t_color	color;

	if (!is_line_color(line))
		return (NO_COLOR);
	color.r = ft_atol(line);
	while (*line && *line != ',')
		line++;
	line++;
	color.g = ft_atol(line);
	while (*line && *line != ',')
		line++;
	line++;
	color.b = ft_atol(line);
	return (set_color(color));
}
