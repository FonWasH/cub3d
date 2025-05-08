/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_thread_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:16:30 by juperez           #+#    #+#             */
/*   Updated: 2025/04/10 19:20:56 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_queue(t_queue *queue, t_queue_flag *flag)
{
	if (flag->mutex)
		pthread_mutex_destroy(&queue->mutex);
	if (flag->active_mutex)
		pthread_mutex_destroy(&queue->active_mutex);
	if (flag->has_tasks)
		pthread_cond_destroy(&queue->has_tasks);
	if (flag->tasks_done)
		pthread_cond_destroy(&queue->tasks_done);
}

static bool	init_mutex_cond(t_queue *queue, t_queue_flag *flag)
{
	*flag = (t_queue_flag){false, false, false, false};
	if (pthread_mutex_init(&queue->mutex, NULL) == 0)
		flag->mutex = true;
	else
		return (destroy_queue(queue, flag), false);
	if (pthread_mutex_init(&queue->active_mutex, NULL) == 0)
		flag->active_mutex = true;
	else
		return (destroy_queue(queue, flag), false);
	if (pthread_cond_init(&queue->has_tasks, NULL) == 0)
		flag->has_tasks = true;
	else
		return (destroy_queue(queue, flag), false);
	if (pthread_cond_init(&queue->tasks_done, NULL) == 0)
		flag->tasks_done = true;
	else
		return (destroy_queue(queue, flag), false);
	return (true);
}

static bool	init_queue(t_queue *queue, t_queue_flag *flag)
{
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	queue->active_tasks = 0;
	queue->shutdown = false;
	return (init_mutex_cond(queue, flag));
}

bool	init_threads(t_threads *threads)
{
	t_queue_flag	flag;
	int				i;

	if (!init_queue(&threads->queue, &flag))
		return (false);
	i = 0;
	while (i < THREADS_NB)
	{
		if (pthread_create(&threads->pool[i], NULL,
				threads_worker, threads) != 0)
		{
			while (--i >= 0)
				pthread_join(threads->pool[i], NULL);
			return (destroy_queue(&threads->queue, &flag), false);
		}
		i++;
	}
	threads->initialized = true;
	return (true);
}
