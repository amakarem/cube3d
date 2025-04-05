/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:01:15 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/05 12:19:02 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_get_wall_side(float angle, t_rayhit *rayhit, bool shortest_vertical)
{
    if (angle > 0 && angle <= M_PI_2)
        rayhit->side = 'N' * (shortest_vertical) + 'E' * (!shortest_vertical);
    else if (angle > M_PI_2 && angle < M_PI)
        rayhit->side = 'N' * (shortest_vertical) + 'W' * (!shortest_vertical);
    else if (angle >= M_PI && angle < M_3_PI_2)
        rayhit->side = 'S' * (shortest_vertical) + 'W' * (!shortest_vertical);
    else if (angle >= M_3_PI_2 && angle < 2 * M_PI)
        rayhit->side = 'S' * (shortest_vertical) + 'E' * (!shortest_vertical);
    else
        rayhit->side = 'N';
}

t_rayhit   ft_raytrace(t_data *data, t_player player, float angle)
{
    float       distance_v;
    float       distance_h;
    t_rayhit    rayhit;

	if (angle == 0 || angle == M_PI)
    {
        rayhit.side = 'E' * (angle == 0) + 'W' * (angle == M_PI);
        return (rayhit.distance = ft_dist_horizontal(data, player, angle), rayhit);        
    }
	else if (angle == M_PI_2 || angle == M_3_PI_2)
    {
        rayhit.side = 'N' * (angle == M_PI_2) + 'S' * (angle == M_3_PI_2);
        return (rayhit.distance = ft_dist_vertical(data, player, angle), rayhit);
    }
    distance_v = ft_dist_vertical(data, player, angle);
    distance_h = ft_dist_horizontal(data, player, angle);
    rayhit.distance = fminf(distance_v, distance_h);
    ft_get_wall_side(angle, &rayhit, distance_v < distance_h);
    return (rayhit);
}

void ft_draw_ceiling_slice(t_data *data, t_img **img, int x, int y_start)
{
    int y;

    y = 0;
	(void)data;
    while (y < y_start)
        ft_putpxl(img, x, y++, data->ceiling_color);
}

void ft_draw_floor_slice(t_data *data, t_img **img, int x, int y_end)
{
    while (y_end < data->wnd_h)
        ft_putpxl(img, x, y_end++, data->floor_color);
}

// uint32_t ft_texture_color(t_data *data, float angle, t_rayhit rayhit, t_wall_data wall_data)
// {
//     int     x;
//     int     y;
//     float   texture_x;
//     float   texture_y;

//     x = (int)(angle / (2 * M_PI) * data->north->width);
//     y = (int)((y - ((data->wnd_h - wall_data.wall_height) / 2)) / wall_data.wall_height * data->north->height);
//     texture_x = x % data->north->width;
//     texture_y = y % data->north->height;
//     return (*(uint32_t *)(data->north->data + (texture_x * (data->north->bpp / 8) + texture_y * data->north->linelen)));
// }

void    ft_draw_wall_slice(t_data *data, t_img **img, float *section, int x)
{
    int     y_end;
    float   distance;
    t_rayhit rayhit;
    t_wall_data wall_data;

    rayhit = ft_raytrace(data, data->player, section[x]);
    distance = rayhit.distance * cos(section[x] - data->player.angle);
    if (distance == 0)
        distance = 1;
    wall_data.wall_height = ft_absf(((float)BLOCK_SIZE / distance) * data->proj_dist);
    wall_data.y_start = (data->wnd_h - wall_data.wall_height) / 2;
    ft_draw_floor_slice(data, img, x, wall_data.y_start + wall_data.wall_height);
    ft_draw_ceiling_slice(data, img, x, wall_data.y_start);
    while (wall_data.y_start < y_end)
        ft_putpxl(img, x, wall_data.y_start++, 0x6D6E72);
}
