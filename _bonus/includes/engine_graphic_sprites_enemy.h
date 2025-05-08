/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_enemy.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:23:03 by juperez           #+#    #+#             */
/*   Updated: 2025/05/03 01:57:03 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_GRAPHIC_SPRITES_ENEMY_H
# define ENGINE_GRAPHIC_SPRITES_ENEMY_H

# define ENEMY_MAX_DIRS			8
# define ENEMY_MAX_ANIMS		6
# define ENEMY_MAX_FRAMES		6
# define ENEMY_MAX_FRAMECOUNT	0.5f
# define ENEMY_SCALE			0.6f

typedef struct s_anims
{
	bool		oriented;
	int			frames;
	t_image		img[ENEMY_MAX_FRAMES][ENEMY_MAX_DIRS];
}				t_anims;

typedef struct s_esprites
{
	t_anims		anims[ENEMY_MAX_ANIMS];
}				t_esprites;

void	init_sprites_enemy(t_esprites *enemy);
void	free_sprites_enemy(t_esprites *enemy, void *mlx_ptr);
void	*load_sprites_enemy(void *arg);
void	*draw_sprites_enemies(void *arg);

#endif
