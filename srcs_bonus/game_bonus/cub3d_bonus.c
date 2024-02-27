/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:34:50 by niromano          #+#    #+#             */
/*   Updated: 2024/02/27 16:44:56 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	calcul_distance(t_mlx *mlx)
{
	int	dist;

	dist = sqrt((pow(mlx->put_line_coord.sx - mlx->put_line_coord.ex, 2))
			+ (pow(mlx->put_line_coord.sy - mlx->put_line_coord.ey, 2)));
	return (dist);
}

// void	draw_ray(t_game *game, int j)
// {
// 	int	len;
// 	int	start;
// 	int	end;
// 	int	h;
// 	int	i;

// 	h = SCREEN_Y;
// 	len = h / calcul_distance(&game->mlx) * 8;
// 	start = -len / 2 + h / 2;
// 	end = len / 2 + h / 2;
// 	i = 0;
// 	while (i != 8)
// 	{
// 		game->mlx.put_line_coord.sx = j + i;
// 		game->mlx.put_line_coord.sy = start;
// 		game->mlx.put_line_coord.ex = j + i;
// 		game->mlx.put_line_coord.ey = end;
// 		put_line(&game->mlx, &game->mlx.img_buf, 0xFF0000);
// 		i ++;
// 	}
// }

// void	cub3d(t_game *game)
// {
// 	float	i;
// 	int		j;

// 	j = game->player.pov + 90 - FOV / 2;
// 	while (j != game->player.pov + 90 + FOV / 2)
// 	{
// 		i = 1;
// 		game->mlx.put_line_coord.sx = (int)(game->player.x * L_BOX - (int)(cos_pov(&game->player)));
// 		game->mlx.put_line_coord.sy = (int)(game->player.y * L_BOX - (int)(sin_pov(&game->player)));
// 		game->mlx.put_line_coord.ex = (int)(game->player.x * L_BOX + (int)(sin_pov(&game->player) * i) - (int)(cosf(j * (RAD)) * i));
// 		game->mlx.put_line_coord.ey = (int)(game->player.y * L_BOX - (int)(cos_pov(&game->player) * i) - (int)(sinf(j * (RAD)) * i));
// 		while (((int)game->mlx.put_line_coord.ey / L_BOX) < game->data.map_y - 1
// 			&& ((int)game->mlx.put_line_coord.ex / L_BOX) < game->data.map_x - 1
// 			&& ((int)game->mlx.put_line_coord.ey / L_BOX) > 0
// 			&& ((int)game->mlx.put_line_coord.ex / L_BOX) > 0
// 			&& game->data.map[(int)game->mlx.put_line_coord.ey / L_BOX][(int)game->mlx.put_line_coord.ex / L_BOX] != '1')
// 		{
// 			game->mlx.put_line_coord.ex = (int)(game->player.x * L_BOX + (int)(sin_pov(&game->player) * i) - (int)(cosf(j * (RAD)) * i));
// 			game->mlx.put_line_coord.ey = (int)(game->player.y * L_BOX - (int)(cos_pov(&game->player) * i) - (int)(sinf(j * (RAD)) * i));
// 			i += 0.1;
// 		}
// 		put_line(&game->mlx, &game->mlx.img_map, 0xFF0000);
// 		// draw_ray(game, (j - (game->player.pov + 90 - FOV / 2)) * 8);
// 		j ++;
// 	}
// }

float	x_axes(t_game *game, int pov, float i)
{
	int		hit;
	int		tmp_x;

	hit = 0;
	tmp_x = (int)game->mlx.put_line_coord.ex / L_BOX;
	while (hit == 0)
	{
		game->mlx.put_line_coord.ex = (int)(game->player.x * L_BOX + (int)(sin_pov(&game->player) * i) - (int)(cosf(pov * (RAD)) * i));
		game->mlx.put_line_coord.ey = (int)(game->player.y * L_BOX - (int)(cos_pov(&game->player) * i) - (int)(sinf(pov * (RAD)) * i));
		i += 0.1;
		if (tmp_x != (int)game->mlx.put_line_coord.ex / L_BOX
			|| (int)game->mlx.put_line_coord.ey / L_BOX == -1
			|| (int)game->mlx.put_line_coord.ey / L_BOX == game->data.map_y)
			hit = 1;
	}
	return (i);
}

void	cub3d(t_game *game)
{
	float	i;
	int		pov;
	int		x_map;
	int		y_map;

	i = 1.5;
	pov = game->player.pov + 90;
	x_map = game->player.x;
	y_map = game->player.y;
	game->mlx.put_line_coord.sx = (int)(game->player.x * L_BOX);
	game->mlx.put_line_coord.sy = (int)(game->player.y * L_BOX);
	game->mlx.put_line_coord.ex = (int)(game->player.x * L_BOX);
	game->mlx.put_line_coord.ey = (int)(game->player.y * L_BOX);
	while (game->data.map[(int)game->mlx.put_line_coord.ey / L_BOX][(int)game->mlx.put_line_coord.ex / L_BOX] != '1')
	{
		i = x_axes(game, pov, i);
		if ((int)game->mlx.put_line_coord.ey / L_BOX == -1
			|| (int)game->mlx.put_line_coord.ey / L_BOX == game->data.map_y)
			break ;
	}
	put_line(&game->mlx, &game->mlx.img_map, 0xFFF000);
}
