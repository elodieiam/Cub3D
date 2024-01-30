/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:23:23 by niromano          #+#    #+#             */
/*   Updated: 2024/01/30 15:15:36 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	ft_strlen_w_linefeed(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i ++;
	return (i);
}

int	max_len(t_list *buffer)
{
	t_list	*tmp;
	int		len;

	tmp = buffer;
	len = 0;
	while (tmp->next != NULL)
	{
		if (len < ft_strlen_w_linefeed(tmp->content))
			len = ft_strlen_w_linefeed(tmp->content);
		tmp = tmp->next;
	}
	return (len);
}

int	count_line(t_list *buffer)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = buffer;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i ++;
	}
	return (i);
}

void	take_map2(t_game *game)
{
	clear_list(game->data.buffer);
	game->data.buffer = NULL;
	search_player(game);
	if (game->player.pov == -1)
		clear_all_failed(game, "No spawn point in the map\n");
	check_border(game);
	check_door(game);
}

void	take_map(t_game *game)
{
	t_list	*tmp;
	int		i;
	int		line;
	int		len;

	i = 0;
	line = count_line(game->data.buffer);
	len = max_len(game->data.buffer);
	check_map(game);
	tmp = game->data.buffer;
	game->data.map = malloc(sizeof(char *) * (line + 1));
	if (game->data.map == NULL)
		clear_all_failed(game, "Malloc Failed !\n");
	while (i != line)
	{
		game->data.map[i] = fill_map(tmp->content, len);
		if (game->data.map[i] == NULL)
			clear_all_failed(game, "Malloc Failed !\n");
		tmp = tmp->next;
		i ++;
	}
	game->data.map[i] = NULL;
	take_map2(game);
}
