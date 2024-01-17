/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:48:35 by niromano          #+#    #+#             */
/*   Updated: 2024/01/17 10:24:49 by niromano         ###   ########.fr       */
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
		tmp = tmp->next;
	}
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
			new_s[i] = '2';
		else
			new_s[i] = s[i];
		i ++;
	}
	while (i != len)
	{
		new_s[i] = '2';
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
				if (mlx->data->player.pov != '\0')
					clear_all_failed(mlx, "More than one spawn point in the map\n");
				else
				{
					mlx->data->player.x = i;
					mlx->data->player.y = j;
					mlx->data->player.pov = mlx->data->map[i][j];
				}
			}
			j ++;
		}
		i ++;
	}
}

void	check_border(t_mlx *mlx)
{
	(void)mlx;
	return ;
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
	mlx->data->map = malloc(sizeof(char*) * (line + 1));
	if (mlx->data->map == NULL)
		clear_all_failed(mlx, "Malloc Failed !\n");
	while (i != line)
	{
		mlx->data->map[i] = fill_map(tmp->content, len);
		tmp = tmp->next;
		i ++;
	}
	mlx->data->map[i] = NULL;
	search_player(mlx);
	if (mlx->data->player.pov == '\0')
		clear_all_failed(mlx, "No spawn point in the map\n");
	check_border(mlx);
}
