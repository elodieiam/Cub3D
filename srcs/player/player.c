/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:36:46 by niromano          #+#    #+#             */
/*   Updated: 2024/01/25 11:34:10 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	player(t_mlx *mlx, t_player *player)
{
	int	x;
	int	y;
	int	i;

	x = player->x * CASE_LEN;
	y = player->y * CASE_LEN;
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

void	player_move(t_player *player)
{
	if (player->keys.w == 0 && player->y > 0.1)
		player->y -= SPEED;
	if (player->keys.s == 0 && player->y < (SCREEN_Y / 30) - 0.1)
		player->y += SPEED;
	if (player->keys.a == 0 && player->x > 0.1)
		player->x -= SPEED;
	if (player->keys.d == 0 && player->x < (SCREEN_X / 30) + 0.6)
		player->x += SPEED;
}
