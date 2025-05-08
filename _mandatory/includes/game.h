/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:53:42 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 17:18:48 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "game_entity.h"
# include "game_input.h"
# include "game_map.h"
# include "game_ui.h"

typedef struct s_data	t_data;

typedef struct s_game
{
	t_entity	entity;
	t_input		input;
	t_map		map;
	bool		menu;
}				t_game;

void	init_game(t_data *d, char *path);
void	free_game(t_data *d);

#endif
