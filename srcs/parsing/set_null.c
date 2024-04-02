/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:46:23 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 10:40:55 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_mlx_null(t_mlx *mlx)
{
	mlx->mlx_ptr = NULL;
	mlx->win = NULL;
	mlx->img_buf.img = NULL;
	mlx->img_map.img = NULL;
}

void	set_data_null(t_data *data)
{
	data->fd = -1;
	data->textures.raw_n = NULL;
	data->textures.raw_s = NULL;
	data->textures.raw_w = NULL;
	data->textures.raw_e = NULL;
	data->textures.color_f = -1;
	data->textures.color_c = -1;
	data->textures.texture_n.img = NULL;
	data->textures.texture_s.img = NULL;
	data->textures.texture_w.img = NULL;
	data->textures.texture_e.img = NULL;
	data->map = NULL;
	data->buffer = NULL;
}

void	set_player_null(t_player *player)
{
	player->x = -1;
	player->y = -1;
	player->pov = -1;
	player->keys.w = 1;
	player->keys.s = 1;
	player->keys.a = 1;
	player->keys.d = 1;
	player->keys.left = 1;
	player->keys.right = 1;
}

void	set_game_null(t_game *game)
{
	set_mlx_null(&game->mlx);
	set_data_null(&game->data);
	set_player_null(&game->player);
}
