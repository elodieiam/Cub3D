/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:58:28 by niromano          #+#    #+#             */
/*   Updated: 2024/03/13 11:12:14 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_BONUS_H
# define DATA_BONUS_H

# define SCREEN_X 1280
# define SCREEN_Y 720

# define PI 3.14159265358
# define RAD PI/180

# define L_BOX 20

typedef struct s_buf
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_x;
	int		img_y;
}	t_buf;

typedef struct s_textures
{
	char	*raw_n;
	char	*raw_s;
	char	*raw_w;
	char	*raw_e;
	char	*raw_d;
	int		color_f;
	int		color_c;
	t_buf	texture_n;
	t_buf	texture_s;
	t_buf	texture_w;
	t_buf	texture_e;
	t_buf	texture_d;
}	t_textures;

typedef struct s_data
{
	int			fd;
	char		**map;
	int			map_x;
	int			map_y;
	t_textures	textures;
	t_list		*buffer;
}	t_data;

#endif