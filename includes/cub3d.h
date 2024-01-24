/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:20:25 by niromano          #+#    #+#             */
/*   Updated: 2024/01/24 13:00:40 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include "data.h"
# include "player.h"

typedef struct s_buf
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_buf;

typedef struct s_coord
{
	float	sx;
	float	sy;
	float	ex;
	float	ey;
}	t_coord;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	*data;
	t_player	player;
	t_buf	img_buf;
	t_coord	put_line_coord;
}	t_mlx;

void	set_mlx_null(t_mlx *mlx);
void	set_data_null(t_data *data);

void	parsing(int argc, char **argv, t_mlx *mlx);
int		get_rgb(char *tmp, t_mlx *mlx);
void	take_map(t_mlx *mlx);
void	set_textures(t_mlx *mlx);

void	my_mlx_pixel_put(t_buf *buf, int x, int y, int color);
void	put_line(t_mlx *mlx, int color);

int		game(t_mlx *mlx);

void	map(t_mlx *mlx);
void	minimap(t_mlx *mlx);

void	player(t_mlx *mlx);
void	player_move(t_mlx *mlx);

void	clear_list(t_list *list);
void	clear_mat(char **mat);
int		clear_all_success(t_mlx *mlx);
void	clear_all_failed(t_mlx *mlx, char *error);

#endif