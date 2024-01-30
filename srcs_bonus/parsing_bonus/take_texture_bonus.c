/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:56:05 by niromano          #+#    #+#             */
/*   Updated: 2024/01/30 12:32:20 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	search_texture(char *s)
{
	if (s[0] == '\0')
		return (-2);
	else if (ft_strncmp(s, "NO", 2) == 0 && (s[2] == ' '
			|| (s[2] >= 9 && s[2] <= 13)))
		return (1);
	else if (ft_strncmp(s, "SO", 2) == 0 && (s[2] == ' '
			|| (s[2] >= 9 && s[2] <= 13)))
		return (2);
	else if (ft_strncmp(s, "WE", 2) == 0 && (s[2] == ' '
			|| (s[2] >= 9 && s[2] <= 13)))
		return (3);
	else if (ft_strncmp(s, "EA", 2) == 0 && (s[2] == ' '
			|| (s[2] >= 9 && s[2] <= 13)))
		return (4);
	else if (ft_strncmp(s, "F", 1) == 0 && (s[1] == ' '
			|| (s[2] >= 9 && s[2] <= 13)))
		return (5);
	else if (ft_strncmp(s, "C", 1) == 0 && (s[1] == ' '
			|| (s[2] >= 9 && s[2] <= 13)))
		return (6);
	return (-1);
}

int	check_texture(char *s, t_game *game)
{
	int	i;
	int	value;

	i = 0;
	if (s == NULL || s[i] == '\n')
		return (0);
	while (s[i] != '\0' && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i ++;
	value = search_texture(&s[i]);
	if (value < 0)
		return (value);
	i += 2;
	if (value == 5 || value == 6)
		i -= 1;
	while (s[i] != '\0' && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i ++;
	if (s[i] == '\0')
	{
		if (value == 5 || value == 6)
			clear_all_failed(game, "ID without RGB example : ID \"R,G,B\"\n");
		clear_all_failed(game, "ID without path example : ID \"path\"\n");
	}
	fill_texture(&s[i], value, game);
	return (0);
}

void	delete_texture_buffer(t_game *game, t_list *tmp)
{
	int	len;

	if (tmp == NULL)
		clear_all_failed(game, "No map in file\n");
	len = ft_lstsize(game->data.buffer) - ft_lstsize(tmp);
	while (len != 0)
	{
		free(game->data.buffer->content);
		tmp = game->data.buffer;
		game->data.buffer = game->data.buffer->next;
		free(tmp);
		len --;
	}
}

void	open_texture(t_game *game)
{
	int	fd;

	fd = open(game->data.textures.raw_n, O_RDONLY);
	if (fd == -1)
		clear_all_failed(game, "Can't read North Texture\n");
	close(fd);
	fd = open(game->data.textures.raw_s, O_RDONLY);
	if (fd == -1)
		clear_all_failed(game, "Can't read South Texture\n");
	close(fd);
	fd = open(game->data.textures.raw_w, O_RDONLY);
	if (fd == -1)
		clear_all_failed(game, "Can't read West Texture\n");
	close(fd);
	fd = open(game->data.textures.raw_e, O_RDONLY);
	if (fd == -1)
		clear_all_failed(game, "Can't read East Texture\n");
	close(fd);
}

void	take_texture(t_game *game)
{
	t_list	*tmp;
	int		value;

	tmp = game->data.buffer;
	while (tmp != NULL)
	{
		value = check_texture(tmp->content, game);
		if (value == 0)
			tmp = tmp->next;
		else if (value == -2)
			clear_all_failed(game, "A line is not empty in the file\n");
		else
			break ;
	}
	if (game->data.textures.raw_n == NULL
		|| game->data.textures.raw_s == NULL
		|| game->data.textures.raw_w == NULL
		|| game->data.textures.raw_e == NULL
		|| game->data.textures.color_f == -1
		|| game->data.textures.color_c == -1)
		clear_all_failed(game,
			"Incorrect line or missing textures before map\n");
	delete_texture_buffer(game, tmp);
	open_texture(game);
}
