/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:23:26 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 10:33:14 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	my_mlx_pixel_get(t_buf *buf, int x, int y)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < buf->img_x && y < buf->img_y)
	{
		dst = buf->addr
			+ (y * buf->line_length + x * (buf->bits_per_pixel / 8));
		return (*(unsigned int *)dst);
	}
	return (0);
}
