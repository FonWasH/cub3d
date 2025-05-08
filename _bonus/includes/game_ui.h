/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 06:36:50 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 23:58:36 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UI_H
# define GAME_UI_H

# define FPS_MAX		999
# define MINIMAP_RATIO	0.25f
# define MINIMAP_POS	10.0f
# define MINIMAP_RADIUS	5.0f
# define MINIMAP_BORDER	2.0f
# define MINIMAP_SIZE	180

# define SCREEN_COMPLETE	"../resources/assets/screen/complete.xpm"
# define SCREEN_GAMEOVER	"../resources/assets/screen/gameover.xpm"
# define SCREEN_LOADING		"../resources/assets/screen/loading.xpm"
# define SCREEN_MENU		"../resources/assets/screen/pause.xpm"

typedef enum e_hud_elem
{
	HUD_DA,
	HUD_DM,
	HUD_AMMO,
	HUD_STATUS
}	t_hud_elem;

typedef struct s_data	t_data;

typedef struct s_ehud
{
	t_image	*src;
	t_image	*dst;
	t_vec2	offset;
	t_vec2	draw_size;
}			t_ehud;

typedef struct s_screen
{
	t_image		complete;
	t_image		gameover;
	t_image		loading;
	t_image		pause;
}				t_screen;

typedef struct s_triangle
{
	t_vecf2		p[3];
	t_vecf2		b_min;
	t_vecf2		b_max;
	float		det;
}				t_triangle;

typedef struct s_minimap
{
	t_vec2		scale;
	t_vec2		pos;
	t_vec2		center;
	float		dist[MINIMAP_SIZE][MINIMAP_SIZE];
	t_triangle	triangle;
}				t_minimap;

typedef struct s_ui
{
	t_screen	screen;
	t_minimap	minimap;
}				t_ui;

void	init_ui(t_data *d);
void	free_ui(t_ui *ui, void *mlx_ptr);
void	loop_ui(t_data *d);
void	init_minimap(t_minimap *minimap, int width);
void	draw_minimap(t_data *d);
void	draw_minimap_background(t_data *d, t_minimap *minimap);
void	draw_minimap_border(t_data *d, t_minimap *minimap);
void	draw_minimap_player(t_data *d, t_triangle *triangle);
void	draw_ehud(t_image *src, t_image *dst, t_vecf2 pos, t_vecf2 ratio);
void	show_fps(float delta_time, void *mlx_ptr, void *win_ptr);
void	draw_loading_screen(t_data *d);
void	init_screen(t_screen *screen);
void	free_screen(t_screen *screen, void *mlx_ptr);
void	load_screen(t_data *d);

#endif
