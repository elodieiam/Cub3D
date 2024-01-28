/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:13:29 by niromano          #+#    #+#             */
/*   Updated: 2024/01/27 17:35:54 by niromano         ###   ########.fr       */
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

void	mouse(t_mlx *mlx, t_player *player)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(mlx->mlx_ptr, mlx->win, &x, &y);
	if (x == 0)
		x = 360;
	while (x > 360)
		x -= 360;
	player->pov = x;
	mlx_mouse_move(mlx->mlx_ptr, mlx->win, player->pov, 0);
}

int	game_cub(t_game *game)
{
	background(&game->mlx, &game->data);
	map(&game->mlx, game->data.map);
	player(&game->mlx, &game->player);
	player_move(&game->mlx, &game->data, &game->player);
	mouse(&game->mlx, &game->player);
	// minimap(mlx);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win, game->mlx.img_buf.img, 0, 0);
	return (0);
}
