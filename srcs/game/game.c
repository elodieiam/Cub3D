/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:13:29 by niromano          #+#    #+#             */
/*   Updated: 2024/01/23 10:40:39 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	background(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x != SCREEN_X)
	{
		y = 0;
		while (y != SCREEN_Y)
		{
			if (y < SCREEN_Y / 2)
				my_mlx_pixel_put(&mlx->buffer, x, y, mlx->data->raw.texture_f);
			else
				my_mlx_pixel_put(&mlx->buffer, x, y, mlx->data->raw.texture_c);
			y ++;
		}
		x ++;
	}
}

int	game(t_mlx *mlx)
{
	background(mlx);
	map(mlx);
	player(mlx);
	player_move(mlx);
	// minimap(mlx);
	mlx->line_coord[0] = 100;
	mlx->line_coord[1] = 100;
	mlx->line_coord[2] = 1200;
	mlx->line_coord[3] = 600;
	put_line(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->buffer.img, 0, 0);
	return (0);
}
