/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rc_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:35:56 by niromano          #+#    #+#             */
/*   Updated: 2024/03/30 15:36:12 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

void	set_rc_data2(t_data *data, t_player *player, t_raycast *rc)
{
	if (data->map[(int)player->y][(int)player->x] == 'W')
	{
		rc->dir_x = 0;
		rc->dir_y = -1;
		rc->plane_x = -0.66;
		rc->plane_y = 0;
	}
	else if (data->map[(int)player->y][(int)player->x] == 'S')
	{
		rc->dir_x = 1;
		rc->dir_y = 0;
		rc->plane_x = 0;
		rc->plane_y = -0.66;
	}
	rc->anim = 0;
}

void	set_rc_data(t_data *data, t_player *player, t_raycast *rc)
{
	if (data->map[(int)player->y][(int)player->x] == 'N')
	{
		rc->dir_x = -1;
		rc->dir_y = 0;
		rc->plane_x = 0;
		rc->plane_y = 0.66;
	}
	else if (data->map[(int)player->y][(int)player->x] == 'E')
	{
		rc->dir_x = 0;
		rc->dir_y = 1;
		rc->plane_x = 0.66;
		rc->plane_y = 0;
	}
	set_rc_data2(data, player, rc);
}
