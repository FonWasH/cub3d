/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input_key_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:41:23 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 16:42:55 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_key(t_key *key)
{
	int	i;

	i = 0;
	while (i < KEY_NB)
	{
		key[i].pressed = false;
		key[i].released = false;
		i++;
	}
}
