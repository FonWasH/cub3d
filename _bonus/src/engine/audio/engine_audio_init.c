/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_audio_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:25:59 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 03:24:14 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_audio(t_audio *audio)
{
	int		i;

	audio->ptr = NULL;
	i = 0;
	while (i < MAX_AUDIO)
	{
		audio->sounds[i] = NULL;
		i++;
	}
}
