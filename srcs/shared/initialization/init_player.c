/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:34:52 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/07 15:07:29 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	ft_get_player(char **map, float *px, float *py)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
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

void ft_get_plane_vector(float *planeX, float *planeY, t_player *p)
{
    float   fov_radiant;

    fov_radiant = FOV * M_PI / 180.0f;
    p->plane_length = tanf(fov_radiant / 2.0f);
    *planeX = -p->dirY * p->plane_length;
    *planeY = p->dirX * p->plane_length;
}

void	ft_init_player(t_player *p, char **map)
{
	char	orientation;

	orientation = ft_get_player(map, &p->posX, &p->posY);
	// printf("in init player x = %f, y = %f, map[y][x] = %c\n", p->posX, p->posY, map[(int)p->posY][(int)p->posX]);
	if (orientation == 'N')
    {
        p->dirX = 0;
        p->dirY = -1;
    }
	else if (orientation == 'S')
    {
        p->dirX = 0;
        p->dirY = 1;
    }
	else if (orientation == 'E')
    {
        p->dirX = 1;
        p->dirY = 0;
    }
	else if (orientation == 'W')
    {
        p->dirX = -1;
        p->dirY = 0;
    }
    ft_get_plane_vector(&p->planeX, &p->planeY, p);
}

void	ft_init_keyboard(t_data **data)
{
	(*data)->keyboard.w_down = false;
	(*data)->keyboard.a_down = false;
	(*data)->keyboard.s_down = false;
	(*data)->keyboard.d_down = false;
}
