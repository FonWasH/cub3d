/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_screen_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:17:37 by juperez           #+#    #+#             */
/*   Updated: 2025/05/02 16:09:28 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_screen(t_screen *screen)
{
	screen->complete.ptr = NULL;
	screen->complete.data = NULL;
	screen->gameover.ptr = NULL;
	screen->gameover.data = NULL;
	screen->loading.ptr = NULL;
	screen->loading.data = NULL;
	screen->pause.ptr = NULL;
	screen->pause.data = NULL;
}
