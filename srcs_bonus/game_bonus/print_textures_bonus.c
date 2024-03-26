/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:56:45 by niromano          #+#    #+#             */
/*   Updated: 2024/03/26 10:40:25 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

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
	else if (texture == TEXT_C || texture == TEXT_O)
	{
		rc->text_height = text.texture_d.img_y;
		rc->text_width = text.texture_d.img_x;
	}
}

int	what_texture(t_game *game, t_raycast *rc, int side)
{
	if (game->data.map[rc->map_x][rc->map_y] == 'C')
		return (TEXT_C);
	else if (side == 0)
	{
		if (rc->step_x < 0)
		{
			if (game->data.map[rc->map_x + 1][rc->map_y] == 'O')
				return (TEXT_O);
			return (TEXT_N);
		}
		else
		{
			if (game->data.map[rc->map_x - 1][rc->map_y] == 'O')
				return (TEXT_O);
			return (TEXT_S);
		}
	}
	else
	{
		if (rc->step_y < 0)
		{
			if (game->data.map[rc->map_x][rc->map_y + 1] == 'O')
				return (TEXT_O);
			return (TEXT_W);
		}
		else
		{
			if (game->data.map[rc->map_x][rc->map_y - 1] == 'O')
				return (TEXT_O);
			return (TEXT_E);
		}
	}
	return (-1);
}

static int	get_color(t_game *game, int side, int x, int y)
{
	if (side == TEXT_N)
		return (my_mlx_pixel_get(&game->data.textures.texture_n, x, y));
	else if (side == TEXT_S)
		return (my_mlx_pixel_get(&game->data.textures.texture_s, x, y));
	else if (side == TEXT_W)
		return (my_mlx_pixel_get(&game->data.textures.texture_w, x, y));
	else if (side == TEXT_E)
		return (my_mlx_pixel_get(&game->data.textures.texture_e, x, y));
	else if (side == TEXT_C)
	{
		if (game->test > game->rc.text_width)
			game->test = 0;
		x += game->test;
		while (x > game->rc.text_width - 1)
			x -= game->rc.text_width;
		game->test += 0.00001;
		return (my_mlx_pixel_get(&game->data.textures.texture_d, x, y));
	}
	else if (side == TEXT_O)
		return ((my_mlx_pixel_get(&game->data.textures.texture_d, x, y) >> 1) & 8355711);
	return (0);
}

void	print_texture(t_game *game, t_raycast *rc, int side, int x)
{
	double	wall;
	int		color;
	int		text_x;
	int		text_y;
	double	step;
	double	text_pos;
	int		y;

	init_text_len(game->data.textures, rc, what_texture(game, rc, side));
	if (side == 0)
		wall = rc->pos_y + rc->perpwalldist * rc->raydir_y;
	else
		wall = rc->pos_x + rc->perpwalldist * rc->raydir_x;
	wall -= floor((wall));
	text_x = (int)(wall * (double)(rc->text_width));
	if (side == 0 && rc->raydir_x > 0)
		text_x = rc->text_width - text_x - 1;
	if (side == 1 && rc->raydir_y < 0)
		text_x = rc->text_width - text_x - 1;
	step = 1.0 * rc->text_height / rc->lineheight;
	text_pos = (rc->drawstart - SCREEN_Y / 2 + rc->lineheight / 2) * step;
	side = what_texture(game, rc, side);
	y = rc->drawstart;
	while (y < rc->drawend)
	{
		text_y = (int)text_pos & (rc->text_height - 1);
		text_pos += step;
		color = get_color(game, side, text_x, text_y);
		my_mlx_pixel_put(&game->mlx.img_buf, x, y, color);
		y ++;
	}
}
