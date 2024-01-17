/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:20:25 by niromano          #+#    #+#             */
/*   Updated: 2024/01/17 06:54:20 by niromano         ###   ########.fr       */
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

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

typedef struct s_raw_textures
{
	char	*texture_n;
	char	*texture_s;
	char	*texture_w;
	char	*texture_e;
	int		texture_f;
	int		texture_c;
}	t_raw_textures;

typedef struct s_textures
{
	void	*texture_n;
	void	*texture_s;
	void	*texture_w;
	void	*texture_e;
	char	*texture_f;
	char	*texture_c;
}	t_textures;

typedef struct s_data
{
	int				fd;
	t_raw_textures	raw;
	t_textures		textures;
	char			**map;
	t_list			*buffer;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	*data;
}	t_mlx;

void	parsing(int argc, char **argv, t_data *data);
void	set_data_null(t_data *data);
void	take_map(t_data *data);

void	clear_mat(char **mat);
void	clear_data(t_data *data);
void	clear_all_error(t_data *data, char *error);

#endif