/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:34:50 by niromano          #+#    #+#             */
/*   Updated: 2024/02/28 15:55:31 by niromano         ###   ########.fr       */
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
// 		// put_line(&game->mlx, &game->mlx.img_map, 0xFF0000);
// 		draw_ray(game, (j - (game->player.pov + 90 - FOV / 2)) * 8);
// 		j ++;
// 	}
// }

void	cub3d(t_game *game)
{
	double	x_pos;
	double	y_pos;
	double	x_dir = -1;
	double	y_dir = 0;
	double	x_plane = 0;
	double	y_plane = 0.66;
	double	x_raydir;
	double	y_raydir;
	double camera_x;
	int		w = SCREEN_X;
	int		x_map;
	int		y_map;
	double	x_sidedist;
	double	y_sidedist;
	double	x_deltadist;
	double	y_deltadist;
	double	perpwalldist;
	int		x_step;
	int		y_step;
	int		hit;
	int		side;

	x_pos = game->player.y;
	y_pos = game->player.x;
	x_map = (int)game->player.y;
	y_map = (int)game->player.x;
	for(int x = 0; x < w; x++)
	{
		hit = 0;
		camera_x = 2 * x / (double)w - 1;
		x_raydir = x_dir + x_plane * camera_x;
		y_raydir = y_dir + y_plane * camera_x;
		if (x_raydir == 0)
			x_deltadist = pow(10, 30);
		else
			x_deltadist = fabs(1 / x_raydir);
		if (y_raydir == 0)
			y_deltadist = pow(10, 30);
		else
			y_deltadist = fabs(1 / y_raydir);
		if (x_raydir < 0)
		{
			x_step = -1;
			x_sidedist = (x_pos - x_map) * x_deltadist;
		}
		else
		{
			x_step = 1;
			x_sidedist = (x_map + 1.0 - x_pos) * x_deltadist;
		}
		if (y_raydir < 0)
		{
			y_step = -1;
			y_sidedist = (y_pos - y_map) * y_deltadist;
		}
		else
		{
			y_step = 1;
			y_sidedist = (y_map + 1.0 - y_pos) * y_deltadist;
		}
		while (hit == 0)
		{
			if (x_sidedist < y_sidedist)
			{
				x_sidedist += x_deltadist;
				x_map += x_step;
				side = 0;
			}
			else
			{
				y_sidedist += y_deltadist;
				y_map += y_step;
				side = 1;
			}
			// printf("%d / %d\n", x_map, y_map);
			if (x_map < 0)
				x_map = 0;
			if (x_map >= game->data.map_y)
				x_map = game->data.map_y - 1;
			if (y_map < 0)
				y_map = 0;
			if (y_map >= game->data.map_x)
				y_map = game->data.map_x - 1;
			if (game->data.map[x_map][y_map] == '1')
				hit = 1;
		}
		if(side == 0)
			perpwalldist = (x_sidedist - x_deltadist);
		else
			perpwalldist = (y_sidedist - y_deltadist);
		int	h = SCREEN_Y;
		int lineHeight = (int)(h / perpwalldist);
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h)
			drawEnd = h - 1;
		game->mlx.put_line_coord.sx = x;
		game->mlx.put_line_coord.sy = drawStart;
		game->mlx.put_line_coord.ex = x;
		game->mlx.put_line_coord.ey = drawEnd;
		// printf("x %f / y %f\n", x_dir, y_dir);
		// printf("%f = %f\n", x_raydir, y_raydir);
		// printf("      %f = %f\n", x_sidedist, x_deltadist);
		// printf("      %f = %f\n", y_sidedist, y_deltadist);
		// printf("%d = %f\n", lineHeight, perpwalldist);
		// printf("%f / %f\n", game->mlx.put_line_coord.sx, game->mlx.put_line_coord.sy);
		// printf("%f / %f\n", game->mlx.put_line_coord.ex, game->mlx.put_line_coord.ey);
		// printf("side = %d\n\n", side);
		if (side == 0)
			put_line(&game->mlx, &game->mlx.img_buf, 0xFFF000);
		else
			put_line(&game->mlx, &game->mlx.img_buf, 0xFF0000);
	}
}
