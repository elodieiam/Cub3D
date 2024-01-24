/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:48:35 by niromano          #+#    #+#             */
/*   Updated: 2024/01/24 12:53:34 by niromano         ###   ########.fr       */
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

int	max_len(t_mlx *mlx)
{
	t_list	*tmp;
	int		len;

	tmp = mlx->data->buffer;
	len = 0;
	while (tmp->next != NULL)
	{
		if (len < ft_strlen_w_linefeed(tmp->content))
			len = ft_strlen_w_linefeed(tmp->content);
		tmp = tmp->next;
	}
	return (len);
}

int	count_line(t_mlx *mlx)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = mlx->data->buffer;
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

void	verify_character(t_mlx *mlx)
{
	t_list	*tmp;
	int		i;

	tmp = mlx->data->buffer;
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
				clear_all_failed(mlx, "Invalid character in the map\n");
			}
			i ++;
		}
		tmp = tmp->next;
	}
}

void	check_map(t_mlx *mlx)
{
	t_list	*tmp;
	int		i;

	tmp = mlx->data->buffer;
	while (tmp->next != NULL)
	{
		i = 0;
		if (check_empty_line_map(tmp->content) == 1)
			clear_all_failed(mlx, "Empty line in the map\n");
		i ++;
		tmp = tmp->next;
	}
	verify_character(mlx);
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

void	search_player(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->data->map[i] != NULL)
	{
		j = 0;
		while (mlx->data->map[i][j] != '\0')
		{
			if (mlx->data->map[i][j] == 'N' || mlx->data->map[i][j] == 'S'
				|| mlx->data->map[i][j] == 'W' || mlx->data->map[i][j] == 'E')
			{
				if (mlx->player.pov != '\0')
					clear_all_failed(mlx, "More than one spawn point in the map\n");
				else
				{
					mlx->player.x = j + 0.5;
					mlx->player.y = i + 0.5;
					mlx->player.pov = mlx->data->map[i][j];
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

void	check_border(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (mlx->data->map[i] != NULL)
	{
		j = 0;
		while (mlx->data->map[i][j] != '\0')
		{
			if ((i == 0 || j == 0 || i == ft_strlen_mat(mlx->data->map) - 1
					|| j == (int)ft_strlen(mlx->data->map[i]) - 1) && mlx->data->map[i][j] == '0')
				clear_all_failed(mlx, "The map is not closed\n");
			else if (mlx->data->map[i][j] == '0' || mlx->data->map[i][j] == 'N'
				|| mlx->data->map[i][j] == 'S' || mlx->data->map[i][j] == 'W'
				|| mlx->data->map[i][j] == 'E')
			{
				if (mlx->data->map[i - 1][j] == '.'
					|| mlx->data->map[i][j - 1] == '.'
					|| mlx->data->map[i + 1][j] == '.'
					|| mlx->data->map[i][j + 1] == '.')
				{
					clear_all_failed(mlx, "The map is not closed\n");
				}
			}
			j ++;
		}
		i ++;
	}
}

void	take_map(t_mlx *mlx)
{
	t_list	*tmp;
	int		i;
	int		line;
	int		len;

	i = 0;
	line = count_line(mlx);
	len = max_len(mlx);
	check_map(mlx);
	tmp = mlx->data->buffer;
	mlx->data->map = malloc(sizeof(char *) * (line + 1));
	if (mlx->data->map == NULL)
		clear_all_failed(mlx, "Malloc Failed !\n");
	while (i != line)
	{
		mlx->data->map[i] = fill_map(tmp->content, len);
		if (mlx->data->map[i] == NULL)
			clear_all_failed(mlx, "Malloc Failed !\n");
		tmp = tmp->next;
		i ++;
	}
	mlx->data->map[i] = NULL;
	clear_list(mlx->data->buffer);
	mlx->data->buffer = NULL;
	search_player(mlx);
	if (mlx->player.pov == '\0')
		clear_all_failed(mlx, "No spawn point in the map\n");
	check_border(mlx);
}
