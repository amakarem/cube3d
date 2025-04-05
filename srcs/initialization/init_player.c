/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:34:52 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/05 13:52:28 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	ft_get_position_and_direction(char **map, float *px, float *py)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
			{
				*px = x + 0.5f;
				*py = y + 0.5f;
				return (map[y][x]);
			}
			x++;
		}
		y++;
	}
	return ('N');
}

void ft_get_plane_vector(float *planeX, float *planeY, t_player player)
{
    float   fov_radiant;
    float   plane_length;

    fov_radiant = FOV * M_PI / 180.0f;
    plane_length = tanf(fov_radiant / 2.0f);
    *planeX = -player.dirY * plane_length;
    *planeY = player.dirX * plane_length;
}

void	ft_init_player(t_data **data, char **map)
{
	char	orientation;

	orientation = ft_get_position_and_direction(map, &(*data)->player.posX,
			&(*data)->player.posY);
	if (orientation == 'N')
    {
        (*data)->player.dirX = 0;
        (*data)->player.dirY = 1;
    }
	else if (orientation == 'S')
    {
        (*data)->player.dirX = 0;
        (*data)->player.dirY = -1;
    }
	else if (orientation == 'E')
    {
        (*data)->player.dirX = 1;
        (*data)->player.dirY = 0;
    }
	else if (orientation == 'W')
    {
        (*data)->player.dirX = -1;
        (*data)->player.dirY = 0;
    }
    ft_get_plane_vector(&(*data)->player.planeX, &(*data)->player.planeY, (*data)->player);
    // (*data)->proj_dist = ((*data)->wnd_w / 2) / tan((FOV / 2) * M_PI / 180);
}

void	ft_init_keyboard(t_data **data)
{
	(*data)->keyboard.w_down = false;
	(*data)->keyboard.a_down = false;
	(*data)->keyboard.s_down = false;
	(*data)->keyboard.d_down = false;
}
