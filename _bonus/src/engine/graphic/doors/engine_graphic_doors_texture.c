/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_doors_texture.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 01:22:59 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 02:32:10 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine_graphic_walls_arg.h"

uint32_t	*door_tex_index(t_walls_arg *w)
{
	int			itex;
	t_emap_type	type;
	u_int32_t	*tex;

	tex = NULL;
	itex = w->map.elem[w->impact.x][w->impact.y].itex;
	type = w->map.elem[w->impact.x][w->impact.y].type;
	if (type == EDOOR)
		tex = (u_int32_t *)w->map.tex[TE][itex].data;
	else if (type == PDOOR)
		tex = (u_int32_t *)w->map.tex[TP][itex].data;
	return (tex);
}
