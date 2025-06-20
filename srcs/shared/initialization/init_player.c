/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:34:52 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/11 19:14:08 by aelaaser         ###   ########.fr       */
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

void	ft_get_plane_vector(float *planex, float *planey, t_player *p)
{
	float	fov_radiant;

	fov_radiant = FOV * M_PI / 180.0f;
	p->plane_length = tanf(fov_radiant / 2.0f);
	*planex = -p->diry * p->plane_length;
	*planey = p->dirx * p->plane_length;
}

void	ft_init_player(t_player *p, char **map)
{
	char	orientation;

	orientation = ft_get_player(map, &p->posx, &p->posy);
	if (orientation == 'N')
	{
		p->dirx = 0;
		p->diry = -1;
	}
	else if (orientation == 'S')
	{
		p->dirx = 0;
		p->diry = 1;
	}
	else if (orientation == 'E')
	{
		p->dirx = 1;
		p->diry = 0;
	}
	else if (orientation == 'W')
	{
		p->dirx = -1;
		p->diry = 0;
	}
	ft_get_plane_vector(&p->planex, &p->planey, p);
}

void	ft_init_keyboard(t_data **data)
{
	(*data)->keyboard.w_down = false;
	(*data)->keyboard.a_down = false;
	(*data)->keyboard.s_down = false;
	(*data)->keyboard.d_down = false;
	(*data)->keyboard.left_down = false;
	(*data)->keyboard.right_down = false;
	(*data)->keyboard.up_pressed = false;
	(*data)->keyboard.down_pressed = false;
}
