/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_audio_load.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:03:08 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 05:33:22 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "resources_audio.h"

static void	init_audio_engine(t_data *d, t_audio *audio)
{
	audio->ptr = mla_init(SAMPLE_RATE, A_BUFF_SIZE);
	if (!audio->ptr)
	{
		d->load.error = true;
		return (put_error(ERROR_MEM, NULL));
	}
}

static void	load_sounds(t_data *d, t_audio *audio,
	const char *path[], int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (d->load.error)
			return ;
		audio->sounds[i] = mla_new_sound(audio->ptr, (char *)path[i],
				(i == A_AMBIENT || i == A_LOADING || i == A_MUSIC));
		if (!audio->sounds[i])
		{
			d->load.error = true;
			return (put_error(ERROR_MEM, (char *)path[i]));
		}
		d->load.audio_count++;
		i++;
	}
}

static void	load_audio_path(t_data *d, t_audio *audio)
{
	const char	*paths[MAX_AUDIO] = {
		AED, AEG1, AEG2, AEG3, AEG4, AEG5, AEI, AMB, MUS, LOA, JUI, JUO, PAI,
		PSP, PTI, PWA, WAI, WAO, WDF, WFI, WPU, WRE, WSO, WDO, WSA, WSF, WSM
	};

	load_sounds(d, audio, paths, MAX_AUDIO);
	if (!d->load.error)
	{
		mla_loop_sound(audio->sounds[A_AMBIENT], true);
		mla_loop_sound(audio->sounds[A_LOADING], true);
		mla_loop_sound(audio->sounds[A_MUSIC], true);
		mla_set_volume_sound(audio->sounds[A_MUSIC], 0.5f);
	}
}

void	*load_audio(void *arg)
{
	t_task_arg	*task;
	t_data		*d;
	t_audio		*audio;

	task = (t_task_arg *)arg;
	d = task->d;
	audio = &d->engine.audio;
	init_audio_engine(d, audio);
	load_audio_path(d, audio);
	d->load.audio_done = true;
	return (free(task), NULL);
}
