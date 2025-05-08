/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entity.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 04:01:35 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 17:39:12 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENTITY_H
# define GAME_ENTITY_H

# define PLAYER_PLANE			0.66f
# define PLAYER_ROTATION_SPEED	2.0f
# define PLAYER_MAX_PITCH		1.0f
# define PLAYER_ZOOM			1.0f
# define PLAYER_ZOOM_FACTOR		0.5f
# define PLAYER_RZOOM_FACTOR	2.0f
# define PLAYER_MOVE_SPEED		2.0f
# define PLAYER_JUMP_MAX_HEIGHT	0.5f
# define PLAYER_JUMP_VELOCITY	2.5f
# define PLAYER_CROUCH_HEIGHT	-0.25f

typedef struct s_map	t_map;
typedef struct s_spwn	t_spwn;

typedef struct s_rot
{
	t_vecf2		cos;
	t_vecf2		sin;
}				t_rot;

typedef struct s_pcam
{
	t_vecf2		dir;
	t_vecf2		plane;
	float		zoom;
	float		rzoom;
	float		pitch;
	int			poffset;
	t_rot		rot;
}				t_pcam;

typedef struct s_state
{
	bool		aim;
	bool		ground;
	bool		jump;
	bool		crouch;
}				t_state;

typedef struct s_player
{
	t_vecf2		pos;
	t_pcam		cam;
	float		speed;
	float		height;
	float		velocity;
	t_state		state;
}				t_player;

typedef struct s_entity
{
	t_player	player;
}				t_entity;

void	init_entity(t_entity *entity, t_spwn spawn);
void	init_player(t_player *player, t_spwn spawn);
void	set_player_pos(t_player *player, t_vecf2 pos, t_map *map);

#endif
