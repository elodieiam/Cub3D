/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_collision_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:32:21 by niromano          #+#    #+#             */
/*   Updated: 2024/01/30 12:32:38 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static int	dir_north_west(t_data *data, t_player *player, int axis)
{
	if (axis == 'x' && data->map[(int)player->y][(int)player->x - 1] == '1'
		&& player->x < (int)player->x + 0.1)
		return (1);
	if (axis == 'y' && data->map[(int)player->y - 1][(int)player->x] == '1'
		&& player->y < (int)player->y + 0.1)
		return (1);
	return (0);
}

static int	dir_north_east(t_data *data, t_player *player, int axis)
{
	if (axis == 'x' && data->map[(int)player->y][(int)player->x + 1] == '1'
		&& player->x > (int)player->x + 0.9)
		return (1);
	if (axis == 'y' && data->map[(int)player->y - 1][(int)player->x] == '1'
		&& player->y < (int)player->y + 0.1)
		return (1);
	return (0);
}

static int	dir_south_west(t_data *data, t_player *player, int axis)
{
	if (axis == 'x' && data->map[(int)player->y][(int)player->x - 1] == '1'
		&& player->x < (int)player->x + 0.1)
		return (1);
	if (axis == 'y' && data->map[(int)player->y + 1][(int)player->x] == '1'
		&& player->y > (int)player->y + 0.9)
		return (1);
	return (0);
}

static int	dir_south_east(t_data *data, t_player *player, int axis)
{
	if (axis == 'x' && data->map[(int)player->y][(int)player->x + 1] == '1'
		&& player->x > (int)player->x + 0.9)
		return (1);
	if (axis == 'y' && data->map[(int)player->y + 1][(int)player->x] == '1'
		&& player->y > (int)player->y + 0.9)
		return (1);
	return (0);
}

int	dir_collision(t_data *data, t_player *player, int axis, int dir)
{
	if (dir == NE)
		return (dir_north_east(data, player, axis));
	else if (dir == SE)
		return (dir_south_east(data, player, axis));
	else if (dir == SW)
		return (dir_south_west(data, player, axis));
	else if (dir == NW)
		return (dir_north_west(data, player, axis));
	return (0);
}
