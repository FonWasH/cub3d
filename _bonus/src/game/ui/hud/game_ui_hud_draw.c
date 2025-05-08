/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ui_hud_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:44:09 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 23:58:19 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_args(t_ehud *e, t_image *src, t_image *dst)
{
	e->src = src;
	e->dst = dst;
	e->offset.x = 0;
	e->offset.y = 0;
	e->draw_size.x = 0;
	e->draw_size.y = 0;
}

static void	calc_hud_size(t_ehud *e, t_vecf2 pos, float ratio)
{
	float	dst_area;
	float	target_area;
	float	src_ratio;

	dst_area = e->dst->size.x * e->dst->size.y;
	target_area = ratio * dst_area;
	src_ratio = (float)e->src->size.x / (float)e->src->size.y;
	e->draw_size.x = sqrtf(target_area * src_ratio);
	e->draw_size.y = e->draw_size.x / src_ratio;
	e->offset.x = (int)(pos.x * e->dst->size.x - e->draw_size.x / 2);
	e->offset.y = (int)(pos.y * e->dst->size.y - e->draw_size.y / 2);
}

static void	draw_hud_pixel(t_ehud *e, t_vec2 i)
{
	t_vec2		src_pos;
	t_vec2		dst_pos;
	uint32_t	color;

	src_pos.x = i.x * e->src->size.x / e->draw_size.x;
	src_pos.y = i.y * e->src->size.y / e->draw_size.y;
	dst_pos.x = e->offset.x + i.x;
	dst_pos.y = e->offset.y + i.y;
	if (dst_pos.x >= 0 && dst_pos.x < e->dst->size.x
		&& dst_pos.y >= 0 && dst_pos.y < e->dst->size.y)
	{
		color = e->src->data[src_pos.y * e->src->size.x + src_pos.x];
		if ((color >> 24) != 0xFF)
			e->dst->data[dst_pos.y * e->dst->size.x + dst_pos.x] = color;
	}
}

void	draw_ehud(t_image *src, t_image *dst,
	t_vecf2 pos, t_vecf2 ratio)
{
	t_ehud	e;
	t_vec2	i;
	int		end;

	init_args(&e, src, dst);
	calc_hud_size(&e, pos, ratio.y);
	i.y = 0;
	end = (int)(e.draw_size.x * ratio.x);
	while (i.y < e.draw_size.y)
	{
		i.x = 0;
		while (i.x < end)
		{
			draw_hud_pixel(&e, i);
			i.x++;
		}
		i.y++;
	}
}
