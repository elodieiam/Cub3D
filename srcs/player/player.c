/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:36:46 by niromano          #+#    #+#             */
/*   Updated: 2024/01/25 18:34:36 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	icon_player(t_mlx *mlx, t_player *player, int x, int y)
// {
// 	int	i;

// 	i = -8;
// 	mlx->put_line_coord.sx = x + (int)((sinf(player->pov * (PI/180))) * 15);
// 	mlx->put_line_coord.sy = y - (int)((cosf(player->pov * (PI/180))) * 15);
// 	while (i != 9)
// 	{
// 		mlx->put_line_coord.ex = x - (int)((sinf(player->pov * (PI/180))) * 15);
// 		mlx->put_line_coord.ey = y + (int)((cosf(player->pov * (PI/180))) * 15);
// 		put_line(mlx, 0xFFF000);
// 		i ++;
// 	}
// }

void	player(t_mlx *mlx, t_player *player)
{
	int	x;
	int	y;

	x = player->x * CASE_LEN;
	y = player->y * CASE_LEN;
	mlx->put_line_coord.sx = x + (int)((sinf(player->pov * (PI/180))) * 15);
	mlx->put_line_coord.sy = y - (int)((cosf(player->pov * (PI/180))) * 15);
	mlx->put_line_coord.ex = x - (int)((sinf(player->pov * (PI/180))) * 15);
	mlx->put_line_coord.ey = y + (int)((cosf(player->pov * (PI/180))) * 15);
	put_line(mlx, 0xFFF000);
	// icon_player(mlx, player, x, y);
}

void	player_move(t_player *player)
{
	if (player->keys.w == 0 && player->y > 0.1)
	{
		player->x += ((sinf(player->pov * (PI/180))) * SPEED);
		player->y -= ((cosf(player->pov * (PI/180))) * SPEED);
	}
	if (player->keys.s == 0)
	{
		player->x -= ((sinf(player->pov * (PI/180))) * SPEED);
		player->y += ((cosf(player->pov * (PI/180))) * SPEED);
	}
	if (player->keys.a == 0 && player->x > 0.1)
	{
		player->x -= ((cosf(player->pov * (PI/180))) * SPEED);
		player->y -= ((sinf(player->pov * (PI/180))) * SPEED);
	}
	if (player->keys.d == 0)
	{
		player->x += ((cosf(player->pov * (PI/180))) * SPEED);
		player->y += ((sinf(player->pov * (PI/180))) * SPEED);
	}
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
