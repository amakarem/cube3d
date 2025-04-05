/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:01:15 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/05 15:37:41 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_get_dda(t_dda *dda, float *rayDir, t_player player)
{
    dda->mapX = (int)player.posX;
    dda->mapY = (int)player.posY;
    dda->deltaDistX = ft_absf(1 / rayDir[0]) * (rayDir[0] != 0) + 1e30 * (rayDir[0] == 0);
    dda->deltaDistX = ft_absf(1 / rayDir[1]) * (rayDir[1] != 0) + 1e30 * (rayDir[1] == 0);
    if (rayDir[0] < 0)
    {
        dda->stepX = -1;
        dda->sideDistX = (player.posX - dda->mapX) * dda->deltaDistX;
    }
    else
    {
        dda->stepX = 1;
        dda->sideDistX = (dda->mapX + 1 - player.posX) * dda->deltaDistX;
    }
    if (rayDir[1] < 0)
    {
        dda->stepY = -1;
        dda->sideDistY = (player.posY - dda->mapY) * dda->deltaDistY;
    }
    else
    {
        dda->stepY = 1;
        dda->sideDistY = (dda->mapY + 1 - player.posY) * dda->deltaDistY;
    }
}

t_rayhit    ft_rayhit(t_dda dda, int side, float *rayDir)
{
    t_rayhit    rayhit;

    rayhit.NS_EW = side;
    if (side == 0)
    {
        if (dda.stepX == 1)
            rayhit.side = 'W';
        else
            rayhit.side = 'E';
        rayhit.distance = dda.sideDistX - dda.deltaDistX;
    }
    else
    {
        if (dda.stepY == 1)
            rayhit.side = 'S';
        else
            rayhit.side = 'N';
        rayhit.distance = dda.sideDistY - dda.deltaDistY;
    }
    return (rayhit);
}

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
        ft_putpxl(img, x, y_start++, 0x6D6E72);
}
