/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 06:42:16 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 19:45:30 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_menu(t_data *d)
{
	uint32_t	*framebuffer;
	t_vec2		i;
	uint32_t	color;

	framebuffer = d->engine.graphic.frame.data;
	color = set_color((t_color){255, 255, 255});
	i.x = 0;
	while (i.x < d->win.size.x)
	{
		i.y = 0;
		while (i.y < d->win.size.y)
		{
			framebuffer[i.y * d->win.size.x + i.x] = 0x00000000;
			i.y++;
		}
		i.x++;
	}
	mlx_put_image_to_window(d->mlx, d->win.ptr,
		d->engine.graphic.frame.ptr, 0, 0);
	mlx_string_put(d->mlx, d->win.ptr, 10, 40, color, "MENU");
}
