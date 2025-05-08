/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_get.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:08:47 by juperez           #+#    #+#             */
/*   Updated: 2025/04/23 09:34:23 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_enemy	*get_enemy(t_list *enemies, size_t id)
{
	t_enemy	*enemy;
	t_list	*tmp;

	tmp = enemies;
	while (tmp)
	{
		enemy = tmp->data;
		if (enemy->id == id)
			return (enemy);
		tmp = tmp->next;
	}
	return (NULL);
}
