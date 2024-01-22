/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:13:29 by niromano          #+#    #+#             */
/*   Updated: 2024/01/22 18:55:07 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_buf *buf, int x, int y, int color)
{
	char	*dst;

	dst = buf->addr + (y * buf->line_length + x * (buf->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	background(t_mlx *mlx)
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
				my_mlx_pixel_put(&mlx->buffer, x, y, mlx->data->raw.texture_f);
			else
				my_mlx_pixel_put(&mlx->buffer, x, y, mlx->data->raw.texture_c);
			y ++;
		}
		x ++;
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

void	player(t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = mlx->data->player.x * CASE_LEN;
	y = mlx->data->player.y * CASE_LEN;
	i = -3;
	while (i != 3)
	{
		j = -3;
		while (j != 3)
		{
			my_mlx_pixel_put(&mlx->buffer, x + i, y + j, 0xFF0000);
			j ++;
		}
		i ++;
	}
}

void	player_move(t_mlx *mlx)
{
	if (mlx->hook[0] == 0 && mlx->data->player.y > 0.2)
		mlx->data->player.y -= SPEED;
	if (mlx->hook[1] == 0)
		mlx->data->player.y += SPEED;
	if (mlx->hook[2] == 0 && mlx->data->player.x > 0.2)
		mlx->data->player.x -= SPEED;
	if (mlx->hook[3] == 0)
		mlx->data->player.x += SPEED;
}

void	carre(t_mlx *mlx, float start[2], float end[2], int color)
{
	float	x;
	float	y;

	x = start[0];
	y = start[1];
	while (x != end[0])
	{
		my_mlx_pixel_put(&mlx->buffer, x, y, color);
		if (x > end[0])
			x --;
		else
			x ++;
	}
	x = start[0];
	while (y != end[1])
	{
		my_mlx_pixel_put(&mlx->buffer, x, y, color);
		if (y > end[1])
			y --;
		else
			y ++;
	}
}

void	put_line(t_mlx *mlx, float start[2], float end[2], int color)
{
	float	x;
	float	y;
	float	res;

	x = start[0];
	y = start[1];
	carre(mlx, start, end, color);
	res = (start[0] - end[0]) / (start[1] - end[1]);
	printf("%f / %f = %f\n", (start[0] - end[0]), (start[1] - end[1]), res);
	while (x != end[0] && y != end[1])
	{
		my_mlx_pixel_put(&mlx->buffer, x, y, color);
		if (x != end[0])
		{
			if (x < end[0])
				x ++;
			else
				x --;
		}
		if (y != end[1])
		{
			if (y < end[1])
				y ++;
			else
				y --;
		}
	}
}

int	game(t_mlx *mlx)
{
	background(mlx);
	// map(mlx);
	// player(mlx);
	// player_move(mlx);
	// minimap(mlx);
	float tab1[2] = {200,200};
	float tab2[2] = {250,500};
	put_line(mlx, tab1, tab2, 0x000000);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->buffer.img, 0, 0);
	return (0);
}
