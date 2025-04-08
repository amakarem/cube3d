/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:47:13 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/08 18:00:42 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_validation
{
	bool		north_tex;
	bool		south_tex;
	bool		east_tex;
	bool		west_tex;
	bool		floor;
	bool		ceiling;
	bool		tex_and_cols;
	bool		map_started;
	bool		validated;
}				t_validation;

typedef struct s_mouse
{
	bool		mouse_down;
	bool		ctrl_down;
	int			mouse_x;
	int			mouse_y;
}				t_mouse;

typedef struct s_img
{
	void		*img;
	char		*data;
	int			linelen;
	int			bpp;
	int			endian;
    int         width;
    int         height;
}				t_img;

typedef struct s_texture
{
	void		*img;
	char		*data;
	int			linelen;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}				t_texture;

typedef struct s_slice
{
    int         y_start;
    int         y_end;
    int         tex_x;
    int         tex_y;
    float       tex_step;
    float       tex_pos;
    t_texture   *tex;
} t_slice;

typedef struct s_rayhit
{
    int	    	side;
    int         wall_h;
    int         NS_EW;
    float       wallX;
    float		distance;
    t_texture   *tex;
}				t_rayhit;

typedef struct s_keyboard
{
	bool		w_down;
	bool		a_down;
	bool		s_down;
	bool		d_down;
	bool		left_down;
	bool		right_down;
	bool		up_pressed;
	bool		down_pressed;
}				t_keyboard;

typedef struct s_dda
{
    int     mapX;
    int     mapY;
    int     stepX;
    int     stepY;
    float   sideDistX;
    float   sideDistY;
    float   deltaDistX;
    float   deltaDistY;
    float   perpWallDist;
}           t_dda;

typedef struct s_player
{
	float		posx;
	float		posy;
    float       dirX;
    float       dirY;
    float       planeX;
    float       planeY;
    float       plane_length;
}				t_player;

#endif