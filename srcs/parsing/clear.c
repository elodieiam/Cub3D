/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:44:27 by niromano          #+#    #+#             */
/*   Updated: 2023/12/12 12:03:20 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	clear_list(t_list *list)
{
	t_list	*tmp;

	while (list != NULL)
	{
		tmp = list;
		if (list->content != NULL)
			free(list->content);
		list = list->next;
		free(tmp);
	}
}

void	clear_all(t_data *data)
{
	if (data != NULL)
	{
		if (data->fd != -1)
			close(data->fd);
		if (data->texture_n != NULL)
			free(data->texture_n);
		if (data->texture_s != NULL)
			free(data->texture_s);
		if (data->texture_w != NULL)
			free(data->texture_w);
		if (data->texture_e != NULL)
			free(data->texture_e);
		if (data->map != NULL)
			clear_mat(data->map);
		if (data->buffer != NULL)
			clear_list(data->buffer);
		free(data);
	}
}

void	clear_all_error(t_data *data, char *error)
{
	clear_all(data);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	exit(1);
}
