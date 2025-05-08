/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_physic_enemies.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 07:24:19 by juperez           #+#    #+#             */
/*   Updated: 2025/04/24 10:40:45 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_PHYSIC_ENEMIES_H
# define ENGINE_PHYSIC_ENEMIES_H

void	sort_enemies(t_list *enemies);
void	*calc_render_enemy_1(void *arg);
void	calc_render_enemy_2(t_data *d, t_enemy *enemy);

#endif
