/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:20:25 by niromano          #+#    #+#             */
/*   Updated: 2024/01/30 16:04:20 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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

# include "data_bonus.h"
# include "player_bonus.h"

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
	void	*mlx_ptr;
	void	*win;
	t_buf	img_buf;
	t_buf	img_map;
	t_coord	put_line_coord;
}	t_mlx;

typedef struct s_game
{
	t_mlx		mlx;
	t_data		data;
	t_player	player;
}	t_game;

void	set_game_null(t_game *game);
void	set_mlx_null(t_mlx *mlx);
void	set_data_null(t_data *data);

void	parsing(int argc, char **argv, t_game *game);
int		ft_strlen_mat(char **mat);
int		get_rgb(char *tmp, t_game *game);
void	take_texture(t_game *game);
void	fill_texture(char *s, int value, t_game *game);
void	take_map(t_game *game);
void	check_map(t_game *game);
char	*fill_map(char *s, int len);
void	search_player(t_game *game);
void	check_border(t_game *game);
void	check_door(t_game *game);
void	set_textures(t_game *game);

void	my_mlx_pixel_put(t_buf *buf, int x, int y, int color);
int		my_mlx_pixel_get(t_buf *buf, int x, int y);
void	put_line(t_mlx *mlx, t_buf *mlx_img, int color);
float	cos_pov(t_player *player);
float	sin_pov(t_player *player);

int		game_cub(t_game *game);

int		get_hook(int key, t_game *game);
int		let_hook(int key, t_player *player);

void	background(t_mlx *mlx, t_data *data);
void	minimap(t_mlx *mlx, t_player *player, char **map);
void	insert_minimap(t_mlx *mlx, t_player *player);
void	move_player(t_data *data, t_player *player);
int		collision(t_data *data, t_player *player, char key, char axis);
int		dir_collision(t_data *data, t_player *player, int axis, int dir);
void	move_cam(t_mlx *mlx, t_player *player);
void	door_gestion(t_game *game);

void	clear_list(t_list *list);
void	clear_mat(char **mat);
int		clear_all_success(t_game *game);
void	clear_all_failed(t_game *game, char *error);

#endif