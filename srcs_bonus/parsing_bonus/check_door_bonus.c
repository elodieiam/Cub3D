/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:29:55 by niromano          #+#    #+#             */
/*   Updated: 2024/01/30 15:25:04 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	check_beside(char **map, int i, int j)
{
	if (map[i + 1][j] == '1' && map[i - 1][j] == '1'
		&& map[i][j + 1] != '1' && map[i][j - 1] != '1')
	{
		return (0);
	}
	else if (map[i + 1][j] != '1' && map[i - 1][j] != '1'
		&& map[i][j + 1] == '1' && map[i][j - 1] == '1')
	{
		return (0);
	}
	return (1);
}

void	check_door(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->data.map[i] != NULL)
	{
		j = 0;
		while (game->data.map[i][j] != '\0')
		{
			if (game->data.map[i][j] == 'O' || game->data.map[i][j] == 'C')
			{
				if (check_beside(game->data.map, i, j) == 1)
					clear_all_failed(game, "Door needs to be closed on 2 sides\n");
			}
			j ++;
		}
		i ++;
	}
}
