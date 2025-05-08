/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_ai_pathfinding_pop.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:09:50 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 19:02:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pop_lowest_f_cost(t_pathfinding *pathfinding)
{
	int	index;
	int	i;

	i = get_lowest_f_cost(pathfinding);
	index = pathfinding->open_list[i];
	while (i < pathfinding->open_size - 1)
	{
		pathfinding->open_list[i] = pathfinding->open_list[i + 1];
		i++;
	}
	pathfinding->open_size--;
	return (index);
}
