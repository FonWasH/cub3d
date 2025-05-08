/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_minimap_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:19:02 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 18:30:52 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_minimap_dist(t_minimap *minimap)
{
	t_vec2		i;

	i.y = 0;
	while (i.y < MINIMAP_SIZE)
	{
		i.x = 0;
		while (i.x < MINIMAP_SIZE)
		{
			minimap->dist[i.y][i.x] = heu(minimap->center, i);
			i.x++;
		}
		i.y++;
	}
}

static void	calc_player_triangle(t_minimap *minimap, t_triangle *t)
{
	t_vecf2	center;

	center.x = minimap->pos.x + MINIMAP_SIZE / 2.0f;
	center.y = minimap->pos.y + MINIMAP_SIZE / 2.0f;
	t->p[0] = (t_vecf2){center.x, center.y - 6.0f};
	t->p[1] = (t_vecf2){center.x - 6.0f * 0.6f, center.y + 6.0f * 0.6f};
	t->p[2] = (t_vecf2){center.x + 6.0f * 0.6f, center.y + 6.0f * 0.6f};
	t->b_min.x = fminf(t->p[0].x, fminf(t->p[1].x, t->p[2].x));
	t->b_min.y = fminf(t->p[0].y, fminf(t->p[1].y, t->p[2].y));
	t->b_max.x = fmaxf(t->p[0].x, fmaxf(t->p[1].x, t->p[2].x));
	t->b_max.y = fmaxf(t->p[0].y, fmaxf(t->p[1].y, t->p[2].y));
	t->det = (t->p[1].y - t->p[2].y) * (t->p[0].x - t->p[2].x)
		+ (t->p[2].x - t->p[1].x) * (t->p[0].y - t->p[2].y);
}

void	init_minimap(t_minimap *minimap, int width)
{
	int	diameter;

	diameter = MINIMAP_RADIUS * 2;
	minimap->scale.x = MINIMAP_SIZE / (float)diameter;
	minimap->scale.y = MINIMAP_SIZE / (float)diameter;
	minimap->pos.x = width - MINIMAP_SIZE - MINIMAP_POS;
	minimap->pos.y = MINIMAP_POS;
	minimap->center.x = MINIMAP_SIZE >> 1;
	minimap->center.y = MINIMAP_SIZE >> 1;
	calc_minimap_dist(minimap);
	calc_player_triangle(minimap, &minimap->triangle);
}
