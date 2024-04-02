/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:06:53 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 10:53:41 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	move_cam_left(t_player *player, t_raycast *rc)
{
	double	olddir_x;
	double	oldplane_x;
	double	accel;

	accel = 0;
	olddir_x = rc->dir_x;
	oldplane_x = rc->plane_x;
	rc->dir_x = rc->dir_x * cos(ROT_SPEED + accel)
		- rc->dir_y * sin(ROT_SPEED + accel);
	rc->dir_y = olddir_x * sin(ROT_SPEED + accel)
		+ rc->dir_y * cos(ROT_SPEED + accel);
	rc->plane_x = rc->plane_x * cos(ROT_SPEED + accel)
		- rc->plane_y * sin(ROT_SPEED + accel);
	rc->plane_y = oldplane_x * sin(ROT_SPEED + accel)
		+ rc->plane_y * cos(ROT_SPEED + accel);
	atan_pov(player, rc);
}

static void	move_cam_right(t_player *player, t_raycast *rc)
{
	double	olddir_x;
	double	oldplane_x;
	double	accel;

	accel = 0;
	olddir_x = rc->dir_x;
	oldplane_x = rc->plane_x;
	rc->dir_x = rc->dir_x * cos(-ROT_SPEED - accel)
		- rc->dir_y * sin(-ROT_SPEED - accel);
	rc->dir_y = olddir_x * sin(-ROT_SPEED - accel)
		+ rc->dir_y * cos(-ROT_SPEED - accel);
	rc->plane_x = rc->plane_x * cos(-ROT_SPEED - accel)
		- rc->plane_y * sin(-ROT_SPEED - accel);
	rc->plane_y = oldplane_x * sin(-ROT_SPEED - accel)
		+ rc->plane_y * cos(-ROT_SPEED - accel);
	atan_pov(player, rc);
}

void	move_cam(t_player *player, t_raycast *rc)
{
	if (player->keys.left == 0)
		move_cam_left(player, rc);
	if (player->keys.right == 0)
		move_cam_right(player, rc);
}
