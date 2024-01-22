/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:46:23 by niromano          #+#    #+#             */
/*   Updated: 2024/01/22 14:28:09 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_mlx_null(t_mlx *mlx)
{
	mlx->data = NULL;
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->buffer.img = NULL;
	mlx->hook[0] = 1;
	mlx->hook[1] = 1;
	mlx->hook[2] = 1;
	mlx->hook[3] = 1;
	mlx->hook[4] = 1;
	mlx->hook[5] = 1;
}

void	set_data_null(t_data *data)
{
	data->fd = -1;
	data->raw.texture_n = NULL;
	data->raw.texture_s = NULL;
	data->raw.texture_w = NULL;
	data->raw.texture_e = NULL;
	data->raw.texture_f = -1;
	data->raw.texture_c = -1;
	data->textures.texture_n = NULL;
	data->textures.texture_s = NULL;
	data->textures.texture_w = NULL;
	data->textures.texture_e = NULL;
	data->textures.texture_f = NULL;
	data->textures.texture_c = NULL;
	data->map = NULL;
	data->player.x = -1;
	data->player.y = -1;
	data->player.pov = '\0';
	data->buffer = NULL;
}
