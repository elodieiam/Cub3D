/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:36:46 by niromano          #+#    #+#             */
/*   Updated: 2024/01/25 17:24:17 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	icon_player(t_mlx *mlx, t_player *player, int x, int y)
{
	if (player->pov >= 0 && player->pov < 90)
	{
		mlx->put_line_coord.ex = x + (int)((sinf(player->pov * (PI/180))) * 10);
		mlx->put_line_coord.ey = y - (int)((cosf(player->pov * (PI/180))) * 10);
		put_line(mlx, 0xFFF000);
	}
	else if (player->pov >= 90 && player->pov < 180)
	{
		mlx->put_line_coord.ex = x + (int)((sinf(player->pov * (PI/180))) * 10);
		mlx->put_line_coord.ey = y - (int)((cosf(player->pov * (PI/180))) * 10);
	}
	else if (player->pov >= 180 && player->pov < 270)
	{
		mlx->put_line_coord.ex = x + (int)((sinf(player->pov * (PI/180))) * 10);
		mlx->put_line_coord.ey = y - (int)((cosf(player->pov * (PI/180))) * 10);
	}
	else if (player->pov >= 270 && player->pov < 360)
	{
		mlx->put_line_coord.ex = x + (int)((sinf(player->pov * (PI/180))) * 10);
		mlx->put_line_coord.ey = y - (int)((cosf(player->pov * (PI/180))) * 10);
	}
}

void	player(t_mlx *mlx, t_player *player)
{
	int	x;
	int	y;

	x = player->x * CASE_LEN;
	y = player->y * CASE_LEN;
	mlx->put_line_coord.sx = x;
	mlx->put_line_coord.sy = y;
	mlx->put_line_coord.ex = x + (int)((sinf(player->pov * (PI/180))) * 15);
	mlx->put_line_coord.ey = y - (int)((cosf(player->pov * (PI/180))) * 15);
	put_line(mlx, 0xFFF000);
}

void	player_move(t_player *player)
{
	if (player->keys.w == 0 && player->y > 0.1)
		player->y -= SPEED;
	if (player->keys.s == 0)
		player->y += SPEED;
	if (player->keys.a == 0 && player->x > 0.1)
		player->x -= SPEED;
	if (player->keys.d == 0)
		player->x += SPEED;
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
