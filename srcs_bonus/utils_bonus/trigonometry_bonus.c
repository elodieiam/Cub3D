/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigonometry_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niromano <niromano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:59:18 by niromano          #+#    #+#             */
/*   Updated: 2024/01/30 12:33:20 by niromano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3d_bonus.h"

float	cos_pov(t_player *player)
{
	return (cosf(player->pov * (RAD)));
}

float	sin_pov(t_player *player)
{
	return (sinf(player->pov * (RAD)));
}
