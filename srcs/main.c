/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:19:42 by niromano          #+#    #+#             */
/*   Updated: 2024/01/31 11:57:45 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_mlx(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (game->mlx.mlx_ptr == NULL)
		clear_all_failed(game, "Init of MLX failed\n");
	game->mlx.win = mlx_new_window(game->mlx.mlx_ptr,
			SCREEN_X, SCREEN_Y, "Cub3D");
	if (game->mlx.win == NULL)
		clear_all_failed(game, "Creation of window failed\n");
	game->mlx.img_buf.img = mlx_new_image(game->mlx.mlx_ptr,
			SCREEN_X, SCREEN_Y);
	game->mlx.img_buf.addr = mlx_get_data_addr(game->mlx.img_buf.img,
			&game->mlx.img_buf.bits_per_pixel, &game->mlx.img_buf.line_length,
			&game->mlx.img_buf.endian);
	set_textures(game);
}

void	set_game_cub(t_game *game)
{
	mlx_hook(game->mlx.win, 17, 0, clear_all_success, game);
	mlx_hook(game->mlx.win, KeyPress, KeyPressMask, get_hook, game);
	mlx_hook(game->mlx.win,
		KeyRelease, KeyReleaseMask, let_hook, &game->player);
	mlx_loop_hook(game->mlx.mlx_ptr, game_cub, game);
	mlx_loop(game->mlx.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game	game;

	set_game_null(&game);
	parsing(argc, argv, &game);
	set_mlx(&game);
	set_game_cub(&game);
	return (0);
}
