/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:19:42 by niromano          #+#    #+#             */
/*   Updated: 2024/01/17 08:00:31 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		clear_all_success(mlx);
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
	parsing(argc, argv, &mlx);
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		clear_all_failed(&mlx, "Init of MLX failed\n");
	mlx.win = mlx_new_window(mlx.mlx, 1280, 800, "Cub3D");
	if (mlx.win == NULL)
		clear_all_failed(&mlx, "Creation of window failed\n");
	set_textures(&mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, input, &mlx);
	mlx_hook(mlx.win, 17, 0, clear_all_success, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
