/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:39:39 by niromano          #+#    #+#             */
/*   Updated: 2024/01/28 19:46:56 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	positive(t_mlx *mlx, float coord[2], float fraction[2], float remnant)
{
	if (coord[0] < mlx->put_line_coord.ex)
		coord[0]++;
	else
		coord[0]--;
	remnant --;
	if ((int)remnant == 0)
	{
		if (coord[1] < mlx->put_line_coord.ey)
			coord[1]++;
		else
			coord[1]--;
		remnant += fraction[0] / fraction[1];
	}
	return (remnant);
}

float	negative(t_mlx *mlx, float coord[2], float fraction[2], float remnant)
{
	if (coord[1] < mlx->put_line_coord.ey)
		coord[1]++;
	else
		coord[1]--;
	remnant --;
	if ((int)remnant == 0)
	{
		if (coord[0] < mlx->put_line_coord.ex)
			coord[0]++;
		else
			coord[0]--;
		remnant += fraction[1] / fraction[0];
	}
	return (remnant);
}

void	put_line(t_mlx *mlx, int color)
{
	float	coord[2];
	float	fraction[2];
	float	remnant;

	coord[0] = mlx->put_line_coord.sx;
	coord[1] = mlx->put_line_coord.sy;
	fraction[0] = mlx->put_line_coord.sx - mlx->put_line_coord.ex;
	if (fraction[0] < 0)
		fraction[0] *= -1;
	fraction[1] = mlx->put_line_coord.sy - mlx->put_line_coord.ey;
	if (fraction[1] < 0)
		fraction[1] *= -1;
	if (fraction[0] > fraction[1])
		remnant = fraction[0] / fraction[1];
	else
		remnant = fraction[1] / fraction[0];
	while (coord[0] != mlx->put_line_coord.ex
		|| coord[1] != mlx->put_line_coord.ey)
	{
		my_mlx_pixel_put(&mlx->img_buf, coord[0], coord[1], color);
		if (fraction[0] > fraction[1])
			remnant = positive(mlx, coord, fraction, remnant);
		else
			remnant = negative(mlx, coord, fraction, remnant);
	}
}
