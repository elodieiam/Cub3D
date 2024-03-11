/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cam_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:06:53 by niromano          #+#    #+#             */
/*   Updated: 2024/03/11 15:15:07 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

// void	mouse(t_mlx *mlx, t_player *player, t_raycast *rc)
// {
// 	int	x;
// 	int	y;

// 	(void)rc;
// 	mlx_mouse_get_pos(mlx->mlx_ptr, mlx->win, &x, &y);
// 	if (x == 0)
// 		x = 360 * 2;
// 	while (x > 360 * 2)
// 		x -= 360 * 2;
// 	player->pov = x / 2;
// 	// rc->dir_x = -cos_pov(player);
// 	// rc->dir_y = sin_pov(player);
// 	mlx_mouse_move(mlx->mlx_ptr, mlx->win, player->pov * 2, 0);
// }

void	mouse(t_mlx *mlx, t_player *player, t_raycast *rc)
{
	int	x;
	int	y;
	double	olddir_x;
	double	oldplane_x;

	(void)player;
	mlx_mouse_get_pos(mlx->mlx_ptr, mlx->win, &x, &y);
	olddir_x = rc->dir_x;
	oldplane_x = rc->plane_x;
	if (x < 360)
	{
		rc->dir_x = rc->dir_x * cos(ROT_SPEED) - rc->dir_y * sin(ROT_SPEED);
		rc->dir_y = olddir_x * sin(ROT_SPEED) + rc->dir_y * cos(ROT_SPEED);
		rc->plane_x = rc->plane_x * cos(ROT_SPEED) - rc->plane_y * sin(ROT_SPEED);
		rc->plane_y = oldplane_x * sin(ROT_SPEED) + rc->plane_y * cos(ROT_SPEED);
		atan_pov(player, rc);
	}
	else if (x > 360)
	{
		rc->dir_x = rc->dir_x * cos(-ROT_SPEED) - rc->dir_y * sin(-ROT_SPEED);
		rc->dir_y = olddir_x * sin(-ROT_SPEED) + rc->dir_y * cos(-ROT_SPEED);
		rc->plane_x = rc->plane_x * cos(-ROT_SPEED) - rc->plane_y * sin(-ROT_SPEED);
		rc->plane_y = oldplane_x * sin(-ROT_SPEED) + rc->plane_y * cos(-ROT_SPEED);
		atan_pov(player, rc);
	}
	mlx_mouse_move(mlx->mlx_ptr, mlx->win, 360, 0);
}

void	move_cam(t_mlx *mlx, t_player *player, t_raycast *rc)
{
	double	olddir_x;
	double	oldplane_x;

	(void)mlx;
	if (player->keys.left == 0)
	{
		olddir_x = rc->dir_x;
		oldplane_x = rc->plane_x;
		rc->dir_x = rc->dir_x * cos(ROT_SPEED) - rc->dir_y * sin(ROT_SPEED);
		rc->dir_y = olddir_x * sin(ROT_SPEED) + rc->dir_y * cos(ROT_SPEED);
		rc->plane_x = rc->plane_x * cos(ROT_SPEED) - rc->plane_y * sin(ROT_SPEED);
		rc->plane_y = oldplane_x * sin(ROT_SPEED) + rc->plane_y * cos(ROT_SPEED);
		atan_pov(player, rc);
	}
	if (player->keys.right == 0)
	{
		olddir_x = rc->dir_x;
		oldplane_x = rc->plane_x;
		rc->dir_x = rc->dir_x * cos(-ROT_SPEED) - rc->dir_y * sin(-ROT_SPEED);
		rc->dir_y = olddir_x * sin(-ROT_SPEED) + rc->dir_y * cos(-ROT_SPEED);
		rc->plane_x = rc->plane_x * cos(-ROT_SPEED) - rc->plane_y * sin(-ROT_SPEED);
		rc->plane_y = oldplane_x * sin(-ROT_SPEED) + rc->plane_y * cos(-ROT_SPEED);
		atan_pov(player, rc);
	}
	if (player->keys.mouse == 0)
		mouse(mlx, player, rc);
}
