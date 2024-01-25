/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:00:11 by niromano          #+#    #+#             */
/*   Updated: 2024/01/25 11:48:57 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
}

void	set_textures(t_game *game)
{
	int	x;
	int	y;

	game->data.textures.texture_n = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->data.textures.raw_n, &x, &y);
	if (game->data.textures.texture_n == NULL)
		clear_all_failed(game, "North texture is not a texture\n");
	game->data.textures.texture_s = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->data.textures.raw_s, &x, &y);
	if (game->data.textures.texture_s == NULL)
		clear_all_failed(game, "South texture is not a texture\n");
	game->data.textures.texture_w = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->data.textures.raw_w, &x, &y);
	if (game->data.textures.texture_w == NULL)
		clear_all_failed(game, "West texture is not a texture\n");
	game->data.textures.texture_e = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->data.textures.raw_e, &x, &y);
	if (game->data.textures.texture_e == NULL)
		clear_all_failed(game, "East texture is not a texture\n");
	clear_raw(&game->data);
}
