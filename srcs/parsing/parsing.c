/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 06:26:01 by niromano          #+#    #+#             */
/*   Updated: 2024/01/24 12:52:01 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	take_buffer(t_mlx *mlx)
{
	t_list	*buf;

	buf = ft_lstnew(get_next_line(mlx->data->fd));
	if (buf == NULL)
		clear_all_failed(mlx, "Malloc Failed !\n");
	while (buf->content != NULL)
	{
		if (mlx->data->buffer == NULL)
			mlx->data->buffer = buf;
		else
			ft_lstadd_back(&mlx->data->buffer, buf);
		buf = ft_lstnew(get_next_line(mlx->data->fd));
		if (buf == NULL)
			clear_all_failed(mlx, "Malloc Failed !\n");
	}
	ft_lstadd_back(&mlx->data->buffer, buf);
	close(mlx->data->fd);
	mlx->data->fd = -1;
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

void	fill_texture2(int value, char *tmp, t_mlx *mlx)
{
	if (value == 4)
	{
		if (mlx->data->textures.raw_e != NULL)
		{
			free(tmp);
			clear_all_failed(mlx, "Duplicate East texture in file\n");
		}
		mlx->data->textures.raw_e = tmp;
	}
	else if (value == 5)
	{
		if (mlx->data->textures.texture_f != -1)
		{
			free(tmp);
			clear_all_failed(mlx, "Duplicate Floor texture in file\n");
		}
		mlx->data->textures.texture_f = get_rgb(tmp, mlx);
	}
	else if (value == 6)
	{
		if (mlx->data->textures.texture_c != -1)
		{
			free(tmp);
			clear_all_failed(mlx, "Duplicate Ceiling texture in file\n");
		}
		mlx->data->textures.texture_c = get_rgb(tmp, mlx);
	}
}

void	fill_texture(char *s, int value, t_mlx *mlx)
{
	char	*tmp;

	tmp = ft_strtrim(s, " \f\n\r\t\v");
	if (tmp == NULL)
		clear_all_failed(mlx, "Malloc Failed !\n");
	if (value == 1)
	{
		if (mlx->data->textures.raw_n != NULL)
		{
			free(tmp);
			clear_all_failed(mlx, "Duplicate North texture in file\n");
		}
		mlx->data->textures.raw_n = tmp;
	}
	else if (value == 2)
	{
		if (mlx->data->textures.raw_s != NULL)
		{
			free(tmp);
			clear_all_failed(mlx, "Duplicate South texture in file\n");
		}
		mlx->data->textures.raw_s = tmp;
	}
	else if (value == 3)
	{
		if (mlx->data->textures.raw_w != NULL)
		{
			free(tmp);
			clear_all_failed(mlx, "Duplicate West texture in file\n");
		}
		mlx->data->textures.raw_w = tmp;
	}
	else
		fill_texture2(value, tmp, mlx);
}

int	check_texture(char *s, t_mlx *mlx)
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
			clear_all_failed(mlx, "ID without RGB example : ID \"R,G,B\"\n");
		clear_all_failed(mlx, "ID without path example : ID \"path\"\n");
	}
	fill_texture(&s[i], value, mlx);
	return (0);
}

void	delete_texture_buffer(t_mlx *mlx, t_list *tmp)
{
	int	len;

	if (tmp == NULL)
		clear_all_failed(mlx, "No map in file\n");
	len = ft_lstsize(mlx->data->buffer) - ft_lstsize(tmp);
	while (len != 0)
	{
		free(mlx->data->buffer->content);
		tmp = mlx->data->buffer;
		mlx->data->buffer = mlx->data->buffer->next;
		free(tmp);
		len --;
	}
}

void	take_texture(t_mlx *mlx)
{
	t_list	*tmp;
	int		value;

	tmp = mlx->data->buffer;
	while (tmp != NULL)
	{
		value = check_texture(tmp->content, mlx);
		if (value == 0)
			tmp = tmp->next;
		else if (value == -2)
			clear_all_failed(mlx, "A line is not empty in the file\n");
		else
			break ;
	}
	if (mlx->data->textures.raw_n == NULL || mlx->data->textures.raw_s == NULL
		|| mlx->data->textures.raw_w == NULL || mlx->data->textures.raw_e == NULL
		|| mlx->data->textures.texture_f == -1 || mlx->data->textures.texture_c == -1)
		clear_all_failed(mlx,
			"Incorrect line or missing textures before map\n");
	delete_texture_buffer(mlx, tmp);
}

void	open_texture(t_mlx *mlx)
{
	int	fd;

	fd = open(mlx->data->textures.raw_n, O_RDONLY);
	if (fd == -1)
		clear_all_failed(mlx, "Can't read North Texture\n");
	close(fd);
	fd = open(mlx->data->textures.raw_s, O_RDONLY);
	if (fd == -1)
		clear_all_failed(mlx, "Can't read South Texture\n");
	close(fd);
	fd = open(mlx->data->textures.raw_w, O_RDONLY);
	if (fd == -1)
		clear_all_failed(mlx, "Can't read West Texture\n");
	close(fd);
	fd = open(mlx->data->textures.raw_e, O_RDONLY);
	if (fd == -1)
		clear_all_failed(mlx, "Can't read East Texture\n");
	close(fd);
}

void	parsing(int argc, char **argv, t_mlx *mlx)
{
	set_data_null(mlx->data);
	if (argc != 2)
		clear_all_failed(mlx, "Bad args example : ./cub3D \"file_path\"\n");
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 5) != 0)
		clear_all_failed(mlx, "Bad extension example : \"*.cub\"\n");
	mlx->data->fd = open(argv[1], O_RDONLY);
	if (mlx->data->fd == -1)
		clear_all_failed(mlx, "Can't open the file\n");
	take_buffer(mlx);
	take_texture(mlx);
	open_texture(mlx);
	take_map(mlx);
}
