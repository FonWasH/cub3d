/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_ai_pathfinding_get.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:47:29 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 19:02:15 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_in_closed_list(t_pathfinding *pathfinding, t_vec2 pos)
{
	int	index;
	int	i;

	i = 0;
	while (i < pathfinding->closed_size)
	{
		index = pathfinding->closed_list[i];
		if (pathfinding->nodes[index].pos.x == pos.x
			&& pathfinding->nodes[index].pos.y == pos.y)
			return (true);
		i++;
	}
	return (false);
}

int	get_pos_open_list(t_pathfinding *pathfinding, t_vec2 pos)
{
	int	index;
	int	i;

	i = 0;
	while (i < pathfinding->open_size)
	{
		index = pathfinding->open_list[i];
		if (pathfinding->nodes[index].pos.x == pos.x
			&& pathfinding->nodes[index].pos.y == pos.y)
			return (index);
		i++;
	}
	return (-1);
}

int	get_lowest_f_cost(t_pathfinding *pathfinding)
{
	float	cost;
	int		lowest;
	int		node;
	int		i;

	cost = FLT_MAX;
	lowest = 0;
	i = 0;
	while (i < pathfinding->open_size)
	{
		node = pathfinding->open_list[i];
		if (pathfinding->nodes[node].f_cost < cost)
		{
			cost = pathfinding->nodes[node].f_cost;
			lowest = i;
		}
		i++;
	}
	return (lowest);
}
