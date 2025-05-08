/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 05:20:18 by juperez           #+#    #+#             */
/*   Updated: 2025/04/07 09:07:00 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_error(char *error, char *extra)
{
	printf("%s%s: %s", ERROR, NAME, error);
	if (extra)
		printf(": %s", extra);
	printf("\n");
}

void	error(t_data *d, char *error, char *extra)
{
	if (error)
		put_error(error, extra);
	if (d)
		free_core(d);
	exit(EXIT_FAILURE);
}
