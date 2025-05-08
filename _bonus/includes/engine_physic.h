/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_physic.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:33:20 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 13:32:32 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_PHYSIC_H
# define ENGINE_PHYSIC_H

# include "engine_physic_enemies.h"

# define GRAVITY	4.0f

typedef struct s_data	t_data;

void	loop_physic(t_data *d);
void	physic_jump(t_data *d, t_player *player, float delta_time);

#endif
