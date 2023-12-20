/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:20:25 by niromano          #+#    #+#             */
/*   Updated: 2023/12/20 12:54:46 by niromano         ###   ########.fr       */
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

typedef struct s_data
{
	int		fd;
	char	*texture_n;
	char	*texture_s;
	char	*texture_w;
	char	*texture_e;
	int		texture_f;
	int		texture_c;
	char	**map;
	t_list	*buffer;
}	t_data;

void	parsing(int argc, char **argv, t_data *data);
void	set_data_null(t_data *data);
void	take_map(t_data *data);

void	clear_mat(char **mat);
void	clear_all(t_data *data);
void	clear_all_error(t_data *data, char *error);

#endif