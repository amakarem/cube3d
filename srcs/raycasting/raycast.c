/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:51:40 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/04 18:06:11 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// incr = (30) - 29.xxx in rad
// (30) to (-30) => ((FOV / 2) - x * (FOV / (*data)->wnd_w - 1))
// if player dir = north (90 degrees) && FOV = 60 degrees => section[0] = 120 degrees && section[width - 1] = 60 degrees. (In radiant).
int	ft_raycast(t_data **data)
{
    int     x;
    float   incr;
    float   fov_rad_2;
    float   section[(*data)->wnd_w];

    ft_clean_window(*data);
    ft_update_players_pos_and_dir(data, (*data)->player.angle);
    x = 0;
    fov_rad_2 = ((float)FOV / 2) * (M_PI / 180);
    incr = ((float)FOV / ((*data)->wnd_w - 1)) * (M_PI / 180);
    while (x < (*data)->wnd_w)
    {
        section[x] = (fov_rad_2 - incr * x) + (*data)->player.angle;
        x++;
    }
    x = 0;
    while (x < (*data)->wnd_w)
    {
        ft_draw_wall_slice(*data, &(*data)->buffer, section, x);
        x++;
    }
	mlx_put_image_to_window((*data)->mlx_ptr, (*data)->mlx_win, (*data)->buffer->img, 0, 0);
	return (1);
}
