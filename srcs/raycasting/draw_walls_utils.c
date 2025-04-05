/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:42:46 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/05 20:43:01 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float   ft_absf(float val)
{
    return (val * (val >= 0) - val * (val < 0));
}

// initializes DDA values based on player position and ray direction.
// sets starting grid cell (mapX/Y), step direction (stepX/Y),
// initial side distances (sideDistX/Y), and delta distances (deltaDistX/Y).
// Raycasting Tutorial on: https://lodev.org/cgtutor/raycasting.html
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

// calculates the ray hit result after DDA.
// checks for the wall side (N, S, E, W) and perpendicular wall distance.
// side: 0: vertical wall was hit. 1: horizontal wall was hit.
// subtract deltaDist to get the exact perpendicular distance to the wall
// (sideDist is one step too far after DDA finished)
// Raycasting Tutorial on: https://lodev.org/cgtutor/raycasting.html
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

// getting the texture color from the selected texture
uint32_t    ft_get_tex_col(t_data *data, t_rayhit rayhit, int x, int y)
{
    t_texture   *tex;

    if (rayhit.side == 'N')
        tex = data->north;
    else if (rayhit.side == 'S')
        tex = data->south;
    else if (rayhit.side == 'E')
        tex = data->east;
    else if (rayhit.side == 'W')
        tex = data->west;
}
