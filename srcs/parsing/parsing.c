/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 06:26:01 by niromano          #+#    #+#             */
/*   Updated: 2024/01/26 14:44:00 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	take_buffer(t_game *game)
{
	t_list	*buf;

	buf = ft_lstnew(get_next_line(game->data.fd));
	if (buf == NULL)
		clear_all_failed(game, "Malloc Failed !\n");
	while (buf->content != NULL)
	{
		if (game->data.buffer == NULL)
			game->data.buffer = buf;
		else
			ft_lstadd_back(&game->data.buffer, buf);
		buf = ft_lstnew(get_next_line(game->data.fd));
		if (buf == NULL)
			clear_all_failed(game, "Malloc Failed !\n");
	}
	ft_lstadd_back(&game->data.buffer, buf);
	close(game->data.fd);
	game->data.fd = -1;
}

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

void	fill_texture2(int value, char *tmp, t_game *game)
{
	if (value == 4)
	{
		if (game->data.textures.raw_e != NULL)
		{
			free(tmp);
			clear_all_failed(game, "Duplicate East texture in file\n");
		}
		game->data.textures.raw_e = tmp;
	}
	else if (value == 5)
	{
		if (game->data.textures.color_f != -1)
		{
			free(tmp);
			clear_all_failed(game, "Duplicate Floor texture in file\n");
		}
		game->data.textures.color_f = get_rgb(tmp, game);
	}
	else if (value == 6)
	{
		if (game->data.textures.color_c != -1)
		{
			free(tmp);
			clear_all_failed(game, "Duplicate Ceiling texture in file\n");
		}
		game->data.textures.color_c = get_rgb(tmp, game);
	}
}

void	fill_texture(char *s, int value, t_game *game)
{
	char	*tmp;

	tmp = ft_strtrim(s, " \f\n\r\t\v");
	if (tmp == NULL)
		clear_all_failed(game, "Malloc Failed !\n");
	if (value == 1)
	{
		if (game->data.textures.raw_n != NULL)
		{
			free(tmp);
			clear_all_failed(game, "Duplicate North texture in file\n");
		}
		game->data.textures.raw_n = tmp;
	}
	else if (value == 2)
	{
		if (game->data.textures.raw_s != NULL)
		{
			free(tmp);
			clear_all_failed(game, "Duplicate South texture in file\n");
		}
		game->data.textures.raw_s = tmp;
	}
	else if (value == 3)
	{
		if (game->data.textures.raw_w != NULL)
		{
			free(tmp);
			clear_all_failed(game, "Duplicate West texture in file\n");
		}
		game->data.textures.raw_w = tmp;
	}
	else
		fill_texture2(value, tmp, game);
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
	if (game->data.textures.raw_n == NULL || game->data.textures.raw_s == NULL
		|| game->data.textures.raw_w == NULL || game->data.textures.raw_e == NULL
		|| game->data.textures.color_f == -1 || game->data.textures.color_c == -1)
		clear_all_failed(game, "Incorrect line or missing textures before map\n");
	delete_texture_buffer(game, tmp);
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

void	parsing(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		clear_all_failed(game, "Bad args example : ./cub3D \"file_path\"\n");
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 5) != 0)
		clear_all_failed(game, "Bad extension example : \"*.cub\"\n");
	game->data.fd = open(argv[1], O_RDONLY);
	if (game->data.fd == -1)
		clear_all_failed(game, "Can't open the file\n");
	take_buffer(game);
	take_texture(game);
	open_texture(game);
	take_map(game);
	game->data.map_x = ft_strlen(game->data.map[0]);
	game->data.map_y = ft_strlen_mat(game->data.map);
}
