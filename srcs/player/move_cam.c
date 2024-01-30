/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:06:53 by niromano          #+#    #+#             */
/*   Updated: 2024/01/30 13:51:44 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_cam(t_mlx *mlx, t_player *player)
{
	if (player->keys.left == 0)
	{
		if (player->pov == 0)
			player->pov = 360;
		player->pov -= 1;
	}
	if (player->keys.right == 0)
	{
		if (player->pov == 360)
			player->pov = 0;
		player->pov += 1;
	}
}
