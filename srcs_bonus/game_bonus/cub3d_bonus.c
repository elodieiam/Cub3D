/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:34:50 by niromano          #+#    #+#             */
/*   Updated: 2024/02/28 16:19:22 by niromano         ###   ########.fr       */
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

void	set_rc_data(t_game *game, t_raycast *rc)
{
	rc->pos_x = game->player.y;
	rc->pos_y = game->player.x;
	rc->map_x = (int)game->player.y;
	rc->map_y = (int)game->player.x;
	rc->dir_x = -1;
	rc->dir_y = 0;
	rc->plane_x = 0;
	rc->plane_y = 0.66;
}

void	cub3d(t_game *game, t_raycast *rc)
{
	int		w = SCREEN_X;
	int		hit;
	int		side;

	set_rc_data(game, rc);
	for(int x = 0; x < w; x++)
	{
		hit = 0;
		rc->camera_x = 2 * x / (double)w - 1;
		rc->raydir_x = rc->dir_x + rc->plane_x * rc->camera_x;
		rc->raydir_y = rc->dir_y + rc->plane_y * rc->camera_x;
		if (rc->raydir_x == 0)
			rc->deltadist_x = pow(10, 30);
		else
			rc->deltadist_x = fabs(1 / rc->raydir_x);
		if (rc->raydir_y == 0)
			rc->deltadist_y = pow(10, 30);
		else
			rc->deltadist_y = fabs(1 / rc->raydir_y);
		if (rc->raydir_x < 0)
		{
			rc->step_x = -1;
			rc->sidedist_x = (rc->pos_x - rc->map_x) * rc->deltadist_x;
		}
		else
		{
			rc->step_x = 1;
			rc->sidedist_x = (rc->map_x + 1.0 - rc->pos_x) * rc->deltadist_x;
		}
		if (rc->raydir_y < 0)
		{
			rc->step_y = -1;
			rc->sidedist_y = (rc->pos_y - rc->map_y) * rc->deltadist_y;
		}
		else
		{
			rc->step_y = 1;
			rc->sidedist_y = (rc->map_y + 1.0 - rc->pos_y) * rc->deltadist_y;
		}
		while (hit == 0)
		{
			if (rc->sidedist_x < rc->sidedist_y)
			{
				rc->sidedist_x += rc->deltadist_x;
				rc->map_x += rc->step_x;
				side = 0;
			}
			else
			{
				rc->sidedist_y += rc->deltadist_y;
				rc->map_y += rc->step_y;
				side = 1;
			}
			// printf("%d / %d\n", x_map, y_map);
			if (rc->map_x < 0)
				rc->map_x = 0;
			if (rc->map_x >= game->data.map_y)
				rc->map_x = game->data.map_y - 1;
			if (rc->map_y < 0)
				rc->map_y = 0;
			if (rc->map_y >= game->data.map_x)
				rc->map_y = game->data.map_x - 1;
			if (game->data.map[rc->map_x][rc->map_y] == '1')
				hit = 1;
		}
		if(side == 0)
			rc->perpwalldist = (rc->sidedist_x - rc->deltadist_x);
		else
			rc->perpwalldist = (rc->sidedist_y - rc->deltadist_y);
		int	h = SCREEN_Y;
		int lineHeight = (int)(h / rc->perpwalldist);
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
