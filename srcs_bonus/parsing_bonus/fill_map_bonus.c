/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:25:32 by niromano          #+#    #+#             */
/*   Updated: 2024/01/30 12:31:31 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

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
