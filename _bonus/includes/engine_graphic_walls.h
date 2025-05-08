/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_walls.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:14:09 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 01:37:31 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_WALLS_H
# define ENGINE_GRAPHIC_WALLS_H

typedef struct s_data		t_data;
typedef struct s_walls_arg	t_walls_arg;

void		*draw_walls(void *arg);
void		wall_dist(t_walls_arg *w, t_vecf2 ray);
uint32_t	*wall_tex_index(t_walls_arg *w);

#endif
