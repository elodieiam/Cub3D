/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:27:10 by niromano          #+#    #+#             */
/*   Updated: 2024/03/26 10:17:32 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	ft_strlen_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
		i ++;
	return (i);
}

void	check_border_line(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->data.map[i][j] != '\0')
	{
		if ((i == 0 || j == 0 || i == ft_strlen_mat(game->data.map) - 1
				|| j == (int)ft_strlen(game->data.map[i]) - 1)
			&& (game->data.map[i][j] == '0' || game->data.map[i][j] == 'N'
			|| game->data.map[i][j] == 'S' || game->data.map[i][j] == 'W'
			|| game->data.map[i][j] == 'E' || game->data.map[i][j] == 'O'
			|| game->data.map[i][j] == 'C'))
			clear_all_failed(game, "The map is not closed\n");
		else if (game->data.map[i][j] == '0' || game->data.map[i][j] == 'N'
			|| game->data.map[i][j] == 'S' || game->data.map[i][j] == 'W'
			|| game->data.map[i][j] == 'E' || game->data.map[i][j] == 'O'
			|| game->data.map[i][j] == 'C')
		{
			if (game->data.map[i - 1][j] == '.'
				|| game->data.map[i][j - 1] == '.'
				|| game->data.map[i + 1][j] == '.'
				|| game->data.map[i][j + 1] == '.')
			{
				clear_all_failed(game, "The map is not closed\n");
			}
		}
		j ++;
	}
}

void	check_border(t_game *game)
{
	int		i;

	i = 0;
	while (game->data.map[i] != NULL)
	{
		check_border_line(game, i);
		i ++;
	}
}
