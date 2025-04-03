/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:02:05 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/03 04:04:02 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_is_colission(int x, int y, char **map)
{
    int _x;
    int _y;

    _x = x / BLOCK_SIZE;
    _y = y / BLOCK_SIZE;
    if (map[_y][_x] == '1')
        return (1);
    return (0);
}

float   f_absf(float val)
{
    return (val * (val >= 0) - val * (val < 0));
}

void    ft_get_y_frame(t_player p, int *y_line, int *ya)
{
    if (p.angle < M_PI)
    {
        *ya = -BLOCK_SIZE;
        *y_line = (p.y / BLOCK_SIZE) * BLOCK_SIZE - 1;
    }
    else
    {
        *ya = BLOCK_SIZE;
        *y_line = (p.y / BLOCK_SIZE) * BLOCK_SIZE + BLOCK_SIZE;
    }
}

void    ft_get_x_frame(t_player p, int *x_line, int *xa)
{
    if (p.angle > M_PI_2 || p.angle < 3 * M_PI_2)
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
