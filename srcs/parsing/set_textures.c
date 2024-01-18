/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:00:11 by niromano          #+#    #+#             */
/*   Updated: 2024/01/18 09:59:21 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clear_raw(t_mlx *mlx)
{
	free(mlx->data->raw.texture_n);
	mlx->data->raw.texture_n = NULL;
	free(mlx->data->raw.texture_s);
	mlx->data->raw.texture_s = NULL;
	free(mlx->data->raw.texture_w);
	mlx->data->raw.texture_w = NULL;
	free(mlx->data->raw.texture_e);
	mlx->data->raw.texture_e = NULL;
}

char	*get_hexacode(t_mlx *mlx, int code, char *base)
{
	char	*hexacode;
	int		i;

	i = 7;
	hexacode = malloc(sizeof(char) * 9);
	if (hexacode == NULL)
		clear_all_failed(mlx, "Malloc Failed !\n");
	while (code > 0)
	{
		hexacode[i] = base[code % 16];
		code = code / 16;
		i --;
	}
	while (i > -1)
	{
		hexacode[i] = '0';
		i --;
	}
	hexacode[0] = '0';
	hexacode[1] = 'x';
	hexacode[8] = '\0';
	return (hexacode);
}

void	set_hexacode(t_mlx *mlx)
{
	mlx->data->textures.texture_f = get_hexacode(mlx,
			mlx->data->raw.texture_f, "0123456789abcdef");
	if (mlx->data->textures.texture_f == NULL)
		clear_all_failed(mlx, "Error\n");
	mlx->data->textures.texture_c = get_hexacode(mlx,
			mlx->data->raw.texture_c, "0123456789abcdef");
	if (mlx->data->textures.texture_c == NULL)
		clear_all_failed(mlx, "Error\n");
}

void	set_textures(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->data->textures.texture_n = mlx_xpm_file_to_image(mlx->mlx,
			mlx->data->raw.texture_n, &x, &y);
	if (mlx->data->textures.texture_n == NULL)
		clear_all_failed(mlx, "Error\n");
	mlx->data->textures.texture_s = mlx_xpm_file_to_image(mlx->mlx,
			mlx->data->raw.texture_s, &x, &y);
	if (mlx->data->textures.texture_s == NULL)
		clear_all_failed(mlx, "Error\n");
	mlx->data->textures.texture_w = mlx_xpm_file_to_image(mlx->mlx,
			mlx->data->raw.texture_w, &x, &y);
	if (mlx->data->textures.texture_w == NULL)
		clear_all_failed(mlx, "Error\n");
	mlx->data->textures.texture_e = mlx_xpm_file_to_image(mlx->mlx,
			mlx->data->raw.texture_e, &x, &y);
	if (mlx->data->textures.texture_e == NULL)
		clear_all_failed(mlx, "Error\n");
	set_hexacode(mlx);
	clear_raw(mlx);
}
