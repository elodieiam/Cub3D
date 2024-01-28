/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:13:29 by niromano          #+#    #+#             */
/*   Updated: 2024/01/28 14:55:00 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	game_cub(t_game *game)
{
	background(&game->mlx, &game->data);
	map(&game->mlx, game->data.map);
	// minimap(mlx);
	player(&game->mlx, &game->player);
	player_move(&game->mlx, &game->data, &game->player);
	mouse(&game->mlx, &game->player);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win, game->mlx.img_buf.img, 0, 0);
	return (0);
}
