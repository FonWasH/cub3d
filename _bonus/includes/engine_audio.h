/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_audio.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:12:23 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 05:12:59 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_AUDIO_H
# define ENGINE_AUDIO_H

# define MAX_AUDIO			27
# define SAMPLE_RATE		44100
# define A_BUFF_SIZE		4096

typedef enum e_sounds
{
	A_DIE,
	A_GROWL_1,
	A_GROWL_2,
	A_GROWL_3,
	A_GROWL_4,
	A_GROWL_5,
	A_IDLE,
	A_AMBIENT,
	A_MUSIC,
	A_LOADING,
	A_JUMP_IN,
	A_JUMP_OUT,
	A_PAIN,
	A_SPRINT,
	A_TIRED,
	A_WALK,
	A_AIM_IN,
	A_AIM_OUT,
	A_DRY_FIRE,
	A_FIRE,
	A_PUMP,
	A_RELOAD,
	A_SHELL_OUT,
	A_DOOR,
	A_AMMO,
	A_FAIL,
	A_MEDKIT,
}	t_sounds;

typedef struct s_audio
{
	void	*ptr;
	void	*sounds[MAX_AUDIO];
}			t_audio;

void	init_audio(t_audio *audio);
void	free_audio(t_audio *audio);
void	*load_audio(void *arg);

#endif
