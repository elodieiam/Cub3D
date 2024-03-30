/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigonometry_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:59:18 by niromano          #+#    #+#             */
/*   Updated: 2024/03/30 17:33:46 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

float	cos_pov(t_player *player)
{
	return (cosf(player->pov * (PI / 180)));
}

float	sin_pov(t_player *player)
{
	return (sinf(player->pov * (PI / 180)));
}

void	atan_pov(t_player *player, t_raycast *rc)
{
	player->pov = atan2(rc->dir_x, rc->dir_y) * 180 / PI;
	player->pov += 90;
	if (player->pov < 0)
		player->pov += 360;
}
