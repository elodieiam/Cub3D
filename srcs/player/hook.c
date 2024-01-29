/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:18:03 by niromano          #+#    #+#             */
/*   Updated: 2024/01/29 11:18:41 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_hook(int key, t_game *game)
{
	if (key == XK_Escape)
		clear_all_success(game);
	else if (key == 'w')
		game->player.keys.w = 0;
	else if (key == 's')
		game->player.keys.s = 0;
	else if (key == 'a')
		game->player.keys.a = 0;
	else if (key == 'd')
		game->player.keys.d = 0;
	else if (key == XK_Left)
		game->player.keys.left = 0;
	else if (key == XK_Right)
		game->player.keys.right = 0;
	return (0);
}

int	let_hook(int key, t_player *player)
{
	if (key == 'w')
		player->keys.w = 1;
	else if (key == 's')
		player->keys.s = 1;
	else if (key == 'a')
		player->keys.a = 1;
	else if (key == 'd')
		player->keys.d = 1;
	else if (key == XK_Left)
		player->keys.left = 1;
	else if (key == XK_Right)
		player->keys.right = 1;
	return (0);
}
