/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_physic_enemies_sort.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:00:43 by juperez           #+#    #+#             */
/*   Updated: 2025/04/24 08:20:55 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_enemies_id(t_list *enemies)
{
	t_enemy	*enemy;
	t_list	*tmp;
	size_t	id;

	tmp = enemies;
	id = 0;
	while (tmp)
	{
		enemy = tmp->data;
		enemy->id = id++;
		tmp = tmp->next;
	}
}

void	sort_enemies(t_list *enemies)
{
	t_list	*tmp;
	t_enemy	*e1;
	t_enemy	*e2;
	void	*tmp_data;

	tmp = enemies;
	while (tmp && tmp->next)
	{
		e1 = tmp->data;
		e2 = tmp->next->data;
		if (e1->r.dist < e2->r.dist)
		{
			tmp_data = tmp->data;
			tmp->data = tmp->next->data;
			tmp->next->data = tmp_data;
			tmp = enemies;
		}
		else
			tmp = tmp->next;
	}
	set_enemies_id(enemies);
}
