/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_doors.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 01:35:32 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 01:37:17 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_DOORS_H
# define ENGINE_GRAPHIC_DOORS_H

typedef struct s_data		t_data;
typedef struct s_walls_arg	t_walls_arg;

void		*draw_doors(void *arg);
void		door_dist(t_walls_arg *w, t_vecf2 ray);
uint32_t	*door_tex_index(t_walls_arg *w);

#endif
