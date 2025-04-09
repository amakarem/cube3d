/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:51:40 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/09 16:13:33 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// Raycasting Tutorial: https://lodev.org/cgtutor/raycasting.html
//
// Main raycasting loop. One vertical 
// ray is cast for every x-coordinate on the screen,
// covering the player's entire Field of View (FOV).
//
// For each screen column:
// - camerax is calculated (normalized range: -1.0 to +1.0, left to right)
// - raydir is computed using the player's direction and the camera plane:
//   raydir = playerDir + plane * camerax
//
// The camera plane is always perpendicular 
// to the viewing direction and defines the FOV.
//
// Each ray is used to render one vertical slice of the scene (ceiling, wall,
// floor).
// Slices are rendered to the image buffer and put to the screen afterwards.
int	ft_raycast(t_data *data)
{
	int			x;
	float		camerax;
	float		raydir[5500][2];
	t_rayhit	*rayhit[5500];

	x = 0;
	while (x < data->wnd_w)
	{
		camerax = (2.0f * x / (float)data->wnd_w) - 1.0f;
		raydir[x][0] = data->player.dirx + data->player.planex * camerax;
		raydir[x][1] = data->player.diry + data->player.planey * camerax;
		ft_draw_slice(data, &data->buffer, raydir, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->buffer->img, 0,
		0);
	return (1);
}
