/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_ai_pathfinding_node.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:07:48 by juperez           #+#    #+#             */
/*   Updated: 2025/04/30 15:43:19 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game_entities_enemies_pathfinding_arg.h"

static void	replace_node(t_find_arg *f, int current_index, t_node_arg *n)
{
	int	node_index;

	node_index = f->p->open_list[n->next_index];
	if (n->new_g_cost < f->p->nodes[node_index].g_cost)
	{
		f->p->nodes[node_index].g_cost = n->new_g_cost;
		f->p->nodes[node_index].f_cost = n->new_g_cost
			+ f->p->nodes[node_index].h_cost;
		f->p->nodes[node_index].parent_index = current_index;
	}
}

static void	add_node(t_find_arg *f, int current_index, t_node_arg *n)
{
	t_node	*new_node;

	if (f->next_node < AI_MAX_NODES)
	{
		new_node = &f->p->nodes[f->next_node];
		new_node->pos = n->next_pos;
		new_node->g_cost = n->new_g_cost;
		new_node->h_cost = heu(n->next_pos, f->pos_end);
		new_node->f_cost = n->new_g_cost + new_node->h_cost;
		new_node->parent_index = current_index;
		add_to_open(f->p, f->next_node);
		f->next_node++;
	}
}

static void	check_dir_path(t_find_arg *f, int dir,
	int current_index, t_vec2 current_pos)
{
	const int	dx[AI_DIR] = {0, 1, 1, 1, 0, -1, -1, -1};
	const int	dy[AI_DIR] = {-1, -1, 0, 1, 1, 1, 0, -1};
	float		move_cost;
	t_node_arg	n;

	n.next_pos = (t_vec2){current_pos.x + dx[dir], current_pos.y + dy[dir]};
	if ((n.next_pos.x < 0 || n.next_pos.x >= MAP_SIZE_X
			|| n.next_pos.y < 0 || n.next_pos.y >= MAP_SIZE_Y
			|| f->map.elem[n.next_pos.y][n.next_pos.x].collision >= BLOCK_ENEMY)
		|| is_in_closed_list(f->p, n.next_pos))
		return ;
	move_cost = 1.414f;
	if (dir % 2 == 0)
		move_cost = 1.0f;
	n.new_g_cost = f->p->nodes[current_index].g_cost + move_cost;
	n.next_index = get_pos_open_list(f->p, n.next_pos);
	if ((n.next_index == -1) && (f->next_node < AI_MAX_NODES))
		add_node(f, current_index, &n);
	else
		replace_node(f, current_index, &n);
}

void	find_next_node(t_find_arg *f)
{
	int		current_index;
	t_vec2	current_pos;
	int		i;

	current_index = pop_lowest_f_cost(f->p);
	add_to_closed(f->p, current_index);
	current_pos = f->p->nodes[current_index].pos;
	if (current_pos.x == f->pos_end.x && current_pos.y == f->pos_end.y)
	{
		f->path_len = build_path(f->p, current_index);
		return ;
	}
	i = 0;
	while (i < AI_DIR)
	{
		check_dir_path(f, i, current_index, current_pos);
		i++;
	}
}
