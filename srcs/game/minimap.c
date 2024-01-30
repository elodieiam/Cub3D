/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:13:29 by niromano          #+#    #+#             */
/*   Updated: 2024/01/30 09:27:03 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	base_icon_player(t_mlx *mlx, t_player *player, int x, int y)
{
	mlx->put_line_coord.sx = x - (int)((sin_pov(player) * (L_BOX / 2))
			- (cos_pov(player) * (L_BOX / 4)));
	mlx->put_line_coord.sy = y + (int)((cos_pov(player) * (L_BOX / 2))
			+ (sin_pov(player) * (L_BOX / 4)));
	mlx->put_line_coord.ex = x - (int)((sin_pov(player) * (L_BOX / 2))
			- (cos_pov(player) * (L_BOX / 4 * -1)));
	mlx->put_line_coord.ey = y + (int)((cos_pov(player) * (L_BOX / 2))
			+ (sin_pov(player) * (L_BOX / 4 * -1)));
	put_line(mlx, &mlx->img_map, 0xFFF000);
}

void	icon_player(t_mlx *mlx, t_player *player)
{
	int	x;
	int	y;

	x = player->x * L_BOX;
	y = player->y * L_BOX;
	mlx->put_line_coord.sx = x + (int)(sin_pov(player) * (L_BOX / 2));
	mlx->put_line_coord.sy = y - (int)(cos_pov(player) * (L_BOX / 2));
	mlx->put_line_coord.ex = x - (int)((sin_pov(player) * (L_BOX / 2))
			- (cos_pov(player) * (L_BOX / 4)));
	mlx->put_line_coord.ey = y + (int)((cos_pov(player) * (L_BOX / 2))
			+ (sin_pov(player) * (L_BOX / 4)));
	put_line(mlx, &mlx->img_map, 0xFFF000);
	mlx->put_line_coord.ex = x - (int)((sin_pov(player) * (L_BOX / 2))
			- (cos_pov(player) * (L_BOX / 4 * -1)));
	mlx->put_line_coord.ey = y + (int)((cos_pov(player) * (L_BOX / 2))
			+ (sin_pov(player) * (L_BOX / 4 * -1)));
	put_line(mlx, &mlx->img_map, 0xFFF000);
	base_icon_player(mlx, player, x, y);
}

void	print_cube(t_mlx *mlx, int x, int y, char cube)
{
	int	i;
	int	j;

	i = 0;
	while (i != L_BOX)
	{
		j = 0;
		while (j != L_BOX)
		{
			if (cube == '0' || cube == 'N' || cube == 'S'
				|| cube == 'W' || cube == 'E')
				my_mlx_pixel_put(&mlx->img_map, x + i, y + j, 0x636363);
			else
				my_mlx_pixel_put(&mlx->img_map, x + i, y + j, 0x000000);
			j ++;
		}
		i ++;
	}
}

void	minimap_frame(t_mlx *mlx)
{
	int	i;
	int	j;

	i = SCREEN_X - 171;
	while (i++ < SCREEN_X - 8)
	{
		j = 9;
		while (j ++ < 172)
		{
			if (i == SCREEN_X - 170 || i == SCREEN_X - 8 || j == 10 || j == 172)
				my_mlx_pixel_put(&mlx->img_buf, i, j, 0x010101);
			else
				my_mlx_pixel_put(&mlx->img_buf, i, j, 0x3E3E3E);
		}
	}
}

void	insert_minimap(t_mlx *mlx, t_player *player)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	color;

	x = (player->x * L_BOX) - (L_BOX * 4);
	i = SCREEN_X - 169;
	minimap_frame(mlx);
	while (x < (player->x * L_BOX) + (L_BOX * 4))
	{
		y = (player->y * L_BOX) - (L_BOX * 4);
		j = 11;
		while (y < (player->y * L_BOX) + (L_BOX * 4))
		{
			if (x > 0 && y > 0)
			{
				color = my_mlx_pixel_get(&mlx->img_map, x, y);
				if (color != 0)
					my_mlx_pixel_put(&mlx->img_buf, i, j, color);
			}
			y ++;
			j ++;
		}
		x ++;
		i ++;
	}
}

void	minimap(t_mlx *mlx, t_player *player, char **map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			print_cube(mlx, x, y, map[i][j]);
			j ++;
			x += L_BOX;
		}
		i ++;
		x = 0;
		y += L_BOX;
	}
	icon_player(mlx, player);
	insert_minimap(mlx, player);
}
