/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:36:46 by niromano          #+#    #+#             */
/*   Updated: 2024/01/23 16:52:46 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	player(t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;

	x = mlx->data->player.x * CASE_LEN;
	y = mlx->data->player.y * CASE_LEN;
	i = -10;
	while (i != 10)
	{
		mlx->line_coord[0] = x;
		mlx->line_coord[1] = y - 20;
		mlx->line_coord[2] = x + i;
		mlx->line_coord[3] = y + 20;
		put_line(mlx, 0xFF0000);
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
