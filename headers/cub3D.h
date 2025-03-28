/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:50:31 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/28 17:11:38 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "mlx.h"

# define WIDTH 800
# define HEIGHT 800

# define DEFAULT_CEILING_COL 0x87CEEB
# define DEFAULT_FLOOR_COL 0x8B4513

# define DEFAULT_NORTH_COL 0xFFFFFF
# define DEFAULT_SOUTH_COL 0xFF0000
# define DEFAULT_EAST_COL 0x00FF00
# define DEFAULT_WEST_COL 0x0000FF

# define ESC 53
# define CTRL 256

# define W 13
# define S 1
# define A 0
# define D 2

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define P 35
# define M 46

typedef struct s_img
{
    void *img;
    char *data;
    int linelen;
    int bpp;
    int endian;
} t_img;

typedef struct s_mouse
{
    bool mouse_down;
    bool ctrl_down;
    int mouse_x;
    int mouse_y;
} t_mouse;

typedef struct s_texture
{
    char *path;
    void *img;
    int width;
    int height;
}           t_texture;

typedef struct s_map
{
    int         **map;
    int         width;
    int         height;
}               t_map;

typedef struct s_data
{
    void        *mlx_ptr;
    void        *mlx_win;
    t_img       *buffer;
    int         wnd_w;
    int         wnd_h;
    t_mouse     mouse;
    t_texture   *north;
    t_texture   *south;
    t_texture   *east;
    t_texture   *west;
    t_map       *map;
}               t_data;

int ft_destroy(t_data *data);

//validation
int ft_check_map(char **split);
int ft_check_colors(char **split);
int ft_check_textures(char **split);
int ft_validate_cub_file(char *file);

// initialization
int ft_initialization(t_data *data);

// parsing
int ft_parse_map(t_data *data, char **argv);

// messaging
void ft_err_message(char *s1, char *s2);
void	ft_err_message_exit(char *s1, char *s2);

// keyboard handling
int ft_keydown(int key, void *param);
int ft_keyup(int key, void *param);
int ft_mousemove(int x, int y, void *param);
int ft_mouse_up(int button, int x, int y, void *param);
int ft_mouse_down(int button, int x, int y, void *param);

// actions
void ft_action_W(t_data *data);
void ft_action_A(t_data *data);
void ft_action_S(t_data *data);
void ft_action_D(t_data *data);
int ft_wnd_resize(t_data **data, int delta_x, int delta_y);

//utils
size_t  ft_ptr_len(char **ptr);
int	ft_hex_to_int(const char *str);
void    ft_free_ptr(char ***ptr);

// clearing
void ft_cleardata(t_data *data);

#endif
