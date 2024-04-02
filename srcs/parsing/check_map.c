/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:21:07 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 10:44:45 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_empty_line_map(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i ++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

void	verify_character(t_game *game)
{
	t_list	*tmp;
	int		i;

	tmp = game->data.buffer;
	while (tmp->next != NULL)
	{
		i = 0;
		while (tmp->content[i] != '\0' && tmp->content[i] != '\n')
		{
			if (tmp->content[i] != '0' && tmp->content[i] != '1'
				&& tmp->content[i] != 'N' && tmp->content[i] != 'S'
				&& tmp->content[i] != 'W' && tmp->content[i] != 'E'
				&& tmp->content[i] != ' '
				&& !(tmp->content[i] >= 9 && tmp->content[i] <= 13))
			{
				clear_all_failed(game, "Invalid character in the map\n");
			}
			i ++;
		}
		tmp = tmp->next;
	}
}

void	check_map(t_game *game)
{
	t_list	*tmp;
	int		i;

	tmp = game->data.buffer;
	while (tmp->next != NULL)
	{
		i = 0;
		if (check_empty_line_map(tmp->content) == 1)
			clear_all_failed(game, "Empty line in the map\n");
		i ++;
		tmp = tmp->next;
	}
	verify_character(game);
}
