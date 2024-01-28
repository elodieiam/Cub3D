/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:13:29 by niromano          #+#    #+#             */
/*   Updated: 2024/01/28 19:57:23 by niromano         ###   ########.fr       */
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
	put_line(mlx, 0xFFF000);
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
	put_line(mlx, 0xFFF000);
	mlx->put_line_coord.ex = x - (int)((sin_pov(player) * (L_BOX / 2))
			- (cos_pov(player) * (L_BOX / 4 * -1)));
	mlx->put_line_coord.ey = y + (int)((cos_pov(player) * (L_BOX / 2))
			+ (sin_pov(player) * (L_BOX / 4 * -1)));
	put_line(mlx, 0xFFF000);
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
				my_mlx_pixel_put(&mlx->img_buf, x + i, y + j, 0x636363);
			else if (cube == '1')
				my_mlx_pixel_put(&mlx->img_buf, x + i, y + j, 0x000000);
			j ++;
		}
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
}
