/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:02:21 by juperez           #+#    #+#             */
/*   Updated: 2025/05/05 04:46:36 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MAP_H
# define GAME_MAP_H

# define SCENE_PATH				"../resources/bonus_scene.cub"
# define MAP_SIZE_X				32
# define MAP_SIZE_Y				31
# define MAP_MAX_TYPE			6
# define MAP_MAX_TEXTURE_TYPE	37
# define MAP_MAX_TEXTURE_ANIM	7
# define MAP_MAX_FRAMECOUNT		3

//512	//256	//128	//64	//32
# define TEXTURE_SIZE			256
//9		//8		//7		//6		//5
# define TEXTURE_SIZE_LOG2		8

# define SHOP_MAX_FRAMECOUNT	120
# define MAP_MEDKIT_PRICE		200
# define MAP_AMMO_PRICE			150

typedef enum e_emap_shop
{
	AMMO = 0,
	MEDKIT = 3
}	t_emap_shop;

typedef enum e_emap_type
{
	FLOOR,
	WALL,
	SHOP,
	PDOOR,
	EDOOR,
	NONE
}	t_emap_type;

typedef enum e_collision
{
	BLOCK_NONE,
	BLOCK_PLAYER,
	BLOCK_ENEMY,
	BLOCK_RAY
}	t_collision;

// TF = TEXTURE FLOOR
// TC = TEXTURE CEILING
// TW = TEXTURE WALL
// TS = TEXTURE SHOP
// TP = TEXTURE PLAYER DOOR
// TE = TEXTURE ENEMY DOOR

typedef enum e_itex
{
	TF,
	TC,
	TW,
	TS,
	TP,
	TE
}	t_itex;

typedef struct s_emap
{
	t_emap_type	type;
	int			itex;
	t_collision	collision;
	int			fcount;
}				t_emap;

typedef struct s_map
{
	t_emap	elem[MAP_SIZE_X][MAP_SIZE_Y];
	t_image	tex[MAP_MAX_TYPE][MAP_MAX_TEXTURE_TYPE];
}			t_map;

void	init_map(t_data *d, t_map *map);
void	free_map(t_map *map, void *mlx_ptr);
void	*load_map(void *arg);
void	loop_map(t_data *d);

void	check_map_interact(t_data *d, t_vec2 pos, t_map *map, t_player *player);
void	open_pdoor(t_data *d, t_emap *elem);
void	update_pdoor_anim(t_emap *elem);
void	buy_shop(t_data *d, t_emap *elem, t_player *player);
void	update_shop_anim(t_emap *elem);

#endif
