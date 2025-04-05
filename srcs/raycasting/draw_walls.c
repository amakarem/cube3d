/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:01:15 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/05 20:43:10 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// casting a ray from player in rayDirection (x/y).
// using DDA for incrementing the current x/y position.
// looking for wall colissions on either a horizontal or vertical grid line.
// sideDist: distance from current position to next x/y grid line.
// mapX/Y: current grid cell being checked for wall hit.
// deltaDist: distance the ray travels to go from one x/y-side to the next.
// returns information about the wall distance
// (perpendicular to the camera plane) and the wall side (N, S, E, W).
// Raycasting Tutorial on: https://lodev.org/cgtutor/raycasting.html
t_rayhit   ft_raytrace(t_data *data, t_player player, float *rayDir)
{
    int         side;
    t_dda       dda;

    ft_get_dda(&dda, rayDir, player);
    while (data->map[dda.mapY][dda.mapX] != '1')
    {
        if (dda.sideDistX < dda.sideDistY)
        {
            dda.sideDistX += dda.deltaDistX;
            dda.mapX += dda.stepX;
            side = 0;
        }
        else
        {
            dda.sideDistY += dda.deltaDistY;
            dda.mapY += dda.stepY;
            side = 1;
        }
    }
    return (ft_rayhit(dda, side, rayDir));
}

void ft_draw_ceiling_slice(t_data *data, t_img **img, int x, int y_start)
{
    int y;

    y = 0;
    while (y < y_start)
        ft_putpxl(img, x, y++, data->ceiling_color);
}

void ft_draw_floor_slice(t_data *data, t_img **img, int x, int y_end)
{
    while (y_end < data->wnd_h)
        ft_putpxl(img, x, y_end++, data->floor_color);
}

// Raycasting Tutorial on: https://lodev.org/cgtutor/raycasting.html
void    ft_draw_wall_slice(t_data *data, t_img **img, float **rayDir, int x)
{
    int         y_start;
    int         y_end;
    int         wall_height;
    t_rayhit    rayhit;

    rayhit = ft_raytrace(data, data->player, rayDir[x]);
    wall_height = data->wnd_h / rayhit.distance;
    y_start = (data->wnd_h - wall_height) / 2;
    if (y_start < 0)
        y_start = 0;
    y_end = (data->wnd_h + wall_height) / 2;
    if (y_end >= data->wnd_h)
        y_end = data->wnd_h - 1;
    ft_draw_floor_slice(data, img, x, y_end);
    ft_draw_ceiling_slice(data, img, x, y_start);
    while (y_start < y_end)
    {
        ft_putpxl(img, x, y_start, ft_get_tex_col(data, rayhit, x, y_start));
        y_start++;
    }
}
