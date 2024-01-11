/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:48:35 by niromano          #+#    #+#             */
/*   Updated: 2024/01/11 03:00:33 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_strlen_w_linefeed(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i ++;
	return (i);
}

int	max_len(t_data *data)
{
	t_list	*tmp;
	int		len;

	tmp = data->buffer;
	len = 0;
	while (tmp->next != NULL)
	{
		if (len < ft_strlen_w_linefeed(tmp->content))
			len = ft_strlen_w_linefeed(tmp->content);
		tmp = tmp->next;
	}
	return (len);
}

void	check_map(t_data *data)
{
	t_list	*tmp;

	tmp = data->buffer;
	while (tmp->next != NULL)
	{
		printf("%s", tmp->content);
		tmp = tmp->next;
	}
}

void	take_map(t_data *data)
{
	check_map(data);
	printf("\nlen = %d\n", max_len(data));
}
