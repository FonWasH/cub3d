/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:28:35 by juperez           #+#    #+#             */
/*   Updated: 2025/05/02 13:11:02 by juperez          ###   ########.fr       */
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
	img.size = size;
	return (img);
}

t_image	open_img(void *mlx_ptr, char *path)
{
	t_image	img;
	int		bpp;
	int		len;
	int		end;

	img.ptr = mlx_xpm_file_to_image(mlx_ptr, path, &img.size.x, &img.size.y);
	if (!img.ptr)
		return (img);
	img.data = (u_int32_t *)mlx_get_data_addr(img.ptr, &bpp, &len, &end);
	return (img);
}

void	itoi(t_image *s, t_image *d)
{
	uint32_t	*buffer;
	uint32_t	color;
	t_vec2		nearest;
	t_vec2		i;

	buffer = d->data;
	i.y = 0;
	while (i.y < d->size.y)
	{
		i.x = 0;
		while (i.x < d->size.x)
		{
			nearest.x = (int)(i.x * s->size.x / d->size.x);
			nearest.y = (int)(i.y * s->size.y / d->size.y);
			if (nearest.x < 0 || nearest.x >= s->size.x
				|| nearest.y < 0 || nearest.y >= s->size.y)
				break ;
			color = s->data[(int)nearest.y * s->size.x + (int)nearest.x];
			if ((color >> 24) == 0)
				buffer[(int)i.y * d->size.x + (int)i.x] = color;
			i.x++;
		}
		i.y++;
	}
}
