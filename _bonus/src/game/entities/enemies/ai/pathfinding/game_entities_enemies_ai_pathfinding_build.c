/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_ai_pathfinding_build.        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:20:58 by juperez           #+#    #+#             */
/*   Updated: 2025/04/30 11:05:55 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	build_path(t_pathfinding *p, int node)
{
	int	indices[AI_MAX_PATH];
	int	count;
	int	current;
	int	node_index;
	int	i;

	current = node;
	count = 0;
	while (current != -1 && count < AI_MAX_PATH)
	{
		indices[count++] = current;
		current = p->nodes[current].parent_index;
	}
	if (count > AI_MAX_PATH)
		count = AI_MAX_PATH;
	i = 0;
	while (i < count)
	{
		node_index = indices[count - 1 - i];
		p->path[i].x = (float)p->nodes[node_index].pos.x + 0.5f;
		p->path[i].y = (float)p->nodes[node_index].pos.y + 0.5f;
		i++;
	}
	return (count);
}
