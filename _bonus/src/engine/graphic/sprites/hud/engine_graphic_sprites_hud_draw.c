/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_graphic_sprites_hud_draw.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:18:43 by juperez           #+#    #+#             */
/*   Updated: 2025/05/04 03:52:39 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ammo(t_helem *e, t_weapon *weapon, t_image *frame)
{
	int	clip;
	int	dammo;
	int	iammo;

	clip = weapon->clip;
	dammo = 0;
	iammo = 0;
	if (weapon->ammo > 0)
	{
		dammo = weapon->ammo / 10;
		iammo = weapon->ammo % 10;
	}
	draw_ehud(&e[HUD_AMMO].imgs[0], frame,
		(t_vecf2){0.9f, 0.9f}, (t_vecf2){1.0f, 0.01f});
	draw_ehud(&e[HUD_DA].imgs[clip], frame,
		(t_vecf2){0.885f, 0.89f}, (t_vecf2){1.0f, 0.0008f});
	draw_ehud(&e[HUD_DA].imgs[dammo], frame,
		(t_vecf2){0.910f, 0.895f}, (t_vecf2){1.0f, 0.0004f});
	draw_ehud(&e[HUD_DA].imgs[iammo], frame,
		(t_vecf2){0.924f, 0.895f}, (t_vecf2){1.0f, 0.0004f});
}

static void	draw_money(t_helem *e, t_player *player, t_image *frame)
{
	int	hmoney;
	int	dmoney;
	int	imoney;

	if (player->money <= 0)
		draw_ehud(&e[HUD_DM].imgs[0], frame,
			(t_vecf2){0.14f, 0.864f}, (t_vecf2){1.0f, 0.00008f});
	else
	{
		hmoney = player->money / 100;
		dmoney = (player->money / 10) % 10;
		imoney = player->money % 10;
		if (hmoney)
			draw_ehud(&e[HUD_DM].imgs[hmoney], frame,
				(t_vecf2){0.128f, 0.864f}, (t_vecf2){1.0f, 0.00008f});
		if (hmoney || dmoney)
			draw_ehud(&e[HUD_DM].imgs[dmoney], frame,
				(t_vecf2){0.134f, 0.864f}, (t_vecf2){1.0f, 0.00008f});
		draw_ehud(&e[HUD_DM].imgs[imoney], frame,
			(t_vecf2){0.14f, 0.864f}, (t_vecf2){1.0f, 0.00008f});
	}
}

static void	draw_health_bar(t_helem *e, t_player *player, t_image *frame)
{
	float	fill;

	if (player->health <= 0)
		return ;
	fill = (float)player->health / (float)PLAYER_MAX_HEALTH;
	draw_ehud(&e[HUD_STATUS].imgs[1], frame,
		(t_vecf2){0.1f, 0.9f}, (t_vecf2){fill, 0.01f});
}

static void	draw_stamina_bar(t_helem *e, t_player *player, t_image *frame)
{
	float	fill;

	if (player->stamina <= 0)
		return ;
	fill = (float)player->stamina / (float)PLAYER_MAX_STAMINA;
	draw_ehud(&e[HUD_STATUS].imgs[2], frame,
		(t_vecf2){0.1f, 0.9f}, (t_vecf2){fill, 0.01f});
}

void	draw_sprite_hud(t_data *d, t_player *player)
{
	t_helem	*e;
	t_image	*frame;

	e = d->engine.graphic.sprites.hud.elems;
	frame = &d->engine.graphic.frame;
	draw_ammo(e, &player->weapon, frame);
	draw_ehud(&e[HUD_STATUS].imgs[0], frame,
		(t_vecf2){0.1f, 0.9f}, (t_vecf2){1.0f, 0.01f});
	draw_money(e, player, frame);
	draw_health_bar(e, player, frame);
	draw_stamina_bar(e, player, frame);
}
