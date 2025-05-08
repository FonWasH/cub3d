/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_floor_arg.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 02:11:56 by juperez           #+#    #+#             */
/*   Updated: 2025/04/28 07:47:42 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_FLOOR_ARG_H
# define ENGINE_GRAPHIC_FLOOR_ARG_H

typedef struct s_floor_arg
{
	int			w;
	int			half_h;
	t_vecf2		*rays;
	float		*rays_rmag;
	float		*angle;
	float		fz_offset;
	float		cz_offset;
	t_fog		fog;
	t_pcam		player_cam;
	t_vecf3		player_pos;
	t_map		map;
	uint32_t	*framebuffer;
	uint32_t	*tex;
	bool		is_floor;
	float		row_dist;
}				t_floor_arg;

#endif
