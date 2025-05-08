/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_render_init.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 02:14:48 by juperez           #+#    #+#             */
/*   Updated: 2025/04/08 07:51:24 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_render(t_render *render)
{
	int	i;

	i = 0;
	while (i < MAX_WIDTH)
	{
		render->ray[i].x = 0.0f;
		render->ray[i].y = 0.0f;
		render->ray_rmag[i] = 0.0f;
		render->angle[i] = 0.0f;
		i++;
	}
}
