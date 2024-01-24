/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:46:23 by niromano          #+#    #+#             */
/*   Updated: 2024/01/24 12:56:17 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_mlx_null(t_mlx *mlx)
{
	mlx->data = NULL;
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img_buf.img = NULL;
	mlx->player.x = -1;
	mlx->player.y = -1;
	mlx->player.pov = '\0';
	mlx->player.keys.w = 1;
	mlx->player.keys.s = 1;
	mlx->player.keys.a = 1;
	mlx->player.keys.d = 1;
	mlx->player.keys.left = 1;
	mlx->player.keys.right = 1;
}

void	set_data_null(t_data *data)
{
	data->fd = -1;
	data->textures.raw_n = NULL;
	data->textures.raw_s = NULL;
	data->textures.raw_w = NULL;
	data->textures.raw_e = NULL;
	data->textures.texture_f = -1;
	data->textures.texture_c = -1;
	data->textures.texture_n = NULL;
	data->textures.texture_s = NULL;
	data->textures.texture_w = NULL;
	data->textures.texture_e = NULL;
	data->map = NULL;
	data->buffer = NULL;
}
