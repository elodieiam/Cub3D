/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:46:23 by niromano          #+#    #+#             */
/*   Updated: 2023/12/12 09:19:58 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_data_null(t_data *data)
{
	data->fd = -1;
	data->texture_n = NULL;
	data->texture_s = NULL;
	data->texture_w = NULL;
	data->texture_e = NULL;
	data->texture_f = -1;
	data->texture_c = -1;
	data->map = NULL;
	data->buffer = NULL;
}
