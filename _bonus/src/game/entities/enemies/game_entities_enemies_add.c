/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_add.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 07:39:14 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 02:09:16 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_enemy(t_enemy *enemy, t_vecf3 pos, size_t id, bool in_zone)
{
	enemy->id = id;
	enemy->pos = pos;
	enemy->dir.x = -1.0f;
	enemy->dir.y = 0.0f;
	enemy->state = IDLE;
	enemy->in_zone = in_zone;
	enemy->idle_count = 0;
	enemy->r.dist = 0.0f;
	enemy->r.idir = 0;
	enemy->r.tran.x = 0.0f;
	enemy->r.tran.y = 0.0f;
	enemy->r.w = 0;
	enemy->r.h = 0;
	enemy->r.screen_x = 0;
	enemy->r.h_offset = 0;
	enemy->r.iframe = 0;
	enemy->r.frame_count = 0.0f;
	init_ai(&enemy->ai);
}

void	add_enemy(t_data *d, t_list **enemies, t_vecf3 pos, bool in_zone)
{
	t_enemy	*enemy;
	t_list	*new;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		error(d, ERROR_MEM, NULL);
	init_enemy(enemy, pos, ft_lstsize(*enemies), in_zone);
	new = ft_lstnew(enemy);
	if (!new)
		error(d, ERROR_MEM, NULL);
	ft_lstadd_back(enemies, new);
}
