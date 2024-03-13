/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:34:50 by niromano          #+#    #+#             */
/*   Updated: 2024/03/13 15:51:51 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

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
	else if (data->map[(int)player->y][(int)player->x] == 'W')
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
}

void	init_text_len(t_textures text, t_raycast *rc, int texture)
{
	if (texture == TEXT_N)
	{
		rc->text_height = text.texture_n.img_y;
		rc->text_width = text.texture_n.img_x;
	}
	else if (texture == TEXT_S)
	{
		rc->text_height = text.texture_s.img_y;
		rc->text_width = text.texture_s.img_x;
	}
	else if (texture == TEXT_W)
	{
		rc->text_height = text.texture_w.img_y;
		rc->text_width = text.texture_w.img_x;
	}
	else if (texture == TEXT_E)
	{
		rc->text_height = text.texture_e.img_y;
		rc->text_width = text.texture_e.img_x;
	}
	else if (texture == TEXT_D)
	{
		rc->text_height = text.texture_d.img_y;
		rc->text_width = text.texture_d.img_x;
	}
}

int	what_texture(t_game *game, t_raycast *rc, int side)
{
	if (game->data.map[rc->map_x][rc->map_y] == 'C')
		return (TEXT_D);
	else if (side == 0)
	{
		if (rc->step_x < 0)
			return (TEXT_N);
		else
			return (TEXT_S);
	}
	else
	{
		if (rc->step_y < 0)
			return (TEXT_W);
		else
			return (TEXT_E);
	}
	return (-1);
}

void	print_texture(t_game *game, t_raycast *rc, int side, int x)
{
	double	wall;
	int		color;

	init_text_len(game->data.textures, rc, what_texture(game, rc, side));
	if (side == 0)
		wall = rc->pos_y + rc->perpwalldist * rc->raydir_y;
	else
		wall = rc->pos_x + rc->perpwalldist * rc->raydir_x;
	wall -= floor((wall));
	int texX = (int)(wall * (double)(rc->text_width));
	if (side == 0 && rc->raydir_x > 0)
		texX = rc->text_width - texX - 1;
	if (side == 1 && rc->raydir_y < 0)
		texX = rc->text_width - texX - 1;
	double step = 1.0 * rc->text_height / rc->lineheight;
	double texPos = (rc->drawstart - SCREEN_Y / 2 + rc->lineheight / 2) * step;
	side = what_texture(game, rc, side);
	for (int y = rc->drawstart; y < rc->drawend; y++)
	{
		int texY = (int)texPos & (rc->text_height - 1);
		texPos += step;
		if (side == TEXT_N)
			color = my_mlx_pixel_get(&game->data.textures.texture_n, texX, texY);
		else if (side == TEXT_S)
			color = my_mlx_pixel_get(&game->data.textures.texture_s, texX, texY);
		else if (side == TEXT_W)
			color = my_mlx_pixel_get(&game->data.textures.texture_w, texX, texY);
		else if (side == TEXT_E)
			color = my_mlx_pixel_get(&game->data.textures.texture_e, texX, texY);
		else if (side == TEXT_D)
			color = my_mlx_pixel_get(&game->data.textures.texture_d, texX, texY);
		my_mlx_pixel_put(&game->mlx.img_buf, x, y, color);
	}
}

void	cub3d(t_game *game, t_raycast *rc)
{
	int	hit;
	int	side;
	int	x;

	x = 0;
	while (x < SCREEN_X)
	{
		hit = 0;
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
		while (hit == 0)
		{
			if (rc->sidedist_x < rc->sidedist_y)
			{
				rc->sidedist_x += rc->deltadist_x;
				rc->map_x += rc->step_x;
				side = 0;
			}
			else
			{
				rc->sidedist_y += rc->deltadist_y;
				rc->map_y += rc->step_y;
				side = 1;
			}
			if (game->data.map[rc->map_x][rc->map_y] == '1' || game->data.map[rc->map_x][rc->map_y] == 'C')
				hit = 1;
		}
		if (side == 0)
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
		print_texture(game, rc, side, x);
		x ++;
	}
}
