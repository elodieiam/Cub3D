/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:48:35 by niromano          #+#    #+#             */
/*   Updated: 2023/12/21 10:20:02 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		max_len(t_data *data)
{
	t_list	*tmp;
	size_t	len;

	tmp = data->buffer;
	len = 0;
	while (tmp->next != NULL)
	{
		if (len < ft_strlen(tmp->content))
			len = ft_strlen(tmp->content);
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
	// printf("len = %d\n", max_len(data));
}
