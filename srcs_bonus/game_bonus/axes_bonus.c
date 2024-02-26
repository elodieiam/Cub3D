/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axes_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:32:26 by niromano          #+#    #+#             */
/*   Updated: 2024/02/26 15:03:25 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

float	sidedist(t_game *game, char axes, int pov, float i)
{
	if (axes == 'x')
	{
		while ((int)game->mlx.put_line_coord.ex / L_BOX == (int)game->player.x
			&& (int)game->mlx.put_line_coord.ey / L_BOX < game->data.map_y
			&& (int)game->mlx.put_line_coord.ey / L_BOX > -1)
		{
			i += 0.1;
			game->mlx.put_line_coord.ex = (int)(game->player.x * L_BOX + (int)(sin_pov(&game->player) * i) - (int)(cosf(pov * (RAD)) * i));
			game->mlx.put_line_coord.ey = (int)(game->player.y * L_BOX - (int)(cos_pov(&game->player) * i) - (int)(sinf(pov * (RAD)) * i));
		}
	}
	else if (axes == 'y')
	{
		while ((int)game->mlx.put_line_coord.ey / L_BOX == (int)game->player.y
			&& (int)game->mlx.put_line_coord.ex / L_BOX < game->data.map_x
			&& (int)game->mlx.put_line_coord.ex / L_BOX > -1)
		{
			i += 0.1;
			game->mlx.put_line_coord.ex = (int)(game->player.x * L_BOX + (int)(sin_pov(&game->player) * i) - (int)(cosf(pov * (RAD)) * i));
			game->mlx.put_line_coord.ey = (int)(game->player.y * L_BOX - (int)(cos_pov(&game->player) * i) - (int)(sinf(pov * (RAD)) * i));
		}
	}
	return (i);
}

float	deltadist(t_game *game, char axes, int pov, float i)
{
	int	tmp;

	if (axes == 'x')
	{
		tmp = (int)game->mlx.put_line_coord.ex / L_BOX;
		while ((int)game->mlx.put_line_coord.ex / L_BOX == tmp
			&& (int)game->mlx.put_line_coord.ey / L_BOX < game->data.map_y
			&& (int)game->mlx.put_line_coord.ey / L_BOX > -1)
		{
			game->mlx.put_line_coord.ex = (int)(game->player.x * L_BOX + (int)(sin_pov(&game->player) * i) - (int)(cosf(pov * (RAD)) * i));
			game->mlx.put_line_coord.ey = (int)(game->player.y * L_BOX - (int)(cos_pov(&game->player) * i) - (int)(sinf(pov * (RAD)) * i));
			i += 0.1;
		}
	}
	else if (axes == 'y')
	{
		tmp = (int)game->mlx.put_line_coord.ey / L_BOX;
		while ((int)game->mlx.put_line_coord.ey / L_BOX == tmp
			&& (int)game->mlx.put_line_coord.ex / L_BOX < game->data.map_x
			&& (int)game->mlx.put_line_coord.ex / L_BOX > -1)
		{
			game->mlx.put_line_coord.ex = (int)(game->player.x * L_BOX + (int)(sin_pov(&game->player) * i) - (int)(cosf(pov * (RAD)) * i));
			game->mlx.put_line_coord.ey = (int)(game->player.y * L_BOX - (int)(cos_pov(&game->player) * i) - (int)(sinf(pov * (RAD)) * i));
			i += 0.1;
		}
	}
	return (i);
}

void	axes(t_game *game, int pov, char axes)
{
	float	i;
	float	delta;

	i = 1;
	game->mlx.put_line_coord.ex = (int)(game->player.x * L_BOX + (int)(sin_pov(&game->player) * i) - (int)(cosf(pov * (RAD)) * i));
	game->mlx.put_line_coord.ey = (int)(game->player.y * L_BOX - (int)(cos_pov(&game->player) * i) - (int)(sinf(pov * (RAD)) * i));
	i = sidedist(game, axes, pov, i);
	if ((axes == 'x' && ((int)game->mlx.put_line_coord.ey / L_BOX < 0 || (int)game->mlx.put_line_coord.ey / L_BOX > game->data.map_x - 1))
			|| (axes == 'y' && ((int)game->mlx.put_line_coord.ex / L_BOX < 0 || (int)game->mlx.put_line_coord.ex / L_BOX > game->data.map_y - 1)))
		return ;
	if (game->data.map[(int)game->mlx.put_line_coord.ey / L_BOX][(int)game->mlx.put_line_coord.ex / L_BOX] == '1')
		return ;
	delta = deltadist(game, axes, pov, i) - i;
	if ((axes == 'x' && ((int)game->mlx.put_line_coord.ey / L_BOX < 0 || (int)game->mlx.put_line_coord.ey / L_BOX > game->data.map_x - 1))
		|| (axes == 'y' && ((int)game->mlx.put_line_coord.ex / L_BOX < 0 || (int)game->mlx.put_line_coord.ex / L_BOX > game->data.map_y - 1)))
			return ;
	i += delta;
	while (game->data.map[(int)game->mlx.put_line_coord.ey / L_BOX][(int)game->mlx.put_line_coord.ex / L_BOX] != '1')
	{
		// printf("%f\n", i);
		game->mlx.put_line_coord.ex = (int)(game->player.x * L_BOX + (int)(sin_pov(&game->player) * i) - (int)(cosf(pov * (RAD)) * i));
		game->mlx.put_line_coord.ey = (int)(game->player.y * L_BOX - (int)(cos_pov(&game->player) * i) - (int)(sinf(pov * (RAD)) * i));
		i += delta;
		if ((axes == 'x' && ((int)game->mlx.put_line_coord.ey / L_BOX < 0 || (int)game->mlx.put_line_coord.ey / L_BOX > game->data.map_x - 1))
			|| (axes == 'y' && ((int)game->mlx.put_line_coord.ex / L_BOX < 0 || (int)game->mlx.put_line_coord.ex / L_BOX > game->data.map_y - 1)))
				return ;
	}
}
