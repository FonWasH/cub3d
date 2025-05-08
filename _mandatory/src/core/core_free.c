/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:07:52 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 16:38:45 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_core(t_data *d)
{
	free_game(d);
	free_engine(d);
	if (d->win.ptr)
		mlx_destroy_window(d->mlx, d->win.ptr);
	if (d->mlx)
	{
		mlx_destroy_display(d->mlx);
		free(d->mlx);
	}
}
