/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 06:26:01 by niromano          #+#    #+#             */
/*   Updated: 2023/12/21 12:52:34 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	take_buffer(t_data *data)
{
	t_list	*buf;

	buf = ft_lstnew(get_next_line(data->fd));
	if (buf == NULL)
		clear_all_error(data, "Malloc Failed !\n");
	while (buf->content != NULL)
	{
		if (data->buffer == NULL)
			data->buffer = buf;
		else
			ft_lstadd_back(&data->buffer, buf);
		buf = ft_lstnew(get_next_line(data->fd));
		if (buf == NULL)
			clear_all_error(data, "Malloc Failed !\n");
	}
	ft_lstadd_back(&data->buffer, buf);
	close(data->fd);
	data->fd = -1;
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

int	ft_mini_atoi(const char *nptr)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (ft_strlen(nptr) > 3)
		return (-1);
	if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			nb = nb * 10;
			nb = nb + nptr[i] - 48;
			i ++;
		}
		if (nptr[i] != '\0')
			return (-1);
		else
			return (nb);
	}
	return (-1);
}

int	check_rgb(char *tmp)
{
	int	i;
	int	nb;
	int	comma;

	i = 0;
	nb = 0;
	comma = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == ',')
		{
			if (nb > 3)
				return (1);
			else
				nb = 0;
			comma ++;
		}
		else if (ft_isdigit(tmp[i]) == 1)
			nb ++;
		else
			return (1);
		i ++;
	}
	if (comma != 2)
		return (1);
	return (0);
}

int	get_rgb(char *tmp, t_data *data)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;

	if (check_rgb(tmp) == 1)
		clear_all_error(data, "RGB code example : \"0,123,255\"\n");
	rgb = ft_split(tmp, ',');
	free(tmp);
	if (rgb == NULL)
		clear_all_error(data, "Malloc Failed !\n");
	r = ft_mini_atoi(rgb[0]);
	g = ft_mini_atoi(rgb[1]);
	b = ft_mini_atoi(rgb[2]);
	clear_mat(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		clear_all_error(data, "RGB code range : [0,255]\n");
	return (r << 16 | g << 8 | b);
}

void	fill_texture2(int value, char *tmp, t_data *data)
{
	if (value == 4)
	{
		if (data->texture_e != NULL)
		{
			free(tmp);
			clear_all_error(data, "Duplicate East texture in file\n");
		}
		data->texture_e = tmp;
	}
	else if (value == 5)
	{
		if (data->texture_f != -1)
		{
			free(tmp);
			clear_all_error(data, "Duplicate Floor texture in file\n");
		}
		data->texture_f = get_rgb(tmp, data);
	}
	else if (value == 6)
	{
		if (data->texture_c != -1)
		{
			free(tmp);
			clear_all_error(data, "Duplicate Ceiling texture in file\n");
		}
		data->texture_c = get_rgb(tmp, data);
	}
}

void	fill_texture(char *s, int value, t_data *data)
{
	char	*tmp;

	tmp = ft_strtrim(s, " \f\n\r\t\v");
	if (tmp == NULL)
		clear_all_error(data, "Malloc Failed !\n");
	if (value == 1)
	{
		if (data->texture_n != NULL)
		{
			free(tmp);
			clear_all_error(data, "Duplicate North texture in file\n");
		}
		data->texture_n = tmp;
	}
	else if (value == 2)
	{
		if (data->texture_s != NULL)
		{
			free(tmp);
			clear_all_error(data, "Duplicate South texture in file\n");
		}
		data->texture_s = tmp;
	}
	else if (value == 3)
	{
		if (data->texture_w != NULL)
		{
			free(tmp);
			clear_all_error(data, "Duplicate West texture in file\n");
		}
		data->texture_w = tmp;
	}
	else
		fill_texture2(value, tmp, data);
}

int	check_texture(char *s, t_data *data)
{
	int	i;
	int	value;

	i = 0;
	if (s == NULL || s[i] == '\n')
		return (0);
	while(s[i] != '\0' && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i ++;
	value = search_texture(&s[i]);
	if (value < 0)
		return (value);
	i += 2;
	if (value == 5 || value == 6)
		i -= 1;
	while(s[i] != '\0' && (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i ++;
	if (s[i] == '\0')
	{
		if (value == 5 || value == 6)
			clear_all_error(data, "ID without RGB example : ID \"R,G,B\"\n");
		clear_all_error(data, "ID without path example : ID \"path\"\n");
	}
	fill_texture(&s[i], value, data);
	return (0);
}

void	delete_texture_buffer(t_data *data, t_list *tmp)
{
	int	len;

	if (tmp == NULL)
		clear_all_error(data, "No map in file\n");
	len = ft_lstsize(data->buffer) - ft_lstsize(tmp);
	while (len != 0)
	{
		free(data->buffer->content);
		tmp = data->buffer;
		data->buffer = data->buffer->next;
		free(tmp);
		len --;
	}
}

void	take_texture(t_data *data)
{
	t_list	*tmp;
	int		value;

	tmp = data->buffer;
	while (tmp != NULL)
	{
		value = check_texture(tmp->content, data);
		if (value == 0)
			tmp = tmp->next;
		else if (value == -2)
			clear_all_error(data, "A line is not empty in the file\n");
		else
			break ;
	}
	if (data->texture_n == NULL || data->texture_s == NULL
			|| data->texture_w == NULL || data->texture_e == NULL
			|| data->texture_f == -1 || data->texture_c == -1)
		clear_all_error(data, "Incorrect line or missing textures\n");
	delete_texture_buffer(data, tmp);
}

void	parsing(int argc, char **argv, t_data *data)
{
	set_data_null(data);
	if (argc != 2)
		clear_all_error(data, "Bad args example : ./cub3D \"file_path\"\n");
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 5) != 0)
		clear_all_error(data, "Bad extension example : \"*.cub\"\n");
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd == -1)
		clear_all_error(data, "Can't open the file\n");
	take_buffer(data);
	take_texture(data);
	take_map(data);
}
