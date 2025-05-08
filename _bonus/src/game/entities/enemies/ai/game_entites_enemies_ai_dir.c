/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_entites_enemies_ai_dir.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:02:52 by juperez           #+#    #+#             */
/*   Updated: 2025/04/30 13:30:22 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vecf2	get_dir(t_vecf2 from, t_vecf2 to)
{
	t_vecf2	dir;
	float	length;

	dir.x = to.x - from.x;
	dir.y = to.y - from.y;
	length = magf(dir);
	if (length > 0)
	{
		dir.x /= length;
		dir.y /= length;
	}
	else
	{
		dir.x = 0.0f;
		dir.y = 0.0f;
	}
	return (dir);
}

void	update_dir(t_vecf2 *enemy_dir, t_vecf2 target_dir, float rot_speed)
{
	float	current;
	float	target;
	float	diff;
	float	new;
	float	rot;

	if (target_dir.x == 0.0f && target_dir.y == 0.0f)
		return ;
	current = atan2f(enemy_dir->y, enemy_dir->x);
	target = atan2f(target_dir.y, target_dir.x);
	diff = target - current;
	if (diff > PI)
		diff -= 2 * PI;
	if (diff < -PI)
		diff += 2 * PI;
	rot = fmaxf(-rot_speed, fminf(rot_speed, diff));
	new = current + rot;
	enemy_dir->x = cosf(new);
	enemy_dir->y = sinf(new);
}
