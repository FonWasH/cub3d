/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:02:43 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 03:22:58 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_engine(t_data *d)
{
	init_graphic(d);
	if (!init_threads(&d->engine.threads))
		error(d, ERROR_THD, NULL);
}
