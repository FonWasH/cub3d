/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 06:36:50 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 17:56:51 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UI_H
# define GAME_UI_H

# define FPS_MAX	999

typedef struct s_data	t_data;

void	show_fps(float delta_time, void *mlx_ptr, void *win_ptr);
void	show_menu(t_data *d);

#endif
