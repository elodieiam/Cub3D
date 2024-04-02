/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:55:47 by niromano          #+#    #+#             */
/*   Updated: 2024/04/02 10:45:29 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	fill_texture_ns(int value, char *tmp, t_game *game)
{
	if (value == 1)
	{
		if (game->data.textures.raw_n != NULL)
		{
			free(tmp);
			clear_all_failed(game, "Duplicate North texture in file\n");
		}
		game->data.textures.raw_n = tmp;
	}
	else if (value == 2)
	{
		if (game->data.textures.raw_s != NULL)
		{
			free(tmp);
			clear_all_failed(game, "Duplicate South texture in file\n");
		}
		game->data.textures.raw_s = tmp;
	}
}

static void	fill_texture_we(int value, char *tmp, t_game *game)
{
	if (value == 3)
	{
		if (game->data.textures.raw_w != NULL)
		{
			free(tmp);
			clear_all_failed(game, "Duplicate West texture in file\n");
		}
		game->data.textures.raw_w = tmp;
	}
	else if (value == 4)
	{
		if (game->data.textures.raw_e != NULL)
		{
			free(tmp);
			clear_all_failed(game, "Duplicate East texture in file\n");
		}
		game->data.textures.raw_e = tmp;
	}
}

static void	fill_texture_fc(int value, char *tmp, t_game *game)
{
	if (value == 5)
	{
		if (game->data.textures.color_f != -1)
		{
			free(tmp);
			clear_all_failed(game, "Duplicate Floor texture in file\n");
		}
		game->data.textures.color_f = get_rgb(tmp, game);
	}
	else if (value == 6)
	{
		if (game->data.textures.color_c != -1)
		{
			free(tmp);
			clear_all_failed(game, "Duplicate Ceiling texture in file\n");
		}
		game->data.textures.color_c = get_rgb(tmp, game);
	}
}

void	fill_texture(char *s, int value, t_game *game)
{
	char	*tmp;

	tmp = ft_strtrim(s, " \f\n\r\t\v");
	if (tmp == NULL)
		clear_all_failed(game, "Malloc Failed !\n");
	if (value == 1 || value == 2)
		fill_texture_ns(value, tmp, game);
	else if (value == 3 || value == 4)
		fill_texture_we(value, tmp, game);
	else if (value == 5 || value == 6)
		fill_texture_fc(value, tmp, game);
}
