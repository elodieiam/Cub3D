/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:34:50 by niromano          #+#    #+#             */
/*   Updated: 2024/01/31 21:49:56 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	calcul_distance(t_mlx *mlx)
{
	int	dist;

	dist = sqrt((pow(mlx->put_line_coord.sx - mlx->put_line_coord.ex, 2)) 
	+ (pow(mlx->put_line_coord.sy - mlx->put_line_coord.ey, 2)));
	return (dist);
}

void	cub3d(t_game *game)
{
	float	i;
	int		j;

	j = FOV * -1;
	while (j != FOV + 1)
	{
		i = 1.1;
		game->mlx.put_line_coord.sx = (int)(game->player.x * L_BOX - (int)(cos_pov(&game->player) * (j / 4)));
		game->mlx.put_line_coord.sy = (int)(game->player.y * L_BOX - (int)(sin_pov(&game->player) * (j / 4)));
		game->mlx.put_line_coord.ex = (int)(game->player.x * L_BOX + (int)(sin_pov(&game->player) * 1) - (int)(cos_pov(&game->player) * (j / 4)));
		game->mlx.put_line_coord.ey = (int)(game->player.y * L_BOX - (int)(cos_pov(&game->player) * 1) - (int)(sin_pov(&game->player) * (j / 4)));
		while (((int)game->mlx.put_line_coord.ey / 20) < game->data.map_y - 1
			&& ((int)game->mlx.put_line_coord.ex / 20) < game->data.map_x - 1
			&& game->data.map[(int)game->mlx.put_line_coord.ey / 20][(int)game->mlx.put_line_coord.ex / 20] != '1')
		{
			game->mlx.put_line_coord.ex = (int)(game->player.x * L_BOX + (int)(sin_pov(&game->player) * i) - (int)(cos_pov(&game->player) * (j / 4)));
			game->mlx.put_line_coord.ey = (int)(game->player.y * L_BOX - (int)(cos_pov(&game->player) * i) - (int)(sin_pov(&game->player) * (j / 4)));
			i += 0.1;
		}
		put_line(&game->mlx, &game->mlx.img_map, 0xFF0000);
		j ++;
	}
}
