/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:34:50 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 11:17:05 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_rc(t_game *game, t_raycast *rc, int x)
{
	rc->pos_x = game->player.y;
	rc->pos_y = game->player.x;
	rc->map_x = (int)game->player.y;
	rc->map_y = (int)game->player.x;
	rc->camera_x = 2 * x / (double)SCREEN_X - 1;
	rc->raydir_x = rc->dir_x + rc->plane_x * rc->camera_x;
	rc->raydir_y = rc->dir_y + rc->plane_y * rc->camera_x;
	if (rc->raydir_x == 0)
		rc->deltadist_x = pow(10, 30);
	else
		rc->deltadist_x = fabs(1 / rc->raydir_x);
	if (rc->raydir_y == 0)
		rc->deltadist_y = pow(10, 30);
	else
		rc->deltadist_y = fabs(1 / rc->raydir_y);
}

static void	set_step(t_raycast *rc)
{
	if (rc->raydir_x < 0)
	{
		rc->step_x = -1;
		rc->sidedist_x = (rc->pos_x - rc->map_x) * rc->deltadist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->sidedist_x = (rc->map_x + 1.0 - rc->pos_x) * rc->deltadist_x;
	}
	if (rc->raydir_y < 0)
	{
		rc->step_y = -1;
		rc->sidedist_y = (rc->pos_y - rc->map_y) * rc->deltadist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->sidedist_y = (rc->map_y + 1.0 - rc->pos_y) * rc->deltadist_y;
	}
}

static int	while_hit(t_game *game, t_raycast *rc)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rc->sidedist_x < rc->sidedist_y)
		{
			rc->sidedist_x += rc->deltadist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->sidedist_y += rc->deltadist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (rc->map_x < 0 || rc->map_x == game->data.map_y
			|| rc->map_y < 0 || rc->map_y == game->data.map_x)
			hit = 2;
		else if (game->data.map[rc->map_x][rc->map_y] == '1')
			hit = 1;
	}
	return (hit);
}

void	cub3d(t_game *game, t_raycast *rc)
{
	int	x;

	x = 0;
	while (x < SCREEN_X)
	{
		set_rc(game, rc, x);
		set_step(rc);
		if (while_hit(game, rc) == 1)
		{
			if (rc->side == 0)
				rc->perpwalldist = (rc->sidedist_x - rc->deltadist_x);
			else
				rc->perpwalldist = (rc->sidedist_y - rc->deltadist_y);
			rc->lineheight = (int)(SCREEN_Y / rc->perpwalldist);
			rc->drawstart = -rc->lineheight / 2 + SCREEN_Y / 2;
			if (rc->drawstart < 0)
				rc->drawstart = 0;
			rc->drawend = rc->lineheight / 2 + SCREEN_Y / 2;
			if (rc->drawend >= SCREEN_Y)
				rc->drawend = SCREEN_Y - 1;
			print_texture(game, rc, x);
		}
		x ++;
	}
}
