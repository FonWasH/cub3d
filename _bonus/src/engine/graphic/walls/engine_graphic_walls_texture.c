/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_walls_texture.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:21:53 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 09:59:48 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine_graphic_walls_arg.h"

uint32_t	*wall_tex_index(t_walls_arg *w)
{
	int			itex;
	t_emap_type	type;
	u_int32_t	*tex;

	tex = NULL;
	itex = w->map.elem[w->impact.x][w->impact.y].itex;
	type = w->map.elem[w->impact.x][w->impact.y].type;
	if (type == WALL)
		tex = (u_int32_t *)w->map.tex[TW][itex].data;
	else if (type == SHOP)
		tex = (u_int32_t *)w->map.tex[TS][itex].data;
	else if (type == PDOOR)
		tex = (u_int32_t *)w->map.tex[TP][itex].data;
	return (tex);
}
