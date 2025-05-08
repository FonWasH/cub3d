/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 04:56:24 by juperez           #+#    #+#             */
/*   Updated: 2025/05/06 12:42:58 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INPUTS_H
# define GAME_INPUTS_H

# define KEY_NB					65508
# define MOUSE_BUTTON_NB		4
# define MOUSE_SENSITIVITY		0.005f	// 0.005
# define MOUSE_AIM_SENSITIVITY	0.0025f	// 0.0025
# define MOUSE_SMOOTH			0.5f

//	KEY_W		// move forward
//	KEY_A		// move left
//	KET_S		// move right
//	KEY_D		// move right
//	KEY_E		// interact
//	KEY_R		// reload
//	KEY_CTRL	// crouch
//	KEY_SHIFT	// sprint
//	KEY_SPACE	// jump
//	KEY_LEFT	// camera yaw left
//	KEY_UP		// camera pitch up
//	KEY_RIGHT	// camera yaw right
//	KEY_DOWN	// camera pitch down
//	KEY_ENTER	// pause
//	KEY_ESCAP	// exit

typedef enum e_ekey
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_E = 101,
	KEY_R = 114,
	KEY_CTRL = 65507,
	KEY_SHIFT = 65505,
	KEY_SPACE = 32,
	KEY_LEFT = 65361,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364,
	KEY_ENTER = 65293,
	KEY_ESCAP = 65307
}	t_ekey;

//	BTN_LEFT	//fire
//	BTN_RIGHT	//aim

typedef enum e_ebutton
{
	NO_BTN = 0,
	BTN_LEFT = 1,
	BTN_RIGHT = 3,
}	t_ebutton;

typedef struct s_data	t_data;
typedef struct s_game	t_game;

typedef struct s_key
{
	bool		pressed;
	bool		released;
}				t_key;

typedef struct s_button
{
	bool		pressed;
	bool		released;
	t_vec2		pos;
}				t_button;

typedef struct s_mouse
{
	t_vecf2		delta;
	t_button	buttons[MOUSE_BUTTON_NB];
}				t_mouse;

typedef struct s_inputs
{
	t_key		keys[KEY_NB];
	t_mouse		mouse;
}				t_inputs;

void	init_inputs(t_inputs *inputs, void *mlx_ptr, void *win_ptr);
void	init_keys(t_key *keys);
void	init_mouse(t_mouse *mouse, void *mlx_ptr, void *win_ptr);
void	loop_inputs(t_data *d);
void	loop_keys(t_data *d);
void	loop_mouse(t_data *d);
int		hook_key_press(int key_code, void *data);
int		hook_key_release(int key_code, void *data);
int		hook_btn_press(int button, int x, int y, void *data);
int		hook_btn_release(int button, int x, int y, void *data);
int		hook_motion(int x, int y, void *data);
void	loop_keys_menu(t_data *d);
void	loop_keys_camera(t_game *game, float delta_time, int height);
void	loop_keys_player(t_data *d, t_game *game, float delta_time);
void	loop_mouse_camera(t_game *game, float delta_time, int height);
void	loop_mouse_player(t_data *d, t_game *game);

#endif
