/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:13:29 by niromano          #+#    #+#             */
/*   Updated: 2024/01/23 09:59:02 by niromano         ###   ########.fr       */
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

void	carre(t_mlx *mlx, int start[2], int end[2], int color)
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

void	name(int fraction[2], int save[2], int coord[2], int end[2])
{
	if (fraction[0] > fraction[1])
	{
		if (coord[0] < end[0])
			coord[0] ++;
		else
			coord[0] --;
		fraction[0] --;
	}
	else if (fraction[0] < fraction[1])
	{
		if (coord[1] < end[1])
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
		if (coord[0] < end[0])
			coord[0] ++;
		else
			coord[0] --;
		if (coord[1] < end[1])
			coord[1] ++;
		else
			coord[1] --;
		fraction[0] --;
		fraction[1] --;
	}
}

void	put_line(t_mlx *mlx, int start[2], int end[2])
{
	int	coord[2];
	int	fraction[2];
	int	save[2];

	coord[0] = start[0];
	coord[1] = start[1];
	carre(mlx, start, end, 0x000000);
	get_fraction(start[0] - end[0], start[1] - end[1], fraction, save);
	printf("fraction : %d / %d\n", fraction[0], fraction[1]);
	while (coord[0] != end[0] && coord[1] != end[1])
	{
		my_mlx_pixel_put(&mlx->buffer, coord[0], coord[1], 0x000000);
		name(fraction, save, coord, end);
	}
}

int	game(t_mlx *mlx)
{
	background(mlx);
	// map(mlx);
	// player(mlx);
	// player_move(mlx);
	// minimap(mlx);
	int tab1[2] = {300,450};
	int tab2[2] = {200,200};
	put_line(mlx, tab1, tab2);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->buffer.img, 0, 0);
	return (0);
}
