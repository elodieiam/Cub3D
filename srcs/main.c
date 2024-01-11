/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:19:42 by niromano          #+#    #+#             */
/*   Updated: 2024/01/11 03:52:57 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	clear_all_success(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_n);
	mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_s);
	mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_w);
	mlx_destroy_image(mlx->mlx, mlx->data->textures.texture_e);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	clear_all(mlx->data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	input(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		clear_all_success(mlx);
	return (0);
}

void	set_textures(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->data->textures.texture_n = mlx_xpm_file_to_image(mlx->mlx, mlx->data->raw.texture_n, &x, &y);
	mlx->data->textures.texture_s = mlx_xpm_file_to_image(mlx->mlx, mlx->data->raw.texture_s, &x, &y);
	mlx->data->textures.texture_w = mlx_xpm_file_to_image(mlx->mlx, mlx->data->raw.texture_w, &x, &y);
	mlx->data->textures.texture_e = mlx_xpm_file_to_image(mlx->mlx, mlx->data->raw.texture_e, &x, &y);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.data = malloc(sizeof(t_data));
	if (mlx.data == NULL)
		clear_all_error(mlx.data, "Malloc Failed !\n");
	parsing(argc, argv, mlx.data);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 500, 500, "Cub3D");
	set_textures(&mlx);
	printf("%d -- %d\n", mlx.data->raw.texture_c, mlx.data->raw.texture_f);
	mlx_hook(mlx.win, KeyPress, KeyPressMask, input, &mlx);
	mlx_hook(mlx.win, 17, 0, clear_all_success, &mlx);
	mlx_loop(mlx.mlx);
	clear_all(mlx.data);
	return (0);
}
