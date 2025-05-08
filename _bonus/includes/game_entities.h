/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entities.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 04:01:35 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 14:14:52 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENTITIES_H
# define GAME_ENTITIES_H

# include "game_entities_player.h"
# include "game_entities_enemies.h"

typedef struct s_entities
{
	t_player	player;
	t_enemies	enemies;
}				t_entities;

void	init_entities(t_entities *entities);
void	free_entities(t_entities *entities);
void	loop_entities(t_data *d);

#endif
