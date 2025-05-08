/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_inputs_key_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:41:23 by juperez           #+#    #+#             */
/*   Updated: 2025/04/23 05:08:57 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_keys(t_key *keys)
{
	int	i;

	i = 0;
	while (i < KEY_NB)
	{
		keys[i].pressed = false;
		keys[i].released = false;
		i++;
	}
}
