/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:51:40 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/06 14:50:05 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// Raycasting Tutorial on: https://lodev.org/cgtutor/raycasting.html
//
// one ray for each x coordinate on the screen
// => representing the Field of View (FOV) of the player
//
// cameraX is the x coordinate on the camera plane of the current x -
// coordinate on the screen and goes from -1 to +1 (left to right) (normalized).
//
// rayDir (vector) = players_dir + plane * cameraX
// camera plane is always perpendicular on the players direction.
int	ft_raycast(t_data *data)
{
    int         x;
    float       cameraX;
    float       rayDir[data->wnd_w][2];

    x = 0;
    while (x < data->wnd_w)
    {
        cameraX = (2 * x / data->wnd_w) - 1;
        rayDir[x][0] = data->player.dirX + data->player.planeX * cameraX;
        rayDir[x][1] = data->player.dirY + data->player.planeY * cameraX;
        ft_draw_slice(data, &data->buffer, rayDir, x);
        x++;
    }
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->buffer->img, 0, 0);
	return (1);
}
