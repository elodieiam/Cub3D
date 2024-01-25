/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:48:35 by niromano          #+#    #+#             */
/*   Updated: 2024/01/25 10:02:37 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

char	*fill_map(char *s, int len)
{
	int		i;
	char	*new_s;

	i = 0;
	new_s = malloc(sizeof(char) * (len + 1));
	if (new_s == NULL)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
	{
		if (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
			new_s[i] = '.';
		else
			new_s[i] = s[i];
		i ++;
	}
	while (i != len)
	{
		new_s[i] = '.';
		i ++;
	}
	new_s[i] = '\0';
	return (new_s);
}

void	search_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->data.map[i] != NULL)
	{
		j = 0;
		while (game->data.map[i][j] != '\0')
		{
			if (game->data.map[i][j] == 'N' || game->data.map[i][j] == 'S'
				|| game->data.map[i][j] == 'W' || game->data.map[i][j] == 'E')
			{
				if (game->player.pov != '\0')
					clear_all_failed(game, "More than one spawn point in the map\n");
				else
				{
					game->player.x = j + 0.5;
					game->player.y = i + 0.5;
					game->player.pov = game->data.map[i][j];
				}
			}
			j ++;
		}
		i ++;
	}
}

int	ft_strlen_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
		i ++;
	return (i);
}

void	check_border(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->data.map[i] != NULL)
	{
		j = 0;
		while (game->data.map[i][j] != '\0')
		{
			if ((i == 0 || j == 0 || i == ft_strlen_mat(game->data.map) - 1
					|| j == (int)ft_strlen(game->data.map[i]) - 1) && game->data.map[i][j] == '0')
				clear_all_failed(game, "The map is not closed\n");
			else if (game->data.map[i][j] == '0' || game->data.map[i][j] == 'N'
				|| game->data.map[i][j] == 'S' || game->data.map[i][j] == 'W'
				|| game->data.map[i][j] == 'E')
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
		i ++;
	}
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
	clear_list(game->data.buffer);
	game->data.buffer = NULL;
	search_player(game);
	if (game->player.pov == '\0')
		clear_all_failed(game, "No spawn point in the map\n");
	check_border(game);
}
