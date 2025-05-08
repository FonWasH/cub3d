/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:02:39 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 03:37:11 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_engine(t_data *d)
{
	free_threads(&d->engine.threads);
	free_audio(&d->engine.audio);
	free_graphic(d);
}
