/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:42:46 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/09 14:58:08 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	ft_absf(float val)
{
	return (val * (val >= 0) - val * (val < 0));
}

// Raycasting Tutorial on: https://lodev.org/cgtutor/raycasting.html
// Sets the current grid cell (mapx/Y) based on the player's position.
//
// delta distances: how far the ray has 
// to travel to cross the next x/y gridline.
// side distances: from the player's position to the first x/y gridline.
//
// Sets stepx and stepy depending on ray direction.
void	ft_get_dda(t_dda *dda, float *raydir, t_player player)
{
	dda->mapx = (int)player.posx;
	dda->mapy = (int)player.posy;
	dda->deltadistx = ft_absf(1 / raydir[0]) * (raydir[0] != 0) + 1e30
		* (raydir[0] == 0);
	dda->deltadisty = ft_absf(1 / raydir[1]) * (raydir[1] != 0) + 1e30
		* (raydir[1] == 0);
	if (raydir[0] < 0)
	{
		dda->stepx = -1;
		dda->sidedistx = (player.posx - dda->mapx) * dda->deltadistx;
	}
	else
	{
		dda->stepx = 1;
		dda->sidedistx = (dda->mapx + 1 - player.posx) * dda->deltadistx;
	}
	if (raydir[1] < 0)
	{
		dda->stepy = -1;
		dda->sidedisty = (player.posy - dda->mapy) * dda->deltadisty;
		return ;
	}
	dda->stepy = 1;
	dda->sidedisty = (dda->mapy + 1 - player.posy) * dda->deltadisty;
}

// Raycasting Tutorial on: https://lodev.org/cgtutor/raycasting.html
// Calculates the ray hit result after the DDA loop finished.
// Was a vertical or horizontal wall hit? => (side == 0 or 1).
// Sets the correct wall side index.
// Calculates perpendicular wall distance by subtracting one step from sideDist.
// Calculates wallx for texture mapping.
t_rayhit	ft_rayhit(t_dda dda, int side, float *raydir, t_player player)
{
	t_rayhit	rayhit;

	rayhit.ns_ew = side;
	if (side == 0)
	{
		if (dda.stepx == 1)
			rayhit.side = 3;
		else
			rayhit.side = 2;
		rayhit.distance = dda.sidedistx - dda.deltadistx;
		rayhit.wallx = player.posy + rayhit.distance * raydir[1];
	}
	else
	{
		if (dda.stepy == 1)
			rayhit.side = 1;
		else
			rayhit.side = 0;
		rayhit.distance = dda.sidedisty - dda.deltadisty;
		rayhit.wallx = player.posx + rayhit.distance * raydir[0];
	}
	return (rayhit.wallx -= floorf(rayhit.wallx), rayhit);
}

// Initializes values needed to draw the current vertical slice.
// Calculates start and end y-pixel for the wall slice
// and selects the correct wall texture.
//
// tex_x is based on wallx.
// If the wall was hit from the backside (from left or bottom),
// tex_x is mirrored to align the texture correctly.
// tex_pos is the starting y-position in the texture.
void	ft_init_slice(t_data *data, t_slice *slice, t_rayhit rayhit,
		float *raydir)
{
	slice->y_start = data->center_h - (rayhit.wall_h / 2);
	slice->y_end = data->center_h + (rayhit.wall_h / 2);
	slice->tex = &data->tex[rayhit.side];
	if (slice->y_start < 0)
		slice->y_start = 0;
	if (slice->y_end >= data->wnd_h)
		slice->y_end = data->wnd_h - 1;
	slice->tex_x = rayhit.wallx * (float)slice->tex->width;
	if ((rayhit.ns_ew == 0 && raydir[0] > 0) || (rayhit.ns_ew == 1
			&& raydir[1] < 0))
		slice->tex_x = slice->tex->width - slice->tex_x - 1;
	slice->tex_step = 1.0f * slice->tex->height / rayhit.wall_h;
	slice->tex_pos = slice->tex_step * (slice->y_start - data->center_h
			+ rayhit.wall_h / 2);
}
