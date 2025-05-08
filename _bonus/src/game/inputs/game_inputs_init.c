/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:18:41 by juperez           #+#    #+#             */
/*   Updated: 2025/04/23 05:09:04 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_inputs(t_inputs *inputs, void *mlx_ptr, void *win_ptr)
{
	init_keys(inputs->keys);
	init_mouse(&inputs->mouse, mlx_ptr, win_ptr);
}
