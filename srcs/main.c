/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:19:42 by niromano          #+#    #+#             */
/*   Updated: 2023/12/11 08:46:00 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clear_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != NULL)
	{
		free(mat[i]);
		i ++;
	}
	free(mat);
}

void	clear_all(t_data *data)
{
	if (data != NULL)
	{
		if (data->text_n != NULL)
			free(data->text_n);
		if (data->text_s != NULL)
			free(data->text_s);
		if (data->text_w != NULL)
			free(data->text_w);
		if (data->text_e != NULL)
			free(data->text_e);
		if (data->text_f != NULL)
			clear_mat(data->text_f);
		if (data->text_c != NULL)
			clear_mat(data->text_c);
		if (data->map != NULL)
			clear_mat(data->map);
		free(data);
	}
}

void	clear_all_error(t_data *data)
{
	clear_all(data);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	affiche_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			printf("%s\n", data->map[i]);
			i ++;
		}
	}
}

void	check_extention(char *file, t_data *data)
{
	char	**tmp;
	int		i;

	i = 0;
	while (file[i] != '\0')
		i ++;
	i --;
	if (i < 0 || file[i] == '.')
		clear_all_error(data);
	i = 0;
	tmp = ft_split(file, '.');
	if (tmp == NULL)
		clear_all_error(data);
	while (tmp[i] != NULL)
		i ++;
	i --;
	if (i < 1 || ft_strncmp(tmp[i], "cub", 4) != 0)
	{
		clear_mat(tmp);
		clear_all_error(data);
	}
	clear_mat(tmp);
}

int	use_buf(char *buf, t_data *data)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(buf, ' ');
	if (tmp == NULL)
		return (1);
	while (tmp[i] != NULL)
		i ++;
	if (i > 2)
		return (1);
	if (ft_strncmp(tmp[0], "NO", 3) == 0 && data->text_n == NULL)
		data->text_n = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "SO", 3) == 0 && data->text_s == NULL)
		data->text_s = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "WE", 3) == 0 && data->text_w == NULL)
		data->text_w = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "EA", 3) == 0 && data->text_e == NULL)
		data->text_e = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "F", 2) == 0 && data->text_f == NULL)
		data->text_f = ft_split(tmp[1], ',');
	else if (ft_strncmp(tmp[0], "C", 2) == 0 && data->text_c == NULL)
		data->text_c = ft_split(tmp[1], ',');
	return (0);
}

void	set_data(char *file, t_data *data)
{
	int		fd;
	char	*buf;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		clear_all_error(data);
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		if (use_buf(buf, data) == 1)
		{
			close(fd);
			free(buf);
			clear_all_error(data);
		}
		free(buf);
		buf = get_next_line(fd);
	}
	close(fd);
}

void	parsing(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		clear_all_error(data);
	check_extention(argv[1], data);
	set_data(argv[1], data);
}

void	set_data_null(t_data *data)
{
	data->map = NULL;
	data->text_n = NULL;
	data->text_s = NULL;
	data->text_w = NULL;
	data->text_e = NULL;
	data->text_f = NULL;
	data->text_c = NULL;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		clear_all_error(data);
	set_data_null(data);
	parsing(argc, argv, data);
	affiche_map(data);
	clear_all(data);
	return (0);
}
