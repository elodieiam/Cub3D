/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:54:22 by niromano          #+#    #+#             */
/*   Updated: 2024/03/13 16:03:39 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	background(t_mlx *mlx, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x != SCREEN_X)
	{
		y = 0;
		while (y != SCREEN_Y - 1)
		{
			if (y < SCREEN_Y / 2)
				my_mlx_pixel_put(&mlx->img_buf, x, y, data->textures.color_c);
			else
				my_mlx_pixel_put(&mlx->img_buf, x, y, data->textures.color_f);
			y ++;
		}
		x ++;
	}
}
