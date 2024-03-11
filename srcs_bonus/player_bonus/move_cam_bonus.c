/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:06:53 by niromano          #+#    #+#             */
/*   Updated: 2024/03/11 15:41:40 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

static void	move_cam_left(t_player *player, t_raycast *rc, int mouse)
{
	double	olddir_x;
	double	oldplane_x;
	double	accel;

	accel = 0;
	if (mouse == 1)
		accel = 0.015;
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

static void	move_cam_right(t_player *player, t_raycast *rc, int mouse)
{
	double	olddir_x;
	double	oldplane_x;
	double	accel;

	accel = 0;
	if (mouse == 1)
		accel = 0.015;
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

void	mouse(t_mlx *mlx, t_player *player, t_raycast *rc)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(mlx->mlx_ptr, mlx->win, &x, &y);
	if (x < 360)
		move_cam_left(player, rc, 1);
	else if (x > 360)
		move_cam_right(player, rc, 1);
	mlx_mouse_move(mlx->mlx_ptr, mlx->win, 360, 0);
}

void	move_cam(t_mlx *mlx, t_player *player, t_raycast *rc)
{
	if (player->keys.left == 0)
		move_cam_left(player, rc, 0);
	if (player->keys.right == 0)
		move_cam_right(player, rc, 0);
	if (player->keys.mouse == 0)
		mouse(mlx, player, rc);
}
