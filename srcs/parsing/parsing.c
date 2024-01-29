/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 06:26:01 by niromano          #+#    #+#             */
/*   Updated: 2024/01/29 08:58:35 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	take_buffer(t_game *game)
{
	t_list	*buf;

	buf = ft_lstnew(get_next_line(game->data.fd));
	if (buf == NULL)
		clear_all_failed(game, "Malloc Failed !\n");
	while (buf->content != NULL)
	{
		if (game->data.buffer == NULL)
			game->data.buffer = buf;
		else
			ft_lstadd_back(&game->data.buffer, buf);
		buf = ft_lstnew(get_next_line(game->data.fd));
		if (buf == NULL)
			clear_all_failed(game, "Malloc Failed !\n");
	}
	ft_lstadd_back(&game->data.buffer, buf);
	close(game->data.fd);
	game->data.fd = -1;
}

void	parsing(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		clear_all_failed(game, "Bad args example : ./cub3D \"file_path\"\n");
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 5) != 0)
		clear_all_failed(game, "Bad extension example : \"*.cub\"\n");
	game->data.fd = open(argv[1], O_RDONLY);
	if (game->data.fd == -1)
		clear_all_failed(game, "Can't open the file\n");
	take_buffer(game);
	take_texture(game);
	take_map(game);
	game->data.map_x = ft_strlen(game->data.map[0]);
	game->data.map_y = ft_strlen_mat(game->data.map);
}
