/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:36:46 by niromano          #+#    #+#             */
/*   Updated: 2024/01/23 10:37:07 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
