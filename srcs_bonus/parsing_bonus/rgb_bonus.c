/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:09:11 by niromano          #+#    #+#             */
/*   Updated: 2024/01/30 12:31:49 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

int	ft_mini_atoi(const char *nptr)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (ft_strlen(nptr) > 3)
		return (-1);
	if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			nb = nb * 10;
			nb = nb + nptr[i] - 48;
			i ++;
		}
		if (nptr[i] != '\0')
			return (-1);
		else
			return (nb);
	}
	return (-1);
}

int	check_double_comma(int comma)
{
	if (comma != 2)
		return (1);
	return (0);
}

int	check_rgb(char *tmp)
{
	int	i;
	int	nb;
	int	comma;

	i = 0;
	nb = 0;
	comma = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == ',')
		{
			if (nb > 3)
				return (1);
			else
				nb = 0;
			comma ++;
		}
		else if (ft_isdigit(tmp[i]) == 1)
			nb ++;
		else
			return (1);
		i ++;
	}
	return (check_double_comma(comma));
}

void	rgb_failed(t_game *game, char *tmp)
{
	free(tmp);
	clear_all_failed(game, "RGB code example : \"0,123,255\"\n");
}

int	get_rgb(char *tmp, t_game *game)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;

	if (check_rgb(tmp) == 1)
		rgb_failed(game, tmp);
	rgb = ft_split(tmp, ',');
	free(tmp);
	if (rgb == NULL)
		clear_all_failed(game, "Malloc Failed !\n");
	if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL)
	{
		clear_mat(rgb);
		clear_all_failed(game, "RGB code example : \"0,123,255\"\n");
	}
	r = ft_mini_atoi(rgb[0]);
	g = ft_mini_atoi(rgb[1]);
	b = ft_mini_atoi(rgb[2]);
	clear_mat(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		clear_all_failed(game, "RGB code range : [0,255]\n");
	return (r << 16 | g << 8 | b);
}
