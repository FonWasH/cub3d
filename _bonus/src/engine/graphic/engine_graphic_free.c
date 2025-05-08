/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:34:14 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 11:36:01 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_graphic(t_data *d)
{
	if (d->engine.graphic.frame.ptr && d->engine.graphic.frame.data)
		mlx_destroy_image(d->mlx, d->engine.graphic.frame.ptr);
	if (d->engine.graphic.zbuffer)
		ft_mfree((void **)d->engine.graphic.zbuffer, MAX_WIDTH);
	free_sprites(&d->engine.graphic.sprites, d->mlx);
}
