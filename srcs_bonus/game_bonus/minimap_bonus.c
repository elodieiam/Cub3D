/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:13:29 by niromano          #+#    #+#             */
/*   Updated: 2024/01/31 13:45:32 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	minimap_frame(t_mlx *mlx)
{
	int	i;
	int	j;

	i = SCREEN_X - 171;
	while (i++ < SCREEN_X - 8)
	{
		j = 9;
		while (j ++ < 172)
		{
			if (i == SCREEN_X - 170 || i == SCREEN_X - 8 || j == 10 || j == 172)
				my_mlx_pixel_put(&mlx->img_buf, i, j, 0x010101);
			else
				my_mlx_pixel_put(&mlx->img_buf, i, j, 0x3E3E3E);
		}
	}
}

void	insert_minimap(t_mlx *mlx, t_player *player)
{
	int	buf_xy[2];
	int	map_xy[2];
	int	clr;

	buf_xy[0] = (player->x * L_BOX) - (L_BOX * 4);
	map_xy[0] = SCREEN_X - 169;
	minimap_frame(mlx);
	while (buf_xy[0] < (player->x * L_BOX) + (L_BOX * 4))
	{
		buf_xy[1] = (player->y * L_BOX) - (L_BOX * 4);
		map_xy[1] = 11;
		while (buf_xy[1] < (player->y * L_BOX) + (L_BOX * 4))
		{
			if (buf_xy[0] > 0 && buf_xy[1] > 0)
			{
				clr = my_mlx_pixel_get(&mlx->img_map, buf_xy[0], buf_xy[1]);
				if (clr != 0)
					my_mlx_pixel_put(&mlx->img_buf, map_xy[0], map_xy[1], clr);
			}
			buf_xy[1]++;
			map_xy[1]++;
		}
		buf_xy[0]++;
		map_xy[0]++;
	}
}
