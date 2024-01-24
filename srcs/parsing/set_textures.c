/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:00:11 by niromano          #+#    #+#             */
/*   Updated: 2024/01/24 12:24:42 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clear_raw(t_mlx *mlx)
{
	free(mlx->data->textures.raw_n);
	mlx->data->textures.raw_n = NULL;
	free(mlx->data->textures.raw_s);
	mlx->data->textures.raw_s = NULL;
	free(mlx->data->textures.raw_w);
	mlx->data->textures.raw_w = NULL;
	free(mlx->data->textures.raw_e);
	mlx->data->textures.raw_e = NULL;
}

void	set_textures(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->data->textures.texture_n = mlx_xpm_file_to_image(mlx->mlx,
			mlx->data->textures.raw_n, &x, &y);
	if (mlx->data->textures.texture_n == NULL)
		clear_all_failed(mlx, "Error\n");
	mlx->data->textures.texture_s = mlx_xpm_file_to_image(mlx->mlx,
			mlx->data->textures.raw_s, &x, &y);
	if (mlx->data->textures.texture_s == NULL)
		clear_all_failed(mlx, "Error\n");
	mlx->data->textures.texture_w = mlx_xpm_file_to_image(mlx->mlx,
			mlx->data->textures.raw_w, &x, &y);
	if (mlx->data->textures.texture_w == NULL)
		clear_all_failed(mlx, "Error\n");
	mlx->data->textures.texture_e = mlx_xpm_file_to_image(mlx->mlx,
			mlx->data->textures.raw_e, &x, &y);
	if (mlx->data->textures.texture_e == NULL)
		clear_all_failed(mlx, "Error\n");
	clear_raw(mlx);
}
