/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:56:45 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 10:53:09 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	what_texture(t_raycast *rc)
{
	if (rc->side == 0)
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
	return (0);
}

void	get_and_put(t_game *game, t_raycast *rc, int x, int text_x)
{
	int		y;
	int		color;
	int		text_y;
	double	step;
	double	text_pos;

	step = 1.0 * rc->text_height / rc->lineheight;
	text_pos = (rc->drawstart - SCREEN_Y / 2 + rc->lineheight / 2) * step;
	rc->side = what_texture(rc);
	y = rc->drawstart;
	while (y < rc->drawend)
	{
		text_y = (int)text_pos & (rc->text_height - 1);
		text_pos += step;
		color = get_color(game, rc->side, text_x, text_y);
		my_mlx_pixel_put(&game->mlx.img_buf, x, y, color);
		y ++;
	}
}

void	print_texture(t_game *game, t_raycast *rc, int x)
{
	double	wall;
	int		text_x;

	init_text_len(game->data.textures, rc, what_texture(rc));
	if (rc->side == 0)
		wall = rc->pos_y + rc->perpwalldist * rc->raydir_y;
	else
		wall = rc->pos_x + rc->perpwalldist * rc->raydir_x;
	wall -= floor((wall));
	text_x = (int)(wall * (double)(rc->text_width));
	if (rc->side == 0 && rc->raydir_x > 0)
		text_x = rc->text_width - text_x - 1;
	if (rc->side == 1 && rc->raydir_y < 0)
		text_x = rc->text_width - text_x - 1;
	get_and_put(game, rc, x, text_x);
}
