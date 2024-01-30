/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:54:22 by niromano          #+#    #+#             */
/*   Updated: 2024/01/30 09:30:38 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	background(t_mlx *mlx, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x != SCREEN_X)
	{
		y = 0;
		while (y != SCREEN_Y)
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
