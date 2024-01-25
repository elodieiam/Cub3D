/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:19:42 by niromano          #+#    #+#             */
/*   Updated: 2024/01/25 08:33:00 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_hook(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		clear_all_success(mlx);
	else if (key == 'w')
		mlx->player.keys.w = 0;
	else if (key == 's')
		mlx->player.keys.s = 0;
	else if (key == 'a')
		mlx->player.keys.a = 0;
	else if (key == 'd')
		mlx->player.keys.d = 0;
	else if (key == XK_Left)
		mlx->player.keys.left = 0;
	else if (key == XK_Right)
		mlx->player.keys.right = 0;
	return (0);
}

int	input(int key, t_mlx *mlx)
{
	if (key == 'w')
		mlx->player.keys.w = 1;
	else if (key == 's')
		mlx->player.keys.s = 1;
	else if (key == 'a')
		mlx->player.keys.a = 1;
	else if (key == 'd')
		mlx->player.keys.d = 1;
	else if (key == XK_Left)
		mlx->player.keys.left = 1;
	else if (key == XK_Right)
		mlx->player.keys.right = 1;
	return (0);
}

void	set_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		clear_all_failed(mlx, "Init of MLX failed\n");
	mlx->win = mlx_new_window(mlx->mlx, SCREEN_X, SCREEN_Y, "Cub3D");
	if (mlx->win == NULL)
		clear_all_failed(mlx, "Creation of window failed\n");
	mlx->img_buf.img = mlx_new_image(mlx->mlx, SCREEN_X, SCREEN_Y);
	mlx->img_buf.addr = mlx_get_data_addr(mlx->img_buf.img, &mlx->img_buf.bits_per_pixel, &mlx->img_buf.line_length, &mlx->img_buf.endian);
	set_textures(mlx);
}

void	set_game_cub(t_game *game)
{
	mlx_hook(game->mlx.win, KeyPress, KeyPressMask, get_hook, &game->mlx);
	mlx_hook(game->mlx.win, KeyRelease, KeyReleaseMask, input, &game->mlx);
	mlx_hook(game->mlx.win, 17, 0, clear_all_success, &game->mlx);
	mlx_loop_hook(game->mlx.mlx, game_cub, &game->mlx);
	mlx_loop(game->mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	set_game_null(&game);
	parsing(argc, argv, &game.mlx);
	set_mlx(&game.mlx);
	set_game_cub(&game);
	return (0);
}
