/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:42:46 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/04 16:58:56 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float   ft_absf(float val)
{
    return (val * (val >= 0) - val * (val < 0));
}

float	ft_x_dir(float dist, float angle)
{
	if ((dist >= 0 && angle > M_PI_2 && angle < M_3_PI_2) || (dist < 0 && (angle <= M_PI_2 || angle >= M_3_PI_2)))
		return (-dist);
	return (dist);	
}

float	ft_y_dir(float dist, float angle)
{
	if ((angle < M_PI && dist >= 0) || (angle >= M_PI && dist < 0))
		return (-dist);
	return (dist);	
}

void ft_update_players_pos_and_dir(t_data **data, float angle)
{
	if ((*data)->keyboard.w_down)
	{
        (*data)->player.y += sin(angle) * SPEED;
		(*data)->player.x += cos(angle) * SPEED;
	}
	if ((*data)->keyboard.s_down)
	{
        (*data)->player.y -= sin(angle) * SPEED;
		(*data)->player.x -= cos(angle) * SPEED;
	}
	if ((*data)->keyboard.a_down)
	{
        (*data)->player.y += sin(angle) * SPEED;
        (*data)->player.x -= cos(angle) * SPEED;
	}
	if ((*data)->keyboard.d_down)
	{
        (*data)->player.y -= sin(angle) * SPEED;
        (*data)->player.x += cos(angle) * SPEED;
	}
}
