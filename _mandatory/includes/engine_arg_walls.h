/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_arg_walls.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 04:15:46 by juperez           #+#    #+#             */
/*   Updated: 2025/04/08 07:18:42 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_ARG_WALLS_H
# define ENGINE_ARG_WALLS_H

typedef struct s_wdist_arg
{
	t_vecf2		delta;
	t_vecf2		side;
	t_vec2		step;
	t_vec2		map;
}				t_wdist_arg;

typedef struct s_walls_arg
{
	int			half_h;
	int			h;
	int			w;
	t_vecf2		*ray;
	t_fog		fog;
	t_pcam		player_cam;
	t_vecf2		player_pos;
	float		player_h;
	t_mtex		*tex;
	uint32_t	*framebuffer;
	uint32_t	*wall_tex;
	t_vec2		tpos;
	float		tcurrent;
	float		tstep;
	float		dist;
	int			hoffset;
	int			line_h;
	int			start;
	int			end;
	int			tindex;
	bool		is_side;
}				t_walls_arg;

#endif
