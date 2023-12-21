/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:19:42 by niromano          #+#    #+#             */
/*   Updated: 2023/12/21 10:19:53 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	affiche_all(t_data *data)
{
	int	i = 0;

	printf("%s\n", data->texture_n);
	printf("%s\n", data->texture_s);
	printf("%s\n", data->texture_w);
	printf("%s\n", data->texture_e);
	printf("%d\n", data->texture_f);
	printf("%d\n", data->texture_c);
	while (data->map != NULL && data->map[i] != NULL)
	{
		printf("%s\n", data->map[i]);
		i ++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		clear_all_error(data, "Malloc Failed !\n");
	parsing(argc, argv, data);
	// affiche_all(data);
	clear_all(data);
	return (0);
}
