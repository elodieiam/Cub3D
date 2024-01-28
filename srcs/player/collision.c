/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:01:28 by niromano          #+#    #+#             */
/*   Updated: 2024/01/28 12:24:58 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	north_west(t_data *data, t_player *player, int axis)
{
	printf("NW\n");
	if (axis == 'x' && data->map[(int)player->y][(int)player->x - 1] == '1' && player->x < (int)player->x + 0.1)
		return (1);
	if (axis == 'y' && data->map[(int)player->y - 1][(int)player->x] == '1' && player->y < (int)player->y + 0.1)
		return (1);
	return (0);
}

static int	north_east(t_data *data, t_player *player, int axis)
{
	printf("NE\n");
	if (axis == 'x' && data->map[(int)player->y][(int)player->x + 1] == '1' && player->x > (int)player->x + 0.9)
		return (1);
	if (axis == 'y' && data->map[(int)player->y - 1][(int)player->x] == '1' && player->y < (int)player->y + 0.1)
		return (1);
	return (0);
}

static int	south_west(t_data *data, t_player *player, int axis)
{
	printf("SW\n");
	if (axis == 'x' && data->map[(int)player->y][(int)player->x - 1] == '1' && player->x < (int)player->x + 0.1)
		return (1);
	if (axis == 'y' && data->map[(int)player->y + 1][(int)player->x] == '1' && player->y > (int)player->y + 0.9)
		return (1);
	return (0);
}

static int	south_east(t_data *data, t_player *player, int axis)
{
	printf("SE\n");
	if (axis == 'x' && data->map[(int)player->y][(int)player->x + 1] == '1' && player->x > (int)player->x + 0.9)
		return (1);
	if (axis == 'y' && data->map[(int)player->y + 1][(int)player->x] == '1' && player->y > (int)player->y + 0.9)
		return (1);
	return (0);
}

int	collision(t_data *data, t_player *player, char key, char axis)
{
	if (key == 'w')
	{
		if (sin_pov(player) > 0)
		{
			if (cos_pov(player) > 0)
				return (north_east(data, player, axis));
			else
				return (south_east(data, player, axis));
		}
		else
		{
			if (cos_pov(player) > 0)
				return (north_west(data, player, axis));
			else
				return (south_west(data, player, axis));
		}
	}
	if (key == 's')
	{
		if (sin_pov(player) > 0)
		{
			if (cos_pov(player) > 0)
				return (south_west(data, player, axis));
			else
				return (north_west(data, player, axis));
		}
		else
		{
			if (cos_pov(player) > 0)
				return (south_east(data, player, axis));
			else
				return (north_east(data, player, axis));
		}
	}
	if (key == 'a')
	{
		if (sin_pov(player) > 0)
		{
			if (cos_pov(player) > 0)
				return (north_west(data, player, axis));
			else
				return (north_east(data, player, axis));
		}
		else
		{
			if (cos_pov(player) > 0)
				return (south_west(data, player, axis));
			else
				return (south_east(data, player, axis));
		}
	}
	if (key == 'd')
	{
		if (sin_pov(player) > 0)
		{
			if (cos_pov(player) > 0)
				return (south_east(data, player, axis));
			else
				return (south_west(data, player, axis));
		}
		else
		{
			if (cos_pov(player) > 0)
				return (north_east(data, player, axis));
			else
				return (north_west(data, player, axis));
		}
	}
	return (0);
}
