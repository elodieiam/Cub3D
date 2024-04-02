/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:13:29 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 10:53:46 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	game_cub(t_game *game)
{
	background(&game->mlx, &game->data);
	move_player(&game->data, &game->player);
	move_cam(&game->player, &game->rc);
	cub3d(game, &game->rc);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
		game->mlx.img_buf.img, 0, 0);
	return (0);
}
