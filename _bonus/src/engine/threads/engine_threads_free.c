/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_thread_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:40:06 by juperez           #+#    #+#             */
/*   Updated: 2025/04/10 16:11:27 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_threads(t_threads *threads)
{
	int		i;
	t_task	*task;
	t_task	*next_task;

	if (!threads->initialized)
		return ;
	pthread_mutex_lock(&threads->queue.mutex);
	threads->queue.shutdown = true;
	pthread_cond_broadcast(&threads->queue.has_tasks);
	pthread_mutex_unlock(&threads->queue.mutex);
	i = 0;
	while (i < THREADS_NB)
		pthread_join(threads->pool[i++], NULL);
	task = threads->queue.front;
	while (task)
	{
		next_task = task->next;
		free(task->arg);
		free(task);
		task = next_task;
	}
	pthread_mutex_destroy(&threads->queue.mutex);
	pthread_mutex_destroy(&threads->queue.active_mutex);
	pthread_cond_destroy(&threads->queue.has_tasks);
	pthread_cond_destroy(&threads->queue.tasks_done);
}
