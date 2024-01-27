/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:36:46 by niromano          #+#    #+#             */
/*   Updated: 2024/01/27 13:54:22 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	icon_player(t_mlx *mlx, t_player *player, int x, int y)
{
	mlx->put_line_coord.sx = x + (int)(sin_pov(player) * (L_BOX / 4));
	mlx->put_line_coord.sy = y - (int)(cos_pov(player) * (L_BOX / 4));
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

int	collision(t_player *player, char **map, int map_x, int map_y)
{
	(void)player;
	(void)map;
	(void)map_x;
	(void)map_y;
	// printf("%f %f\n", (sin_pov(player) * SPEED), (cos_pov(player) * SPEED));
	if (map[map_y - 1][map_x - 1])
	{
		
	}
	return (0);
}

void	player_move(t_mlx *mlx, t_player *player, char **map)
{
	if (player->keys.w == 0)
	{
		if (player->x + (sin_pov(player) * SPEED) < ft_strlen(map[0]) && player->x + (sin_pov(player) * SPEED) > 0)
			player->x += (sin_pov(player) * SPEED);
		if (player->y - (cos_pov(player) * SPEED) < ft_strlen_mat(map) && player->y - (cos_pov(player) * SPEED) > 0)
			player->y -= (cos_pov(player) * SPEED);
	}
	if (player->keys.s == 0)
	{
		if (player->x - (sin_pov(player) * SPEED) < ft_strlen(map[0]) && player->x - (sin_pov(player) * SPEED) > 0)
			player->x -= (sin_pov(player) * SPEED);
		if (player->y + (cos_pov(player) * SPEED) < ft_strlen_mat(map) && player->y + (cos_pov(player) * SPEED) > 0)
			player->y += (cos_pov(player) * SPEED);
	}
	if (player->keys.a == 0)
	{
		if (player->x - (cos_pov(player) * SPEED) < ft_strlen(map[0]) && player->x - (cos_pov(player) * SPEED) > 0)
			player->x -= (cos_pov(player) * SPEED);
		if (player->y - (sin_pov(player) * SPEED) < ft_strlen_mat(map) && player->y - (sin_pov(player) * SPEED) > 0)
			player->y -= (sin_pov(player) * SPEED);
	}
	if (player->keys.d == 0)
	{
		if (player->x + (cos_pov(player) * SPEED) < ft_strlen(map[0]) && player->x + (cos_pov(player) * SPEED) > 0)
			player->x += (cos_pov(player) * SPEED);
		if (player->y + (sin_pov(player) * SPEED) < ft_strlen_mat(map) && player->y + (sin_pov(player) * SPEED) > 0)
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
