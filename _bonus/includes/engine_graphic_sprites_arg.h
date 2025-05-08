/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_arg.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 05:09:38 by juperez           #+#    #+#             */
/*   Updated: 2025/04/28 22:37:39 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_SPRITES_ARG_H
# define ENGINE_GRAPHIC_SPRITES_ARG_H

typedef struct s_sprites_arg
{
	t_anims		*anims;
	t_image		sprite;
	t_list		*enemies;
	int			enemies_count;
	t_enemy		*enemy;
	int			w;
	int			h;
	int			half_h;
	float		**zbuffer;
	t_fog		fog;
	uint32_t	*framebuffer;
	t_vec2		start;
	t_vec2		end;
	float		ratio_start;
	float		ratio_end;
	t_vec2		tpos;
}				t_sprites_arg;

#endif
