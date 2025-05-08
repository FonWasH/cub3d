/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:28:35 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 08:02:51 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	new_img(void *mlx_ptr, t_vec2 size)
{
	t_image	img;
	int		bpp;
	int		len;
	int		end;

	img.ptr = mlx_new_image(mlx_ptr, size.x, size.y);
	if (!img.ptr)
		return (img);
	img.data = (u_int32_t *)mlx_get_data_addr(img.ptr, &bpp, &len, &end);
	return (img);
}

t_image	open_img(void *mlx_ptr, char *path)
{
	t_image	img;
	t_vec2	size;
	int		bpp;
	int		len;
	int		end;

	img.ptr = mlx_xpm_file_to_image(mlx_ptr, path, &size.x, &size.y);
	if (!img.ptr)
		return (img);
	img.data = (u_int32_t *)mlx_get_data_addr(img.ptr, &bpp, &len, &end);
	return (img);
}
