/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_arg_floor.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 02:11:56 by juperez           #+#    #+#             */
/*   Updated: 2025/04/08 07:50:51 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_ARG_FLOOR_H
# define ENGINE_ARG_FLOOR_H

typedef struct s_floor_arg
{
	int			half_h;
	int			w;
	t_vecf2		*ray;
	float		*ray_rmag;
	float		*angle;
	t_cam		cam;
	t_fog		fog;
	t_pcam		player_cam;
	t_vecf2		player_pos;
	uint32_t	*framebuffer;
	uint32_t	*floor_tex;
	uint32_t	*ceil_tex;
	int			floor_col;
	int			ceil_col;
	uint32_t	color;
	bool		is_floor;
	float		row_dist;
	float		dist;
}				t_floor_arg;

#endif
