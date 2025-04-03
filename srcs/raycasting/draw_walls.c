/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:01:15 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/03 04:11:37 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// https://permadi.com/1996/05/ray-casting-tutorial-7/
// x_line: x coordinates of vertical grid lines
// xa: x distance between 2 adjacent ray intersections with y_lines
float   ft_dist_vertical(t_data *data, t_player p, float angle)
{
    int     x_line;
    int     y_line;
    int     xa;
    int     ya;
    float   dist;

    ft_get_y_frame(p, &y_line, &ya);
    x_line = p.x + (p.y - y_line) / tan(angle);
    if (p.angle <= M_PI_2 || p.angle >= 3 * M_PI_2)
        xa = BLOCK_SIZE / tan(angle);
    else
        xa = -BLOCK_SIZE / tan(angle);
    while (!ft_is_colission(x_line, y_line, data->map))
    {
        x_line += xa;
        y_line += ya;
    }
    return (f_absf(p.x - x_line) / cos(angle));
}

// https://permadi.com/1996/05/ray-casting-tutorial-7/
// y_line: y coordinates of horizontal grid lines
// ya: y distance between 2 adjacent ray intersections with x_lines
float   ft_dist_horizontal(t_data *data, t_player p, float angle)
{
    int     x_line;
    int     y_line;
    int     xa;
    int     ya;
    float   dist;

    ft_get_x_frame(p, &x_line, &xa);
    y_line = p.y + (p.x - x_line) * tan(angle);
    if (p.angle >= M_PI)
        ya = BLOCK_SIZE * tan(angle);
    else
        ya = -BLOCK_SIZE * tan(angle);
    while (!ft_is_colission(x_line, y_line, data->map))
    {
        x_line += xa;
        y_line += ya;
    }
    return (f_absf(p.x - x_line) / cos(angle));
}

float   ft_raytrace(t_data *data, t_player player, float angle)
{
    float   dist_vertical;
    float   dist_horizontal;

    dist_vertical = ft_dist_vertical(data, player, player.angle + angle);
    dist_horizontal = ft_dist_horizontal(data, player, player.angle + angle);
    return (fminf(dist_vertical, dist_horizontal) * cos(angle));
}

void    ft_draw_wall_slice(t_data *data, t_img *img, float *section, int x)
{
    int     y_end;
    int     y_start;
    float   distance;
    float   wall_height;

    distance = ft_raytrace(data, data->player, section[x]);
    wall_height = (BLOCK_SIZE / distance) * data->proj_dist;
    y_start = (data->wnd_h - wall_height) / 2;
    y_end = y_start + wall_height;
    while (y_start < y_end)
        ft_putpxl(img, x, y_start++, 0x0000ff);
}
