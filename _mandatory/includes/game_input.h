/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 04:56:24 by juperez           #+#    #+#             */
/*   Updated: 2025/04/18 05:44:00 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INPUT_H
# define GAME_INPUT_H

# define KEY_NB				65508
# define MOUSE_BUTTON_NB	6

typedef enum e_ekey
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_E = 101,
	KEY_CTRL = 65507,
	KEY_SPACE = 32,
	KEY_LEFT = 65361,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364,
	KEY_ENTER = 65293,
	KEY_ESCAP = 65307
}	t_ekey;

typedef struct s_data	t_data;
typedef struct s_game	t_game;

typedef struct s_key
{
	bool		pressed;
	bool		released;
}				t_key;

typedef struct s_input
{
	t_key		key[KEY_NB];
}				t_input;

void	init_input(t_input *input);
void	init_key(t_key *key);
void	loop_input(t_data *d);
void	loop_key(t_data *d);
int		hook_key_press(int key_code, void *data);
int		hook_key_release(int key_code, void *data);
void	loop_key_menu(t_data *d);
void	loop_key_camera(t_game *game, float delta_time, int height);
void	loop_key_player(t_game *game, float delta_time);

#endif
