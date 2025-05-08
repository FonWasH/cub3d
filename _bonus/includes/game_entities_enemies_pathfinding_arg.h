/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_pathfinding_arg.h            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:17:11 by juperez           #+#    #+#             */
/*   Updated: 2025/04/30 15:42:34 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENTITIES_ENEMIES_PATHFINDING_ARG_H
# define GAME_ENTITIES_ENEMIES_PATHFINDING_ARG_H

typedef struct s_find_arg
{
	t_pathfinding	*p;
	t_enemy			*enemy;
	t_map			map;
	t_vecf2			enemy_pos;
	t_vec2			pos_start;
	t_vec2			pos_end;
	int				path_len;
	int				next_node;
}					t_find_arg;

typedef struct s_node_arg
{
	t_vec2			next_pos;
	float			new_g_cost;
	int				next_index;
}					t_node_arg;

#endif
