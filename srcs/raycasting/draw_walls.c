/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:01:15 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/03 22:43:33 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	ft_dir2(float dist, float angle)
{
	if ((angle > M_PI_2 && angle < M_3_PI_2 && dist >= 0) || ((angle <= M_PI_2 || angle >= M_3_PI_2) && dist < 0))
		return (-dist);
	return (dist);	
}

// https://permadi.com/1996/05/ray-casting-tutorial-7/
// Finding the nearest horizontal wall
// x_line: x coordinates of vertical grid lines
// xa: x distance between 2 adjacent ray intersections with y_lines
float   ft_dist_vertical(t_data *data, t_player p, float angle)
{
    float     	x_line;
    float     	xa;
	float 		y_line;
    int     	ya;

    ft_get_y_frame(p, &y_line, &ya, angle);
    x_line = p.x + (p.y - y_line) / tan(angle);
    xa = ft_dir2((float)BLOCK_SIZE / tan(angle), angle);
	printf("dist vertical. 	      angle = %f\n", angle * 180 / M_PI);
	printf("x_line = %f, xa = %f, ya = %i\n", x_line, xa, ya);
    while (!ft_is_colission(x_line, y_line, data->map, data->map_height))
    {
        x_line += xa;
        y_line += ya;
    }
    return (ft_absf((p.x - x_line) / cos(angle)));
}

// int	ft_direct()
// https://permadi.com/1996/05/ray-casting-tutorial-7/
// Finding the nearest vertical wall
// y_line: y coordinates of horizontal grid lines
// ya: y distance between 2 adjacent ray intersections with x_lines
float	ft_dir(float dist, float angle)
{
	if ((angle < M_PI && dist < 0) || (angle >= M_PI && dist < 0))
		return (-dist);
	return (dist);	
}

float   ft_dist_horizontal(t_data *data, t_player p, float angle)
{
    float   x_line;
    float   y_line;
	float	ya;
    int		xa;

    ft_get_x_frame(p, &x_line, &xa, angle);
    y_line = p.y + (p.x - x_line) * tan(angle);
	printf("angle = %f\n", angle);
    ya = ft_dir((float)BLOCK_SIZE * tan(angle), angle);
	printf("dist horizontal. 	      angle = %f\n", angle * 180 / M_PI);
	printf("y_line = %f, xa = %i, ya = %f\n", x_line, xa, ya);
    while (!ft_is_colission(x_line, y_line, data->map, data->map_height))
    {
        x_line += xa;
        y_line += ya;
    }
    return (ft_absf((p.x - x_line) / cos(angle)));
}

float   ft_raytrace(t_data *data, t_player player, float angle)
{
    float   dist_vertical;
    float   dist_horizontal;
	float	relative_ray_angle;

	relative_ray_angle = angle - player.angle;
	if (angle == 0 || angle == M_PI)
		return (ft_dist_horizontal(data, player, angle) * cos(relative_ray_angle));
	else if (angle == M_PI_2 || angle == M_3_PI_2)
		return (ft_dist_vertical(data, player, angle) * cos(relative_ray_angle));
	dist_vertical = ft_dist_vertical(data, player, angle);
	dist_horizontal = ft_dist_horizontal(data, player, angle);
    return (fminf(dist_vertical, dist_horizontal) * cos(relative_ray_angle));
}

void ft_draw_floor_slice(t_data *data, t_img **img, int x, int y_end)
{
    while (y_end < data->wnd_h)
        ft_putpxl(img, x, y_end++, 0x5e3f0b);
}

void ft_draw_ceiling_slice(t_data *data, t_img **img, int x, int y_start)
{
    int y;

    y = 0;
	(void)data;
    while (y < y_start)
        ft_putpxl(img, x, y++, 0x3dd1d1);
}

void    ft_draw_wall_slice(t_data *data, t_img **img, float *section, int x)
{
    int     y_end;
    int     y_start;
    float   distance;
    float   wall_height;

	printf("befoore raytrace\n");
    distance = ft_raytrace(data, data->player, section[x]);
	printf("after raytrace distance = %f\n", distance);
    wall_height = ft_absf(((float)BLOCK_SIZE / distance) * data->proj_dist);
    y_start = (data->wnd_h - wall_height) / 2;
    y_end = y_start + wall_height;
    ft_draw_floor_slice(data, img, x, y_end);
    ft_draw_ceiling_slice(data, img, x, y_start);
    while (y_start < y_end)
        ft_putpxl(img, x, y_start++, 0x03cafc);
}
