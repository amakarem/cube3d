/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:02:05 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/04 17:49:45 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_is_colission(float x, float y, char **map, int h)
{
    int _x;
    int _y;

    _x = x / BLOCK_SIZE;
    _y = y / BLOCK_SIZE;
    _y = (_y < 0) * 0 + (_y >= 0 && _y < h) * _y + (_y >= h) * (h - 1);
    _x = (_x < 0) * 0 + (_x >= 0 && _x < (int)ft_strlen(map[_y])) * _x + 
    (_x >= (int)ft_strlen(map[_y])) * (int)ft_strlen(map[_y] - 1);
	// printf("cheking map[%i][%i] = %c\n", _y, _x, map[_y][_x]);
    if (map[_y][_x] == '1')
        return (1);
    return (0);
}

void    ft_get_y_frame(t_player p, float *y_line, int *ya, float angle)
{
    if (angle < M_PI)
    {
        *ya = -BLOCK_SIZE;
        *y_line = (p.y / (float)BLOCK_SIZE) * (float)BLOCK_SIZE - 1;
    }
    else
    {
        *ya = BLOCK_SIZE;
        *y_line = (p.y / (float)BLOCK_SIZE) * (float)BLOCK_SIZE + (float)BLOCK_SIZE;
    }
}

void    ft_get_x_frame(t_player p, float *x_line, int *xa, float angle)
{
    if (angle > M_PI_2 && angle < M_3_PI_2)
    {
        *xa = -BLOCK_SIZE;
        *x_line = (p.x / BLOCK_SIZE) * BLOCK_SIZE - 1;
    }
    else
    {
        *xa = BLOCK_SIZE;
        *x_line = (p.x / BLOCK_SIZE) * BLOCK_SIZE + BLOCK_SIZE;
    }
}

// https://permadi.com/1996/05/ray-casting-tutorial-7/
// Finding horizontal wall intersection
// ya: BLOCK_SIZE or -BLOCK_SIZE
// xa: x distance between 2 adjacent ray intersections with horizontal lines
// x_line: x coordinates of vertical grid lines
float   ft_dist_vertical(t_data *data, t_player p, float angle)
{
    float     	x_line;
    float     	xa;
	float 		y_line;
    int     	ya;

    ft_get_y_frame(p, &y_line, &ya, angle);
    x_line = p.x + (p.y - y_line) / tan(angle);
    xa = ft_x_dir((float)BLOCK_SIZE / tan(angle), angle);
    while (!ft_is_colission(x_line, y_line, data->map, data->map_height))
    {
        x_line += xa;
        y_line += ya;
    }
    return (ft_absf((p.x - x_line) / cos(angle)));
}

// int	ft_direct()
// https://permadi.com/1996/05/ray-casting-tutorial-7/
// Finding vertical wall intersection
// xa: BLOCK_SIZE or -BLOCK_SIZE
// ya: y distance between 2 adjacent ray intersections with vertical lines
// y_line: y coordinates of horizontal grid lines
float   ft_dist_horizontal(t_data *data, t_player p, float angle)
{
    float   x_line;
    float   y_line;
	float	ya;
    int		xa;

    ft_get_x_frame(p, &x_line, &xa, angle);
    y_line = p.y + (p.x - x_line) * tan(angle);
    ya = ft_y_dir((float)BLOCK_SIZE * tan(angle), angle);
    while (!ft_is_colission(x_line, y_line, data->map, data->map_height))
    {
        x_line += xa;
        y_line += ya;
    }
    return (ft_absf((p.x - x_line) / cos(angle)));
}
