/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:02:05 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/03 21:56:57 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_is_colission(float x, float y, char **map, int h)
{
    int _x;
    int _y;

    _x = x / BLOCK_SIZE;
    _y = y / BLOCK_SIZE;
	if (_x < 0)
		_x = 0;
	if (_y < 0)
		_y = 0;
	if (_y >= h)
		_y = h - 1;
	if (_x >= (int)ft_strlen(map[_y]))
		_x = (int)ft_strlen(map[_y]);
	printf("checked for coll00 _x = %i, _y = %i\n", _x, _y);
	printf("cheking map[%i][%i] = %c\n", _y, _x, map[_y][_x]);
	printf("checked for coll01\n");
    if (map[_y][_x] == '1')
        return (1);
    return (0);
}

float   ft_absf(float val)
{
    return (val * (val >= 0) - val * (val < 0));
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
