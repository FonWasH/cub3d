/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_thread_worker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:40:09 by juperez           #+#    #+#             */
/*   Updated: 2025/04/10 19:22:40 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_task	*get_next_task(t_threads *threads)
{
	t_task	*task;

	task = threads->queue.front;
	if (task)
	{
		threads->queue.front = task->next;
		if (threads->queue.front == NULL)
			threads->queue.rear = NULL;
		threads->queue.size--;
		pthread_mutex_lock(&threads->queue.active_mutex);
		threads->queue.active_tasks++;
		pthread_mutex_unlock(&threads->queue.active_mutex);
	}
	return (task);
}

static void	execute_task(t_threads *threads, t_task *task)
{
	(*(task->func))(task->arg);
	free(task);
	pthread_mutex_lock(&threads->queue.active_mutex);
	threads->queue.active_tasks--;
	if (threads->queue.active_tasks == 0 && threads->queue.size == 0)
		pthread_cond_signal(&threads->queue.tasks_done);
	pthread_mutex_unlock(&threads->queue.active_mutex);
}

void	*threads_worker(void *arg)
{
	t_threads	*threads;
	t_task		*task;

	threads = (t_threads *)arg;
	while (true)
	{
		pthread_mutex_lock(&threads->queue.mutex);
		while (threads->queue.size == 0 && !threads->queue.shutdown)
			pthread_cond_wait(&threads->queue.has_tasks, &threads->queue.mutex);
		if (threads->queue.shutdown && threads->queue.size == 0)
		{
			pthread_mutex_unlock(&threads->queue.mutex);
			pthread_exit(NULL);
		}
		task = get_next_task(threads);
		pthread_mutex_unlock(&threads->queue.mutex);
		if (task)
			execute_task(threads, task);
	}
	return (NULL);
}
