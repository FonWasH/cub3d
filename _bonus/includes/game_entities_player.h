/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_player.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 04:12:26 by juperez           #+#    #+#             */
/*   Updated: 2025/05/06 12:54:12 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENTITIES_PLAYER_H
# define GAME_ENTITIES_PLAYER_H

# define PLAYER_SPAWN_POS_X		2.5f
# define PLAYER_SPAWN_POS_Y		15.5f
# define PLAYER_PLANE			0.66f
# define PLAYER_ROTATION_SPEED	2.0f
# define PLAYER_MAX_PITCH		1.0f
# define PLAYER_ZOOM			1.0f
# define PLAYER_ZOOM_FACTOR		0.5f
# define PLAYER_RZOOM_FACTOR	2.0f
# define PLAYER_MOVE_SPEED		1.5f
# define PLAYER_SPRINT_SPEED	3.0f
# define PLAYER_CROUCH_SPEED	0.75f
# define PLAYER_JUMP_MAX_HEIGHT	0.49f
# define PLAYER_JUMP_VELOCITY	1.0f
# define PLAYER_CROUCH_HEIGHT	-0.25f
# define PLAYER_BOX				0.2f
# define PLAYER_FIRE_RADIUS		10
# define PLAYER_FIRE_DISTANCE	7.0f
# define PLAYER_REWARD			10
# define PLAYER_MAX_MONEY		999
# define PLAYER_MAX_AMMO		32
# define PLAYER_MAX_CLIP		8
# define PLAYER_MAX_HEALTH		100
# define PLAYER_MAX_STAMINA		100
# define PLAYER_STAMINA_REGEN	2
# define PLAYER_SPRINT_COST		1
# define PLAYER_JUMP_COST		30
# define PLAYER_HIT_FRAME_MAX	6
# define PLAYER_COMPLETE_COUNT	150

typedef struct s_data	t_data;
typedef struct s_map	t_map;
typedef struct s_enemy	t_enemy;
typedef struct s_panims	t_panims;

typedef enum e_pwstate
{
	P_AIMING,
	P_FIRE,
	P_FIRE_AIM,
	P_IDLE,
	P_IDLE_AIM,
	P_PUMP,
	P_RAISE,
	P_RELOAD,
}	t_pwstate;

typedef struct s_pcam
{
	t_vecf2		dir;
	t_vecf2		plane;
	float		zoom;
	float		rzoom;
	float		pitch;
	int			p_offset;
	float		sensitivity;
}				t_pcam;

typedef struct s_pstate
{
	bool		move;
	bool		ground;
	bool		jump;
	bool		crouch;
	bool		dead;
	bool		sprint;
	bool		damage;
	bool		complete;
}				t_pstate;

typedef struct s_weapon
{
	float		frame_count;
	int			iframe;
	t_pwstate	state;
	int			clip;
	int			ammo;
	bool		reload;
	bool		lower;
	bool		pump;
	bool		aim;
}				t_weapon;

typedef struct s_player
{
	t_vecf3		pos;
	t_pcam		cam;
	float		speed;
	float		velocity;
	t_pstate	state;
	int			health;
	int			stamina;
	int			money;
	int			kills;
	int			frame_count;
	int			complete_count;
	t_weapon	weapon;
}				t_player;

void	init_player(t_player *player);
void	loop_player(t_data *d, t_player *player);
float	calc_player_velocity(t_data *d, t_player *player);
void	set_player_pos(t_data *d, t_player *player, t_vecf3 pos, t_map *map);
void	set_player_damage(t_data *d, t_enemy *enemy);

void	player_aim(t_player *player);
void	player_unaim(t_player *player);
void	player_fire(t_data *d);
void	player_reload(t_player *player, t_weapon *weapon, t_panims *anims);
void	weapon_aim(t_data *d, t_player *player,
			t_weapon *weapon, t_panims *anims);
void	weapon_fire(t_data *d, t_weapon *weapon, t_panims *anims);
void	weapon_reload(t_data *d, t_weapon *weapon, t_panims *anims);

#endif
