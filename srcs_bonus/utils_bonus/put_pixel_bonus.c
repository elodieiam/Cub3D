/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:40:42 by niromano          #+#    #+#             */
/*   Updated: 2024/01/31 15:23:44 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	my_mlx_pixel_put(t_buf *buf, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && y > 0 && x < buf->img_x && y < buf->img_y)
	{
		dst = buf->addr
			+ (y * buf->line_length + x * (buf->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
