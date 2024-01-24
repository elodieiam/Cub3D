/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:40:42 by niromano          #+#    #+#             */
/*   Updated: 2024/01/24 12:31:22 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_buf *buf, int x, int y, int color)
{
	char	*dst;

	dst = buf->addr + (y * buf->line_length + x * (buf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
