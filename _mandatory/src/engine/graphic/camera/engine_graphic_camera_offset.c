/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_camera_offset.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 03:58:27 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 19:33:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cam_offset(t_cam *cam, t_player *player, t_win *win)
{
	float	hoffset;

	hoffset = player->height * player->cam.zoom * win->size.y;
	cam->fhoffset = (win->half_h + hoffset) * player->cam.rzoom;
	cam->choffset = (win->half_h - hoffset) * player->cam.rzoom;
}
