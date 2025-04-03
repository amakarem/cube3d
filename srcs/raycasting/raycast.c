/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:51:40 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/03 13:00:48 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// incr = (30) - 29.xxx in rad
// (30) to (-30) => ((FOV / 2) - x * (FOV / (*data)->wnd_w - 1))
int	ft_raycast(t_data **data)
{
    int     x;
    float   incr;
    float   fov_rad_2;
    float   section[(*data)->wnd_w];
    
    ft_clean_window(*data);
    x = 0;
    fov_rad_2 = FOV * (180 / M_PI) / 2;
    incr = (FOV / ((*data)->wnd_w - 1)) * (180 / M_PI);
    while (x < (*data)->wnd_w)
    {
        section[x] = (fov_rad_2 - incr * x) - (*data)->player.angle;
        x++;
    }
    x = 0;
    while (x < (*data)->wnd_w)
    {
        ft_draw_wall_slice(*data, (*data)->buffer, section, x);
        x++;
    }
	return (1);
}
