/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:06:06 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 15:06:07 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_H
# define ENGINE_GRAPHIC_H

# include "engine_graphic_doors.h"
# include "engine_graphic_effects.h"
# include "engine_graphic_floor.h"
# include "engine_graphic_fog.h"
# include "engine_graphic_rays.h"
# include "engine_graphic_sprites.h"
# include "engine_graphic_walls.h"

# define MAX_DISTANCE		10000.0f

typedef struct s_data	t_data;

typedef struct s_graphic
{
	t_image		frame;
	t_floor		floor;
	t_fog		fog;
	t_rays		rays;
	t_sprites	sprites;
	float		**zbuffer;
}				t_graphic;

void	init_frame(t_data *d);
void	init_graphic(t_data *d);
void	free_graphic(t_data *d);
void	loop_graphic(t_data *d);
void	*reset_z_buffer(void *arg);

#endif
