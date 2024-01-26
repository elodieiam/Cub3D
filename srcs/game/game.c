/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:13:29 by niromano          #+#    #+#             */
/*   Updated: 2024/01/26 14:38:33 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	background(t_mlx *mlx, t_data *data)
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
				my_mlx_pixel_put(&mlx->img_buf, x, y, data->textures.color_f);
			else
				my_mlx_pixel_put(&mlx->img_buf, x, y, data->textures.color_c);
			y ++;
		}
		x ++;
	}
}

int	game_cub(t_game *game)
{
	background(&game->mlx, &game->data);
	map(&game->mlx, game->data.map);
	player(&game->mlx, &game->player);
	player_move(&game->player, game->data.map, game->data.map_x, game->data.map_y);
	// minimap(mlx);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win, game->mlx.img_buf.img, 0, 0);
	return (0);
}
