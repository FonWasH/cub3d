/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_zbuffer_reset.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:54:25 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 11:36:08 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*reset_z_buffer(void *arg)
{
	t_task_arg	*task;
	t_data		*d;
	t_vec2		i;

	task = (t_task_arg *)arg;
	d = task->d;
	i.x = task->start;
	while (i.x < task->end)
	{
		i.y = 0;
		while (i.y < d->win.size.y)
		{
			d->engine.graphic.zbuffer[i.x][i.y] = MAX_DISTANCE;
			i.y++;
		}
		i.x++;
	}
	return (free(task), NULL);
}
