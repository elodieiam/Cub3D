/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:47:37 by niromano          #+#    #+#             */
/*   Updated: 2024/01/27 13:31:50 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define SPEED 0.05

typedef int t_bool;

typedef struct s_keys
{
	t_bool	w;
	t_bool	s;
	t_bool	a;
	t_bool	d;
	t_bool	left;
	t_bool	right;
}	t_keys;

typedef struct s_player
{
	float	x;
	float	y;
	float	pov;
	t_keys	keys;
}	t_player;

#endif