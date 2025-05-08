/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_ai_pathfinding_init.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:06:00 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 21:48:53 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_node	init_node(void)
{
	t_node	node;

	node.pos.x = 0;
	node.pos.y = 0;
	node.g_cost = 0.0f;
	node.h_cost = 0.0f;
	node.f_cost = 0.0f;
	node.parent_index = 0;
	return (node);
}

void	init_pathfinding(t_pathfinding *pathfinding)
{
	int	i;

	pathfinding->open_size = 0;
	pathfinding->closed_size = 0;
	i = 0;
	while (i < AI_MAX_PATH)
	{
		pathfinding->path[i].x = 0.0f;
		pathfinding->path[i].y = 0.0f;
		i++;
	}
	i = 0;
	while (i < AI_MAX_NODES)
	{
		pathfinding->open_list[i] = 0;
		pathfinding->closed_list[i] = 0;
		pathfinding->nodes[i] = init_node();
		i++;
	}
}

void	reset_pathfinding(t_pathfinding *pathfinding)
{
	pathfinding->open_size = 0;
	pathfinding->closed_size = 0;
}
