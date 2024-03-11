/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:47:37 by niromano          #+#    #+#             */
/*   Updated: 2024/03/11 15:36:43 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

# define SPEED 0.05
# define ROT_SPEED 0.02

# define NE 0
# define SE 1
# define SW 2
# define NW 3

typedef int t_bool;

typedef struct s_keys
{
	t_bool	w;
	t_bool	s;
	t_bool	a;
	t_bool	d;
	t_bool	left;
	t_bool	right;
	t_bool	mouse;
}	t_keys;

typedef struct s_player
{
	float	x;
	float	y;
	float	pov;
	t_keys	keys;
}	t_player;

#endif