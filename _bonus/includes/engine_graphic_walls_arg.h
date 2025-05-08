/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_walls_arg.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 04:15:46 by juperez           #+#    #+#             */
/*   Updated: 2025/04/30 13:32:08 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_WALLS_ARG_H
# define ENGINE_GRAPHIC_WALLS_ARG_H

typedef struct s_wdist_arg
{
	t_vecf2		delta;
	t_vecf2		side;
	t_vec2		step;
	t_vec2		map;
}				t_wdist_arg;

typedef struct s_walls_arg
{
	int			h;
	int			w;
	int			half_h;
	t_vecf2		*rays;
	t_fog		fog;
	t_pcam		player_cam;
	t_vecf3		player_pos;
	t_map		map;
	float		**zbuffer;
	uint32_t	*framebuffer;
	uint32_t	*tex;
	t_vec2		tpos;
	t_vec2		impact;
	float		tcurrent;
	float		tstep;
	float		dist;
	int			z_offset;
	int			line_h;
	int			start;
	int			end;
	bool		is_side;
}				t_walls_arg;

#endif
