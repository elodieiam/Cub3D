/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_gestion_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:00:30 by niromano          #+#    #+#             */
/*   Updated: 2024/01/30 19:40:54 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	door_gestion(t_game *game)
{
	int	x;
	int	y;

	x = (game->player.x * L_BOX + (int)(sin_pov(&game->player) * L_BOX)) / L_BOX;
	y = (game->player.y * L_BOX - (int)(cos_pov(&game->player) * L_BOX)) / L_BOX;
	if (game->data.map[y][x] == 'C')
	{
		if ((int)game->player.y != y || (int)game->player.x != x)
			game->data.map[y][x] = 'O';
	}
	else if (game->data.map[y][x] == 'O')
	{
		if ((int)game->player.y != y || (int)game->player.x != x)
			game->data.map[y][x] = 'C';
	}
}
