/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_ai_pathfinding_add.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:41:57 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 18:58:10 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_to_open(t_pathfinding *pathfinding, int node)
{
	if (pathfinding->open_size < AI_MAX_NODES)
		pathfinding->open_list[pathfinding->open_size++] = node;
}

void	add_to_closed(t_pathfinding *pathfinding, int node)
{
	if (pathfinding->closed_size < AI_MAX_NODES)
		pathfinding->closed_list[pathfinding->closed_size++] = node;
}
