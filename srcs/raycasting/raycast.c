/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:51:40 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/05 14:11:07 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// cameraX is the x coordinate on the camera plane of the current x coordinate on the screen
// rayDir vector goes from -1 (left edge) to 1 (right edge) of the window with x/y coordinates
int	ft_raycast(t_data **data)
{
    int     x;
    float   cameraX;
    float   rayDir[(*data)->wnd_w][2];

    ft_clean_window(*data);
    ft_update_players_pos_and_dir(data, &(*data)->player);
    x = 0;
    while (x < (*data)->wnd_w)
    {
        cameraX = (2 * x / (*data)->wnd_w) - 1;
        rayDir[x][0] = (*data)->player.dirX + (*data)->player.planeX * cameraX;
        rayDir[x][1] = (*data)->player.dirY + (*data)->player.planeY * cameraX;
        x++;
    }
    x = 0;
    while (x < (*data)->wnd_w)
    {
        ft_draw_wall_slice(*data, &(*data)->buffer, rayDir, x);
        x++;
    }
	mlx_put_image_to_window((*data)->mlx_ptr, (*data)->mlx_win, (*data)->buffer->img, 0, 0);
	return (1);
}
