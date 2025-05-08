/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_audio_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:29:44 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 03:37:23 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_audio(t_audio *audio)
{
	int		i;

	i = 0;
	while (i < MAX_AUDIO)
	{
		if (audio->sounds[i])
			mla_destroy_sound(audio->sounds[i]);
		i++;
	}
	if (audio->ptr)
		mla_destroy_engine(audio->ptr);
}
