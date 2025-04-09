/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_slices.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:01:15 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/09 16:11:54 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// Raycasting Tutorial on: https://lodev.org/cgtutor/raycasting.html
// Casting a ray from player in raydir.
// Using DDA for checking the grid for walls.
// Looking for wall colissions on horizontal and on vertical grid line.
//
// sideDist: distance from players position to next x/y grid line in raydir.
// deltaDist: distance the ray travels to go from one x/y-side to the next.
// mapx/Y: current grid cell being checked for wall hit.
//
// Returns information about the perpendicular wall distance, wall side
// (N, S, E, W), that was hit and wallx (0 - 1) coordinate of the hit.
// wallx: x/y position on the wall where the ray hit (for texture alignment).
t_rayhit	ft_raytrace(t_data *data, t_player player, float *raydir)
{
	int		side;
	t_dda	dda;

	ft_get_dda(&dda, raydir, player);
	while (data->map[dda.mapy][dda.mapx] != '1')
	{
		if (dda.sidedistx < dda.sidedisty)
		{
			dda.sidedistx += dda.deltadistx;
			dda.mapx += dda.stepx;
			side = 0;
		}
		else
		{
			dda.sidedisty += dda.deltadisty;
			dda.mapy += dda.stepy;
			side = 1;
		}
	}
	return (ft_rayhit(dda, side, raydir, player));
}

// Raycasting Tutorial on: https://lodev.org/cgtutor/raycasting.html
// Filling the texture colors array with vertical texture color values
//
// tex_y is calculated from the current position in the wall slice.
// tex_step determines how much to move in the texture per screen pixel.
// tex_x stays constant per slice, tex_y changes with each y-pixel.
//
// If the wall was hit on a horizontal side (ns_ew == 1), the color is darkened
// to simulate lighting on the different wall sides.
void	ft_get_tex_cols(t_slice s, t_rayhit rayhit, uint32_t tex_cols[])
{
	int			tex_line_length;
	uint32_t	*pixels;
	uint32_t	color;

	(void)rayhit;
	tex_line_length = s.tex->linelen / (s.tex->bpp / 8);
	pixels = (uint32_t *)s.tex->data;
	while (s.y_start < s.y_end)
	{
		s.tex_y = (int)s.tex_pos & (s.tex->height - 1);
		s.tex_pos += s.tex_step;
		color = pixels[s.tex_y * tex_line_length + s.tex_x];
		if (rayhit.ns_ew == 1)
			color = (color >> 1) & 8355711;
		tex_cols[s.y_start] = color;
		s.y_start++;
	}
}

// Raycasting Tutorial on: https://lodev.org/cgtutor/raycasting.html
// Renders one vertical slice on the screen at column x.
//
// Top: Ceiling slice, Middle: Wall slice, Bottom: Floor slice
// Wall slices are centered vertically.
//
// Wall height is based on the perpendicular distance from the player
// to the first wall hit by the ray in raydir[x].
// So distant walls appear shorter.
//
// Texture colors are precomputed for every vertical pixel of the slice.
void	ft_draw_slice(t_data *data, t_img **img, float raydir[][2], int x)
{
	int			y;
	t_slice		slice;
	t_rayhit	rayhit;
	uint32_t	tex_cols[3000];

	rayhit = ft_raytrace(data, data->player, raydir[x]);
	rayhit.wall_h = data->wnd_h / rayhit.distance;
	ft_init_slice(data, &slice, rayhit, raydir[x]);
	ft_get_tex_cols(slice, rayhit, tex_cols);
	y = 0;
	while (y < slice.y_start)
	{
		ft_putpxl(img, x, y++, data->ceiling_color);
	}
	while (y < slice.y_end)
	{
		ft_putpxl(img, x, y, tex_cols[y]);
		y++;
	}
	while (y < data->wnd_h)
		ft_putpxl(img, x, y++, data->floor_color);
}
