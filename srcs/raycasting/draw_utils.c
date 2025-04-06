/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:42:46 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/06 15:33:05 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float   ft_absf(float val)
{
    return (val * (val >= 0) - val * (val < 0));
}

// Raycasting Tutorial on: https://lodev.org/cgtutor/raycasting.html
// Sets the current grid cell (mapX/Y) based on the player's position.
// Calculates delta distances: how far the ray has to travel to cross the next x/y gridline.
// Calculates initial side distances from the player's position to the first x/y gridline.
// Sets stepX and stepY depending on ray direction.
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

// Raycasting Tutorial on: https://lodev.org/cgtutor/raycasting.html
// Calculates the ray hit result after the DDA loop finished.
// Was a vertical or horizontal wall hit? => (side == 0 or 1).
// Sets the correct wall side index.
// Calculates perpendicular wall distance by subtracting one step from sideDist.
// Calculates wallX for texture mapping.
t_rayhit    ft_rayhit(t_dda dda, int side, float *rayDir, t_player player)
{
    t_rayhit    rayhit;

    rayhit.NS_EW = side;
    if (side == 0)
    {
        if (dda.stepX == 1)
            rayhit.side = 3;
        else
            rayhit.side = 2;
        rayhit.distance = dda.sideDistX - dda.deltaDistX;
        rayhit.wallX = player.posY + rayhit.distance * rayDir[1];
    }
    else
    {
        if (dda.stepY == 1)
            rayhit.side = 1;
        else
            rayhit.side = 0;
        rayhit.distance = dda.sideDistY - dda.deltaDistY;
        rayhit.wallX = player.posX + rayhit.distance * rayDir[0];
    }
    return (rayhit.wallX -= floorf(rayhit.wallX), rayhit);
}

// Initializes values needed to draw the current vertical slice.
// Calculates start and end y-pixel for the wall slice
// and selects the correct wall texture.
//
// tex_x is based on wallX.
// If the wall was hit from the backside (from left or bottom),
// tex_x is mirrored to align the texture correctly.
// tex_pos is the starting y-position in the texture.
void    ft_init_slice(t_data *data, t_slice *slice, t_rayhit rayhit, float *rayDir)
{
    slice->y_start = (data->wnd_h - rayhit.wall_h) / 2;
    slice->y_end = (data->wnd_h + rayhit.wall_h) / 2;
    slice->tex = &data->tex[rayhit.side];
    if (slice->y_start < 0)
        slice->y_start = 0;
    if (slice->y_end >= data->wnd_h)
        slice->y_end = data->wnd_h - 1;
    slice->tex_x = rayhit.wallX * (float)slice->tex->width;
    if ((rayhit.NS_EW == 0 && rayDir[0] > 0) || (rayhit.NS_EW == 1 && rayDir[1] < 0))
        slice->tex_x = slice->tex->width - slice->tex_x - 1;
    slice->tex_step = 1.0f * slice->tex->height / rayhit.wall_h;
    slice->tex_pos = slice->tex_step * (slice->y_start - data->wnd_h / 2 + rayhit.wall_h / 2);
}
