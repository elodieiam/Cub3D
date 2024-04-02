/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:27:10 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 10:44:04 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strlen_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
		i ++;
	return (i);
}

int	check_case(char cara)
{
	if (cara == '0' || cara == 'N' || cara == 'S'
		|| cara == 'W' || cara == 'E')
		return (0);
	return (1);
}

void	check_border_line(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->data.map[i][j] != '\0')
	{
		if ((i == 0 || j == 0 || i == ft_strlen_mat(game->data.map) - 1
				|| j == (int)ft_strlen(game->data.map[i]) - 1)
			&& check_case(game->data.map[i][j]) == 0)
			clear_all_failed(game, "The map is not closed\n");
		else if (check_case(game->data.map[i][j]) == 0)
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
