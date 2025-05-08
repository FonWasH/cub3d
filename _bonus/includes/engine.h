/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:33:23 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 20:25:24 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "engine_audio.h"
# include "engine_graphic.h"
# include "engine_physic.h"
# include "engine_threads.h"

typedef struct s_data	t_data;

typedef struct s_engine
{
	t_audio		audio;
	t_graphic	graphic;
	t_threads	threads;
}				t_engine;

void	init_engine(t_data *d);
void	free_engine(t_data *d);
void	loop_engine(t_data *d);

#endif
