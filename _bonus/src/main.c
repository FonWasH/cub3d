/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:53:30 by juperez           #+#    #+#             */
/*   Updated: 2025/05/06 12:41:32 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	d;

	(void)av;
	if (ac > 1)
		error(NULL, USAGE, NULL);
	init_core(&d);
	hook_core(&d);
	return (EXIT_SUCCESS);
}
