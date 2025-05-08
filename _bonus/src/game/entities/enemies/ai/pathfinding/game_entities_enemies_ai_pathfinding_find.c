/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_ai_pathfinding_find.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:36:27 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 21:42:51 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "game_entities_enemies_pathfinding_arg.h"

static void	init_args(t_data *d, t_find_arg *f,
	t_pathfinding *p, t_enemy *enemy)
{
	f->p = p;
	f->enemy = enemy;
	f->map = d->game.map;
	f->pos_start = (t_vec2){(int)enemy->pos.x, (int)enemy->pos.y};
	f->pos_end = (t_vec2){(int)d->game.entities.player.pos.x,
		(int)d->game.entities.player.pos.y};
	f->enemy_pos = (t_vecf2){enemy->pos.x, enemy->pos.y};
	f->path_len = -1;
	f->next_node = 1;
}

static void	init_path(t_find_arg *f)
{
	reset_pathfinding(f->p);
	if (f->pos_start.x < 0 || f->pos_start.x >= MAP_SIZE_X
		|| f->pos_start.y < 0 || f->pos_start.y >= MAP_SIZE_Y
		|| f->pos_end.x < 0 || f->pos_end.x >= MAP_SIZE_X
		|| f->pos_end.y < 0 || f->pos_end.y >= MAP_SIZE_Y)
	{
		f->path_len = 0;
		return ;
	}
	if (f->pos_start.x == f->pos_end.x && f->pos_start.y == f->pos_end.y)
	{
		f->p->path[0] = f->enemy_pos;
		f->path_len = 1;
		return ;
	}
	f->p->nodes[0].pos = f->pos_start;
	f->p->nodes[0].g_cost = 0;
	f->p->nodes[0].h_cost = heu(f->pos_start, f->pos_end);
	f->p->nodes[0].f_cost = f->p->nodes[0].h_cost;
	f->p->nodes[0].parent_index = -1;
}

static int	check_closest_node(t_find_arg *f)
{
	int		closest_node;
	float	closest_dist;
	float	dist;
	int		i;

	if (f->p->closed_size > 0)
	{
		closest_node = 0;
		closest_dist = FLT_MAX;
		i = 0;
		while (i < f->p->closed_size)
		{
			dist = heu(f->p->nodes[f->p->closed_list[i]].pos, f->pos_end);
			if (dist < closest_dist)
			{
				closest_dist = dist;
				closest_node = f->p->closed_list[i];
			}
			i++;
		}
		return (build_path(f->p, closest_node));
	}
	return (0);
}

int	find_path(t_data *d, t_pathfinding *p, t_enemy *enemy)
{
	t_find_arg	f;

	init_args(d, &f, p, enemy);
	init_path(&f);
	if (f.path_len >= 0)
		return (f.path_len);
	add_to_open(f.p, 0);
	f.next_node = 1;
	while (f.p->open_size > 0 && f.next_node < AI_MAX_NODES)
		find_next_node(&f);
	if (f.path_len >= 0)
		return (f.path_len);
	return (check_closest_node(&f));
}
