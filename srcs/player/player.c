/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:36:46 by niromano          #+#    #+#             */
/*   Updated: 2024/01/28 14:29:26 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	icon_player(t_mlx *mlx, t_player *player, int x, int y)
{
	mlx->put_line_coord.sx = x + (int)(sin_pov(player) * (L_BOX / 2));
	mlx->put_line_coord.sy = y - (int)(cos_pov(player) * (L_BOX / 2));
	mlx->put_line_coord.ex = x - (int)((sin_pov(player) * (L_BOX / 2)) - (cos_pov(player) * (L_BOX / 4)));
	mlx->put_line_coord.ey = y + (int)((cos_pov(player) * (L_BOX / 2)) + (sin_pov(player) * (L_BOX / 4)));
	put_line(mlx, 0xFFF000);
	mlx->put_line_coord.ex = x - (int)((sin_pov(player) * (L_BOX / 2)) - (cos_pov(player) * (L_BOX / 4 * -1)));
	mlx->put_line_coord.ey = y + (int)((cos_pov(player) * (L_BOX / 2)) + (sin_pov(player) * (L_BOX / 4 * -1)));
	put_line(mlx, 0xFFF000);
	mlx->put_line_coord.sx = x - (int)((sin_pov(player) * (L_BOX / 2)) - (cos_pov(player) * (L_BOX / 4)));
	mlx->put_line_coord.sy = y + (int)((cos_pov(player) * (L_BOX / 2)) + (sin_pov(player) * (L_BOX / 4)));
	mlx->put_line_coord.ex = x - (int)((sin_pov(player) * (L_BOX / 2)) - (cos_pov(player) * (L_BOX / 4 * -1)));
	mlx->put_line_coord.ey = y + (int)((cos_pov(player) * (L_BOX / 2)) + (sin_pov(player) * (L_BOX / 4 * -1)));
	put_line(mlx, 0xFFF000);
}

void	player(t_mlx *mlx, t_player *player)
{
	int	x;
	int	y;

	x = player->x * L_BOX;
	y = player->y * L_BOX;
	icon_player(mlx, player, x, y);
}

void	player_move(t_mlx *mlx, t_data *data, t_player *player)
{
	if (player->keys.w == 0)
	{
		if (player->x + (sin_pov(player) * SPEED) < data->map_x && player->x + (sin_pov(player) * SPEED) > 0 && collision(data, player, 'w', 'x') == 0)
			player->x += (sin_pov(player) * SPEED);
		if (player->y - (cos_pov(player) * SPEED) < data->map_y && player->y - (cos_pov(player) * SPEED) > 0 && collision(data, player, 'w', 'y') == 0)
			player->y -= (cos_pov(player) * SPEED);
	}
	if (player->keys.s == 0)
	{
		if (player->x - (sin_pov(player) * SPEED) < data->map_x && player->x - (sin_pov(player) * SPEED) > 0 && collision(data, player, 's', 'x') == 0)
			player->x -= (sin_pov(player) * SPEED);
		if (player->y + (cos_pov(player) * SPEED) < data->map_y && player->y + (cos_pov(player) * SPEED) > 0 && collision(data, player, 's', 'y') == 0)
			player->y += (cos_pov(player) * SPEED);
	}
	if (player->keys.a == 0)
	{
		if (player->x - (cos_pov(player) * SPEED) < data->map_x && player->x - (cos_pov(player) * SPEED) > 0 && collision(data, player, 'a', 'x') == 0)
			player->x -= (cos_pov(player) * SPEED);
		if (player->y - (sin_pov(player) * SPEED) < data->map_y && player->y - (sin_pov(player) * SPEED) > 0 && collision(data, player, 'a', 'y') == 0)
			player->y -= (sin_pov(player) * SPEED);
	}
	if (player->keys.d == 0)
	{
		if (player->x + (cos_pov(player) * SPEED) < data->map_x && player->x + (cos_pov(player) * SPEED) > 0 && collision(data, player, 'd', 'x') == 0)
			player->x += (cos_pov(player) * SPEED);
		if (player->y + (sin_pov(player) * SPEED) < data->map_y && player->y + (sin_pov(player) * SPEED) > 0 && collision(data, player, 'd', 'y') == 0)
			player->y += (sin_pov(player) * SPEED);
	}
	if (player->keys.left == 0)
	{
		if (player->pov == 0)
			player->pov = 360;
		player->pov -= 1;
		mlx_mouse_move(mlx->mlx_ptr, mlx->win, player->pov, 0);
	}
	if (player->keys.right == 0)
	{
		if (player->pov == 360)
			player->pov = 0;
		player->pov += 1;
		mlx_mouse_move(mlx->mlx_ptr, mlx->win, player->pov, 0);
	}
}
