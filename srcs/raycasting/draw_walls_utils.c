/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:42:46 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/05 15:50:06 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float   ft_absf(float val)
{
    return (val * (val >= 0) - val * (val < 0));
}

void ft_update_players_pos_and_dir(t_data **data, t_player *player)
{
	if ((*data)->keyboard.w_down)
	{
        ft_action_w();
	}
	if ((*data)->keyboard.s_down)
	{
        ft_action_s();
	}
	if ((*data)->keyboard.a_down)
	{
        ft_action_a();
	}
	if ((*data)->keyboard.d_down)
	{
        ft_action_d();
	}
}
