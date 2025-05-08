/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 04:12:22 by juperez           #+#    #+#             */
/*   Updated: 2025/05/06 12:42:25 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENTITIES_ENEMIES_H
# define GAME_ENTITIES_ENEMIES_H

# define ENEMY_MOV_SPEED	0.5f
# define ENEMY_ROT_SPEED	2.5f
# define ENEMY_ATK_RANGE	0.5f
# define ENEMY_AGR_RANGE	5.0f
# define ENEMY_DAMAGE		25
# define ENEMY_BOX			0.2f
# define AI_UPDATE_FREQ		10		//30
# define AI_MAX_NODES		2000
# define AI_MAX_PATH		200
# define AI_DIR				8
# define ENEMY_SPAWN_CHANCE	5		//2

typedef enum e_estate
{
	IDLE,
	WALK,
	ATTACK_1,
	ATTACK_2,
	DIE_1,
	DIE_2,
}	t_estate;

typedef struct s_data		t_data;
typedef struct s_find_arg	t_find_arg;

typedef struct s_node
{
	t_vec2			pos;
	float			g_cost;
	float			h_cost;
	float			f_cost;
	int				parent_index;
}					t_node;

typedef struct s_pathfinding
{
	t_node			nodes[AI_MAX_NODES];
	int				open_list[AI_MAX_NODES];
	int				closed_list[AI_MAX_NODES];
	int				open_size;
	int				closed_size;
	t_vecf2			path[AI_MAX_PATH];
}					t_pathfinding;

typedef struct s_ai
{
	t_pathfinding	pathfinding;
	int				frame_count;
	t_vecf2			*path;
	int				path_len;
	int				target;
}					t_ai;

typedef struct s_erender
{
	float			dist;
	int				idir;
	t_vecf2			tran;
	int				w;
	int				h;
	int				screen_x;
	int				h_offset;
	int				iframe;
	float			frame_count;
}					t_erender;

typedef struct s_enemy
{
	size_t			id;
	t_vecf3			pos;
	t_vecf2			dir;
	t_estate		state;
	t_erender		r;
	t_ai			ai;
	bool			in_zone;
	int				idle_count;
}					t_enemy;

typedef struct s_enemies
{
	t_list			*list;
}					t_enemies;

void	free_enemies(t_list **enemies);
void	add_enemy(t_data *d, t_list **enemies, t_vecf3 pos, bool in_zone);
t_enemy	*get_enemy(t_list *enemies, size_t id);
void	spawn_enemies(t_data *d, t_list **enemies);

void	init_ai(t_ai *ai);
void	*enemy_seek_player(void *arg);
t_vecf2	get_dir(t_vecf2 from, t_vecf2 to);
void	update_dir(t_vecf2 *enemy_dir, t_vecf2 target_dir, float rot_speed);

bool	check_range_player(t_enemy *enemy);
void	enemy_attack(t_data *d, t_enemy *enemy);
void	enemy_move(t_data *d, t_enemy *e);

void	init_pathfinding(t_pathfinding *pathfinding);
void	reset_pathfinding(t_pathfinding *pathfinding);
void	add_to_open(t_pathfinding *pathfinding, int node);
void	add_to_closed(t_pathfinding *pathfinding, int node);
bool	is_in_closed_list(t_pathfinding *pathfinding, t_vec2 pos);
int		get_pos_open_list(t_pathfinding *pathfinding, t_vec2 pos);
int		get_lowest_f_cost(t_pathfinding *pathfinding);
int		pop_lowest_f_cost(t_pathfinding *pathfinding);
int		build_path(t_pathfinding *pathfinding, int node);
int		find_path(t_data *d, t_pathfinding *pathfinding, t_enemy *enemy);
void	find_next_node(t_find_arg *f);

#endif
