/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:39:39 by niromano          #+#    #+#             */
/*   Updated: 2024/01/23 16:56:35 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_fraction(int x, int y, int fraction[2])
{
	int	tmp;

	if (x < 0)
		x = x * -1;
	if (y < 0)
		y = y * -1;
	if (x > y)
		tmp = y;
	else
		tmp = x;
	fraction[0] = x;
	fraction[1] = y;
	while (tmp > 0)
	{
		if ((x / tmp > 0 && x % tmp == 0) && (y / tmp > 0 && y % tmp == 0))
		{
			fraction[0] = x / tmp;
			fraction[1] = y / tmp;
			break ;
		}
		tmp --;
	}
}

float	name(t_mlx *mlx, int coord[2], int fraction[2], float remnant)
{
	if (remnant == -1)
	{
		if (fraction[0] > fraction[1])
			remnant = (float)fraction[0] / fraction[1];
		else
			remnant = (float)fraction[1] / fraction[0];
	}
	if ((int)remnant == 0)
	{
		if (fraction[0] > fraction[1])
			remnant += (float)fraction[0] / fraction[1];
		else
			remnant += (float)fraction[1] / fraction[0];
	}
	if (fraction[0] > fraction[1])
	{
		if (coord[0] < mlx->line_coord[2])
			coord[0] ++;
		else
			coord[0] --;
		remnant --;
		if ((int)remnant == 0)
		{
			if (coord[1] < mlx->line_coord[3])
				coord[1] ++;
			else
				coord[1] --;
		}
	}
	else
	{
		if (coord[1] < mlx->line_coord[3])
			coord[1] ++;
		else
			coord[1] --;
		remnant --;
		if ((int)remnant == 0)
		{
			if (coord[0] < mlx->line_coord[2])
				coord[0] ++;
			else
				coord[0] --;
		}
	}
	return (remnant);
}

void	put_line(t_mlx *mlx, int color)
{
	int		coord[2];
	int		fraction[2];
	float	remnant;

	remnant = -1;
	coord[0] = mlx->line_coord[0];
	coord[1] = mlx->line_coord[1];
	get_fraction(mlx->line_coord[0] - mlx->line_coord[2], mlx->line_coord[1] - mlx->line_coord[3], fraction);
	while (coord[0] != mlx->line_coord[2] && coord[1] != mlx->line_coord[3])
	{
		if (coord[0] > 0 && coord[1] > 0 && coord[0] < SCREEN_X && coord[1] < SCREEN_Y)
			my_mlx_pixel_put(&mlx->buffer, coord[0], coord[1], color);
		remnant = name(mlx, coord, fraction, remnant);
	}
}
