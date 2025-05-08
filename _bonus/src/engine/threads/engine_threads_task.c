/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_thread_task.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:40:12 by juperez           #+#    #+#             */
/*   Updated: 2025/04/10 06:34:17 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	threads_add_task(t_threads *threads, void *(*func)(void *), void *arg)
{
	t_task	*new_task;

	new_task = (t_task *)malloc(sizeof(t_task));
	if (!new_task)
		return (false);
	new_task->func = func;
	new_task->arg = arg;
	new_task->next = NULL;
	pthread_mutex_lock(&threads->queue.mutex);
	if (threads->queue.rear == NULL)
	{
		threads->queue.front = new_task;
		threads->queue.rear = new_task;
	}
	else
	{
		threads->queue.rear->next = new_task;
		threads->queue.rear = new_task;
	}
	threads->queue.size++;
	pthread_cond_signal(&threads->queue.has_tasks);
	pthread_mutex_unlock(&threads->queue.mutex);
	return (true);
}

void	threads_wait_tasks(t_threads *threads)
{
	pthread_mutex_lock(&threads->queue.active_mutex);
	while (threads->queue.size > 0
		|| threads->queue.active_tasks > 0)
		pthread_cond_wait(&threads->queue.tasks_done,
			&threads->queue.active_mutex);
	pthread_mutex_unlock(&threads->queue.active_mutex);
}
