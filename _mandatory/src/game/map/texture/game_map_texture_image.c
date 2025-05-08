/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_texture_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:54:25 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 17:36:45 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_line_xpm_file(char *line)
{
	char	*ext;

	ext = ft_strrchr(line, '.');
	if (!ext || ft_strncmp(ext, ".xpm", 4) || ft_strlen(ext) > 4)
		return (false);
	return (true);
}

t_image	line_to_image(char *line, void *mlx_ptr)
{
	t_image	img;

	img.ptr = NULL;
	img.data = NULL;
	if (!is_line_xpm_file(line))
		return (img);
	img = open_img(mlx_ptr, line);
	return (img);
}
