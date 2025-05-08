/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities_enemies_ai_attack.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:27:19 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 02:37:29 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_range_player(t_enemy *enemy)
{
	if (enemy->r.dist < ENEMY_ATK_RANGE)
		return (true);
	return (false);
}

void	enemy_attack(t_data *d, t_enemy *enemy)
{
	if (enemy->state != ATTACK_1 && enemy->state != ATTACK_2)
		enemy->state = get_rand(ATTACK_1, ATTACK_2,
				(int)(d->time.current + enemy->id));
}
