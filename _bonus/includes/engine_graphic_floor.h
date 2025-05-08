/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_floor.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:36:12 by juperez           #+#    #+#             */
/*   Updated: 2025/04/23 04:50:37 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_FLOOR_H
# define ENGINE_GRAPHIC_FLOOR_H

typedef struct s_win	t_win;

typedef struct s_floor
{
	float	fz_offset;
	float	cz_offset;
	float	dir_rmag;
	float	rays_rmag[MAX_WIDTH];
	float	angle[MAX_WIDTH];
}			t_floor;

void	init_floor(t_floor *floor);
void	*draw_floor(void *arg);
void	*calc_floor(void *arg);
void	floor_z_offset(t_floor *floor, t_player *player, t_win *win);

#endif
