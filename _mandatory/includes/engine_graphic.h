/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:06:06 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:37:12 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_H
# define ENGINE_GRAPHIC_H

# define TEXTURE_SIZE		128
//512	//256	//128	//64	//32
# define TEXTURE_SIZE_LOG2	7
//9		//8		//7		//6		//5

# define FOG_INTENSITY		0.25f
# define FOG_MAX_DISTANCE	32.0f
# define FOG_LUT_SIZE		1024
# define FOG_MAX_COLOR		255.0f

typedef struct s_data	t_data;
typedef struct s_win	t_win;

typedef struct s_cam
{
	float		lut[MAX_WIDTH];
	float		fhoffset;
	float		choffset;
}				t_cam;

typedef struct s_fog
{
	uint8_t		lut[FOG_LUT_SIZE];
	float		intensity;
	float		rdistance;
}				t_fog;

typedef struct s_render
{
	t_vecf2		ray[MAX_WIDTH];
	float		ray_rmag[MAX_WIDTH];
	float		angle[MAX_WIDTH];
}				t_render;

typedef struct s_graphic
{
	t_image		frame;
	t_cam		cam;
	t_fog		fog;
	t_render	render;
}				t_graphic;

void		init_graphic(t_data *d);
void		free_graphic(t_data *d);
void		loop_graphic(t_data *d);
void		init_cam(t_cam *cam, int width);
void		init_fog(t_fog *fog);
void		init_render(t_render *render);
void		apply_fog(t_fog *fog, uint32_t *color, float distance);
void		cam_offset(t_cam *cam, t_player *player, t_win *win);
float		wall_dist(t_data *d, t_vecf2 ray, bool *is_side);
t_itex		wall_tex_index(bool is_side, t_vecf2 ray);
void		calc_ray(t_data *d);
void		draw_floor(t_data *d);
void		draw_walls(t_data *d);

#endif
