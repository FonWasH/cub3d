/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 07:53:42 by juperez           #+#    #+#             */
/*   Updated: 2025/05/02 13:59:07 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "game_entities.h"
# include "game_inputs.h"
# include "game_map.h"
# include "game_ui.h"

typedef struct s_data	t_data;

typedef struct s_game
{
	t_entities	entities;
	t_inputs	inputs;
	t_map		map;
	t_ui		ui;
	bool		pause;
}				t_game;

void	init_game(t_data *d);
void	free_game(t_data *d);
void	loop_game(t_data *d);

#endif
