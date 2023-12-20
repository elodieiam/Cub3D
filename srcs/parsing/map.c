/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:48:35 by niromano          #+#    #+#             */
/*   Updated: 2023/12/20 13:18:28 by niromano         ###   ########.fr       */
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

void	take_map(t_data *data)
{
	printf("len = %d\n", max_len(data));
}
