/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:19:42 by niromano          #+#    #+#             */
/*   Updated: 2024/01/22 11:40:06 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		clear_all_success(mlx);
	return (0);
}

void	affiche_info(t_mlx *mlx)
{
	// printf("North : %p\n", mlx->data->textures.texture_n);
	// printf("South : %p\n", mlx->data->textures.texture_s);
	// printf("West : %p\n", mlx->data->textures.texture_w);
	// printf("East : %p\n", mlx->data->textures.texture_e);
	// printf("Floor : %s\n", mlx->data->textures.texture_f);
	// printf("Ceiling : %s\n", mlx->data->textures.texture_c);
	// printf("\n");
	printf("Player info : %d/%d %c\n", mlx->data->player.x, mlx->data->player.y, mlx->data->player.pov);
	printf("\n");
	int i = 0;
	while (mlx->data->map[i] != NULL)
	{
		printf("%s\n", mlx->data->map[i]);
		i ++;
	}
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
	affiche_info(&mlx);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, input, &mlx);
	mlx_hook(mlx.win, 17, 0, clear_all_success, &mlx);
	mlx_loop_hook(mlx.mlx, game, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
