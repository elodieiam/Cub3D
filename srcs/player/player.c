/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:36:46 by niromano          #+#    #+#             */
/*   Updated: 2024/01/24 12:56:30 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	player(t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;

	x = mlx->player.x * CASE_LEN;
	y = mlx->player.y * CASE_LEN;
	i = -7;
	while (i != 8)
	{
		mlx->put_line_coord.sx = x;
		mlx->put_line_coord.sy = y - 10;
		mlx->put_line_coord.ex = x + i;
		mlx->put_line_coord.ey = y + 10;
		put_line(mlx, 0xFFF000);
		i ++;
	}
}

void	player_move(t_mlx *mlx)
{
	if (mlx->player.keys.w == 0 && mlx->player.y > 0.1)
		mlx->player.y -= SPEED;
	if (mlx->player.keys.s == 0 && mlx->player.y < (SCREEN_Y / 30) - 0.1)
		mlx->player.y += SPEED;
	if (mlx->player.keys.a == 0 && mlx->player.x > 0.1)
		mlx->player.x -= SPEED;
	if (mlx->player.keys.d == 0 && mlx->player.x < (SCREEN_X / 30) + 0.6)
		mlx->player.x += SPEED;
}
