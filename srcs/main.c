/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:19:42 by niromano          #+#    #+#             */
/*   Updated: 2024/01/22 14:25:55 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_hook(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		clear_all_success(mlx);
	else if (key == 'w')
		mlx->hook[0] = 0;
	else if (key == 's')
		mlx->hook[1] = 0;
	else if (key == 'a')
		mlx->hook[2] = 0;
	else if (key == 'd')
		mlx->hook[3] = 0;
	else if (key == XK_Left)
		mlx->hook[4] = 0;
	else if (key == XK_Right)
		mlx->hook[5] = 0;
	return (0);
}

int	input(int key, t_mlx *mlx)
{
	if (key == 'w')
		mlx->hook[0] = 1;
	else if (key == 's')
		mlx->hook[1] = 1;
	else if (key == 'a')
		mlx->hook[2] = 1;
	else if (key == 'd')
		mlx->hook[3] = 1;
	else if (key == XK_Left)
		mlx->hook[4] = 1;
	else if (key == XK_Right)
		mlx->hook[5] = 1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	set_mlx_null(&mlx);
	mlx.data = malloc(sizeof(t_data));
	if (mlx.data == NULL)
	{
		ft_putstr_fd("Error\nMalloc Failed !\n", 2);
		exit(EXIT_FAILURE);
	}
	mlx.timer = 0;
	parsing(argc, argv, &mlx);
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		clear_all_failed(&mlx, "Init of MLX failed\n");
	mlx.win = mlx_new_window(mlx.mlx, SCREEN_X, SCREEN_Y, "Cub3D");
	if (mlx.win == NULL)
		clear_all_failed(&mlx, "Creation of window failed\n");
	mlx.buffer.img = mlx_new_image(mlx.mlx, SCREEN_X, SCREEN_Y);
	mlx.buffer.addr = mlx_get_data_addr(mlx.buffer.img, &mlx.buffer.bits_per_pixel, &mlx.buffer.line_length, &mlx.buffer.endian);
	set_textures(&mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, get_hook, &mlx);
	mlx_hook(mlx.win, KeyRelease, KeyReleaseMask, input, &mlx);
	mlx_hook(mlx.win, 17, 0, clear_all_success, &mlx);
	mlx_loop_hook(mlx.mlx, game, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
