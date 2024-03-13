/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:00:11 by niromano          #+#    #+#             */
/*   Updated: 2024/03/13 11:58:10 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	clear_raw(t_data *data)
{
	free(data->textures.raw_n);
	data->textures.raw_n = NULL;
	free(data->textures.raw_s);
	data->textures.raw_s = NULL;
	free(data->textures.raw_w);
	data->textures.raw_w = NULL;
	free(data->textures.raw_e);
	data->textures.raw_e = NULL;
	free(data->textures.raw_d);
	data->textures.raw_d = NULL;
}

t_buf	set_addr(t_game *game, char *texture)
{
	t_buf	buf;

	buf.img = mlx_xpm_file_to_image(game->mlx.mlx_ptr, texture, &buf.img_x, &buf.img_y);
	if (buf.img == NULL)
		return (buf);
	buf.addr = mlx_get_data_addr(buf.img, &buf.bits_per_pixel,
		&buf.line_length, &buf.endian);
	return (buf);
}

void	set_textures(t_game *game)
{
	game->data.textures.texture_n = set_addr(game, game->data.textures.raw_n);
	if (game->data.textures.texture_n.img == NULL)
		clear_all_failed(game, "North texture is not a texture\n");
	game->data.textures.texture_s = set_addr(game, game->data.textures.raw_s);
	if (game->data.textures.texture_s.img == NULL)
		clear_all_failed(game, "South texture is not a texture\n");
	game->data.textures.texture_w = set_addr(game, game->data.textures.raw_w);
	if (game->data.textures.texture_w.img == NULL)
		clear_all_failed(game, "West texture is not a texture\n");
	game->data.textures.texture_e = set_addr(game, game->data.textures.raw_e);
	if (game->data.textures.texture_e.img == NULL)
		clear_all_failed(game, "East texture is not a texture\n");
	game->data.textures.texture_d = set_addr(game, game->data.textures.raw_d);
	if (game->data.textures.texture_d.img == NULL)
		clear_all_failed(game, "Door texture is not a texture\n");
	clear_raw(&game->data);
}
