/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:53:30 by juperez           #+#    #+#             */
/*   Updated: 2025/05/01 18:37:16 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_path_cub_file(char *av)
{
	char	*ext;

	ext = ft_strrchr(av, '.');
	if (!ext || ft_strncmp(ext, ".cub", 4) || ft_strlen(ext) > 4)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_data	d;

	if (ac != 2 || !is_path_cub_file(av[1]))
		error(NULL, USAGE, NULL);
	init_core(&d, av[1]);
	hook_core(&d);
	return (EXIT_SUCCESS);
}
