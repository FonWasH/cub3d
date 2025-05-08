/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_threads.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:35:15 by juperez           #+#    #+#             */
/*   Updated: 2025/04/23 04:39:04 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_THREADS_H
# define ENGINE_THREADS_H

# include <pthread.h>

# define THREADS_NB	4

typedef struct s_data	t_data;

typedef struct s_task_arg
{
	t_data			*d;
	int				start;
	int				end;
}					t_task_arg;

typedef struct s_task
{
	void			*(*func)(void *);
	void			*arg;
	struct s_task	*next;
}					t_task;

typedef struct s_queue_flag
{
	bool			mutex;
	bool			active_mutex;
	bool			has_tasks;
	bool			tasks_done;
}					t_queue_flag;

typedef struct s_queue
{
	t_task			*front;
	t_task			*rear;
	pthread_mutex_t	mutex;
	pthread_mutex_t	active_mutex;
	pthread_cond_t	has_tasks;
	pthread_cond_t	tasks_done;
	int				size;
	int				active_tasks;
	Bool			shutdown;
}					t_queue;

typedef struct s_threads
{
	pthread_t		pool[THREADS_NB];
	t_queue			queue;
	bool			initialized;
}					t_threads;

bool	init_threads(t_threads *threads);
void	free_threads(t_threads *threads);
void	*threads_worker(void *arg);
bool	threads_add_task(t_threads *threads, void *(*func)(void *), void *arg);
void	threads_wait_tasks(t_threads *threads);

#endif
