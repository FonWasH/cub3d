/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_enemy_draw.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:50:59 by juperez           #+#    #+#             */
/*   Updated: 2025/04/29 13:44:03 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine_graphic_sprites_arg.h"

static void	init_arg(t_data *d, t_sprites_arg *s)
{
	s->anims = d->engine.graphic.sprites.enemy.anims;
	s->enemies = d->game.entities.enemies.list;
	s->enemies_count = (int)ft_lstsize(s->enemies);
	s->w = d->win.size.x;
	s->h = d->win.size.y;
	s->half_h = d->win.half_h;
	s->zbuffer = d->engine.graphic.zbuffer;
	s->fog = d->engine.graphic.fog;
	s->framebuffer = d->engine.graphic.frame.data;
}

static void	calc_range(t_sprites_arg *s, int start, int end)
{
	int	start_y;
	int	end_y;
	int	sprite_height;

	s->start.x = -(s->enemy->r.w >> 1) + s->enemy->r.screen_x;
	s->end.x = (s->enemy->r.w >> 1) + s->enemy->r.screen_x;
	if (s->start.x < start)
		s->start.x = start;
	if (s->end.x >= end)
		s->end.x = end;
	s->start.y = -(s->enemy->r.h >> 1) + s->half_h + s->enemy->r.h_offset;
	s->end.y = (s->enemy->r.h >> 1) + s->half_h + s->enemy->r.h_offset;
	start_y = s->start.y;
	end_y = s->end.y;
	sprite_height = end_y - start_y;
	if (s->start.y < 0)
		s->start.y = 0;
	if (s->end.y >= s->h)
		s->end.y = s->h - 1;
	s->ratio_start = 0.0f;
	s->ratio_end = 1.0f;
	if (start_y < 0)
		s->ratio_start = (float)(-start_y) / sprite_height;
	if (end_y >= s->h)
		s->ratio_end = (float)(s->h - start_y) / sprite_height;
}

static void	put_pixel(t_sprites_arg *s, t_vec2 i)
{
	float		next;
	uint32_t	color;

	next = (float)(i.y - s->start.y) / (s->end.y - s->start.y);
	next = s->ratio_start + next * (s->ratio_end - s->ratio_start);
	s->tpos.y = (int)(next * s->sprite.size.y);
	if (s->tpos.x < 0 || s->tpos.x >= s->sprite.size.x
		|| s->tpos.y < 0 || s->tpos.y >= s->sprite.size.y)
		return ;
	color = s->sprite.data[s->tpos.y * s->sprite.size.x + s->tpos.x];
	if ((color >> 24) != 0)
		return ;
	apply_fog(&s->fog, &color, s->enemy->r.tran.y);
	if (i.y >= 0 && i.y < s->h && i.x >= 0 && i.x < s->w)
	{
		s->framebuffer[i.y * s->w + i.x] = color;
		s->zbuffer[i.x][i.y] = s->enemy->r.tran.y;
	}
}

static void	draw_enemy(t_sprites_arg *s)
{
	t_vec2	i;

	i.x = s->start.x;
	while (i.x < s->end.x)
	{
		s->tpos.x = (int)((i.x - (-(s->enemy->r.w >> 1) + s->enemy->r.screen_x))
				* s->sprite.size.x / s->enemy->r.w);
		if (i.x >= 0 && i.x < s->w && s->enemy->r.tran.y > 0)
		{
			i.y = s->start.y;
			while (i.y < s->end.y)
			{
				if (s->enemy->r.tran.y < s->zbuffer[i.x][i.y])
					put_pixel(s, i);
				i.y++;
			}
		}
		i.x++;
	}
}

void	*draw_sprites_enemies(void *arg)
{
	t_task_arg		*task;
	t_data			*d;
	t_sprites_arg	s;
	int				i;

	task = (t_task_arg *)arg;
	d = task->d;
	init_arg(d, &s);
	i = 0;
	while (i < s.enemies_count)
	{
		s.enemy = get_enemy(s.enemies, i);
		if (s.enemy && s.enemy->r.tran.y > 0.01f
			&& s.enemy->r.h > 0 && s.enemy->r.w > 0)
		{
			s.sprite = s.anims[s.enemy->state].img[
				s.enemy->r.iframe][s.enemy->r.idir];
			calc_range(&s, task->start, task->end);
			draw_enemy(&s);
		}
		i++;
	}
	return (free(task), NULL);
}
