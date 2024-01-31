/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_gestion_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:00:30 by niromano          #+#    #+#             */
/*   Updated: 2024/01/31 11:07:35 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	door_gestion(t_game *game)
{
	int		x;
	int		y;
	float	i;

	i = 0.1;
	while (i < 1.1)
	{
		x = (int)(game->player.x + (sin_pov(&game->player)) * i);
		y = (int)(game->player.y - (cos_pov(&game->player)) * i);
		if (game->data.map[y][x] == '1')
			return ;
		else if (game->data.map[y][x] == 'C'
			&& ((int)game->player.y != y || (int)game->player.x != x))
		{
			game->data.map[y][x] = 'O';
			return ;
		}
		else if (game->data.map[y][x] == 'O'
			&& ((int)game->player.y != y || (int)game->player.x != x))
		{
			game->data.map[y][x] = 'C';
			return ;
		}
		i += 0.1;
	}
}
