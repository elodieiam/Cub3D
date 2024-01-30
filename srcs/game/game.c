/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:13:29 by niromano          #+#    #+#             */
/*   Updated: 2024/01/30 13:59:50 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	game_cub(t_game *game)
{
	background(&game->mlx, &game->data);
	move_player(&game->data, &game->player);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
		game->mlx.img_buf.img, 0, 0);
	return (0);
}
