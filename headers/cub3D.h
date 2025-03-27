/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:50:31 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/27 14:01:02 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "mlx.h"

#define ESC 53
#define CTRL 256

#define W 13
#define S 1
#define A 0
#define D 2

#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124

#define P 35
#define M 46

typedef struct s_mlx
{
    void *mlx_ptr;
    void *mlx_win;
} t_mlx;

typedef struct s_point
{
    float x;
    float y;
    float z;
    uint32_t color;
} t_point;

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

typedef struct s_wnd
{
    int wnd_w;
    int wnd_h;
} t_wnd;

typedef struct s_data
{
    t_mlx *var;
    t_img *buffer;
    t_wnd wnd;
    t_mouse mouse;
} t_data;

int	ft_destroy(t_data *data);
void ft_err_message(char *s1, char *s2);
bool ft_input_validation(char *s);
void ft_cleardata(t_data *data);

// keyboard handling
int ft_keydown(int key, void *param);
int ft_keyup(int key, void *param);
int ft_mousemove(int x, int y, void *param);
int ft_mouse_up(int button, int x, int y, void *param);
int ft_mouse_down(int button, int x, int y, void *param);

// actions
void    ft_action_W(t_data *data);
void    ft_action_A(t_data *data);
void    ft_action_S(t_data *data);
void    ft_action_D(t_data *data);
int     ft_wnd_resize(t_data **data, int delta_x, int delta_y);

#endif
