/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_ai_init.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:13:02 by juperez           #+#    #+#             */
/*   Updated: 2025/04/30 14:10:11 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ai(t_ai *ai)
{
	init_pathfinding(&ai->pathfinding);
	ai->frame_count = 0;
	ai->path = NULL;
	ai->path_len = 0;
	ai->target = 0;
}
