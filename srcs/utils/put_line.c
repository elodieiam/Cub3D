/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:39:39 by niromano          #+#    #+#             */
/*   Updated: 2024/01/23 10:40:21 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	carre(t_mlx *mlx)
{
	float	x;
	float	y;

	x = mlx->line_coord[0];
	y = mlx->line_coord[1];
	while (x != mlx->line_coord[2])
	{
		my_mlx_pixel_put(&mlx->buffer, x, y, 0x000000);
		if (x > mlx->line_coord[2])
			x --;
		else
			x ++;
	}
	while (y != mlx->line_coord[3])
	{
		my_mlx_pixel_put(&mlx->buffer, x, y, 0x000000);
		if (y > mlx->line_coord[3])
			y --;
		else
			y ++;
	}
	x = mlx->line_coord[0];
	y = mlx->line_coord[1];
	while (y != mlx->line_coord[3])
	{
		my_mlx_pixel_put(&mlx->buffer, x, y, 0x000000);
		if (y > mlx->line_coord[3])
			y --;
		else
			y ++;
	}
	while (x != mlx->line_coord[2])
	{
		my_mlx_pixel_put(&mlx->buffer, x, y, 0x000000);
		if (x > mlx->line_coord[2])
			x --;
		else
			x ++;
	}
}

void	get_fraction(int x, int y, int fraction[2], int save[2])
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
			save[0] = fraction[0];
			save[1] = fraction[1];
			break ;
		}
		tmp --;
	}
}

void	name(int fraction[2], int save[2], int coord[2], t_mlx *mlx)
{
	if (fraction[0] > fraction[1])
	{
		if (coord[0] < mlx->line_coord[2])
			coord[0] ++;
		else
			coord[0] --;
		fraction[0] --;
	}
	else if (fraction[0] < fraction[1])
	{
		if (coord[1] < mlx->line_coord[3])
			coord[1] ++;
		else
			coord[1] --;
		fraction[1] --;
	}
	else if (fraction[0] == 0)
	{
		fraction[0] = save[0];
		fraction[1] = save[1];
	}
	else
	{
		if (coord[0] < mlx->line_coord[2])
			coord[0] ++;
		else
			coord[0] --;
		if (coord[1] < mlx->line_coord[3])
			coord[1] ++;
		else
			coord[1] --;
		fraction[0] --;
		fraction[1] --;
	}
}

void	put_line(t_mlx *mlx)
{
	int	coord[2];
	int	fraction[2];
	int	save[2];

	coord[0] = mlx->line_coord[0];
	coord[1] = mlx->line_coord[1];
	carre(mlx);
	get_fraction(mlx->line_coord[0] - mlx->line_coord[2], mlx->line_coord[1] - mlx->line_coord[3], fraction, save);
	printf("fraction : %d / %d\n", fraction[0], fraction[1]);
	while (coord[0] != mlx->line_coord[2] && coord[1] != mlx->line_coord[3])
	{
		my_mlx_pixel_put(&mlx->buffer, coord[0], coord[1], 0x000000);
		name(fraction, save, coord, mlx);
	}
}
