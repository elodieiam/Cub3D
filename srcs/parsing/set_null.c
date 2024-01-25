/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 06:46:23 by niromano          #+#    #+#             */
/*   Updated: 2024/01/25 08:59:08 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_mlx_null(t_mlx *mlx)
{
	mlx->data = NULL;
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img_buf.img = NULL;
	mlx->player.x = -1;
	mlx->player.y = -1;
	mlx->player.pov = '\0';
	mlx->player.keys.w = 1;
	mlx->player.keys.s = 1;
	mlx->player.keys.a = 1;
	mlx->player.keys.d = 1;
	mlx->player.keys.left = 1;
	mlx->player.keys.right = 1;
}

void	set_data_null(t_data *data)
{
	data->fd = -1;
	data->textures.raw_n = NULL;
	data->textures.raw_s = NULL;
	data->textures.raw_w = NULL;
	data->textures.raw_e = NULL;
	data->textures.texture_f = -1;
	data->textures.texture_c = -1;
	data->textures.texture_n = NULL;
	data->textures.texture_s = NULL;
	data->textures.texture_w = NULL;
	data->textures.texture_e = NULL;
	data->map = NULL;
	data->buffer = NULL;
}

void	set_player_null(t_player *player)
{
	player->x = -1;
	player->y = -1;
	player->pov = '\0';
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
	game->mlx.data = malloc(sizeof(t_data));
	if (game->mlx.data == NULL)
	{
		ft_putstr_fd("Error\nMalloc Failed !\n", 2);
		exit(EXIT_FAILURE);
	}
	set_data_null(game->mlx.data);
	set_player_null(&game->player);
}
