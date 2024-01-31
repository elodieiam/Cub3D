/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 07:13:29 by niromano          #+#    #+#             */
/*   Updated: 2024/01/31 18:23:58 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	game_cub(t_game *game)
{
	background(&game->mlx, &game->data);
	minimap(&game->mlx, &game->player, game->data.map);
	move_player(&game->data, &game->player);
	move_cam(&game->mlx, &game->player);
	cub3d(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win,
		game->mlx.img_map.img, 0, 0);
	return (0);
}
