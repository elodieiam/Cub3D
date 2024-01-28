/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:01:28 by niromano          #+#    #+#             */
/*   Updated: 2024/01/28 19:45:11 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	collision_w(t_data *data, t_player *player, char axis)
{
	if (sin_pov(player) > 0)
	{
		if (cos_pov(player) > 0)
			return (dir_collision(data, player, axis, NE));
		else
			return (dir_collision(data, player, axis, SE));
	}
	else
	{
		if (cos_pov(player) > 0)
			return (dir_collision(data, player, axis, NW));
		else
			return (dir_collision(data, player, axis, SW));
	}
	return (0);
}

static int	collision_s(t_data *data, t_player *player, char axis)
{
	if (sin_pov(player) > 0)
	{
		if (cos_pov(player) > 0)
			return (dir_collision(data, player, axis, SW));
		else
			return (dir_collision(data, player, axis, NW));
	}
	else
	{
		if (cos_pov(player) > 0)
			return (dir_collision(data, player, axis, SE));
		else
			return (dir_collision(data, player, axis, NE));
	}
	return (0);
}

static int	collision_a(t_data *data, t_player *player, char axis)
{
	if (sin_pov(player) > 0)
	{
		if (cos_pov(player) > 0)
			return (dir_collision(data, player, axis, NW));
		else
			return (dir_collision(data, player, axis, NE));
	}
	else
	{
		if (cos_pov(player) > 0)
			return (dir_collision(data, player, axis, SW));
		else
			return (dir_collision(data, player, axis, SE));
	}
	return (0);
}

static int	collision_d(t_data *data, t_player *player, char axis)
{
	if (sin_pov(player) > 0)
	{
		if (cos_pov(player) > 0)
			return (dir_collision(data, player, axis, SE));
		else
			return (dir_collision(data, player, axis, SW));
	}
	else
	{
		if (cos_pov(player) > 0)
			return (dir_collision(data, player, axis, NE));
		else
			return (dir_collision(data, player, axis, NW));
	}
	return (0);
}

int	collision(t_data *data, t_player *player, char key, char axis)
{
	if (key == 'w')
		return (collision_w(data, player, axis));
	if (key == 's')
		return (collision_s(data, player, axis));
	if (key == 'a')
		return (collision_a(data, player, axis));
	if (key == 'd')
		return (collision_d(data, player, axis));
	return (0);
}
