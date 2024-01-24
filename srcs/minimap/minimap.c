/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:13:29 by niromano          #+#    #+#             */
/*   Updated: 2024/01/24 12:45:19 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_cube(t_mlx *mlx, int x, int y, char cube)
{
	int	i;
	int	j;

	i = 0;
	while (i != CASE_LEN)
	{
		j = 0;
		while (j != CASE_LEN)
		{
			if (cube == '0' || cube == 'N' || cube == 'S' || cube == 'W' || cube == 'E')
				my_mlx_pixel_put(&mlx->img_buf, x + i, y + j, 0xC8C8C8);
			else if (cube == '1')
				my_mlx_pixel_put(&mlx->img_buf, x + i, y + j, 0x000000);
			j ++;
		}
		i ++;
	}
}

void	minimap(t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 1080;
	y = 20;
	i = 0;
	while (i != 6)
	{
		j = 0;
		while (j != 6)
		{
			print_cube(mlx, x, y, '0');
			j ++;
			x += CASE_LEN;
		}
		i ++;
		x = 1080;
		y += CASE_LEN;
	}
}

void	map(t_mlx *mlx)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (mlx->data->map[i] != NULL)
	{
		j = 0;
		while (mlx->data->map[i][j] != '\0')
		{
			print_cube(mlx, x, y, mlx->data->map[i][j]);
			j ++;
			x += CASE_LEN;
		}
		i ++;
		x = 0;
		y += CASE_LEN;
	}
}
