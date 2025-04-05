/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:50:31 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/04 19:33:24 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define M_3_PI_2 4.7123889804
# define FOV 60
# define BLOCK_SIZE 64
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
// SPEED [3.0f pixels / frame]
# define SPEED 3.0f
// ROTATION_SPEED [0.07f radiants / pixels difference]
# define ROTATION_SPEED 0.006f

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

typedef struct s_rayhit
{
    char		side;
    float		distance;
    int         y_start;
}				t_rayhit;

typedef struct s_wall_data
{
    float		wall_height;
    int			y_start;
    int			y_end;
}				t_wall_data;

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

typedef struct s_keyboard
{
	bool		w_down;
	bool		a_down;
	bool		s_down;
	bool		d_down;
}				t_keyboard;

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
}				t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		*buffer;
	int			wnd_w;
	int			wnd_h;
    float       proj_dist;
	char		**map;
	int			map_height;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	t_texture	*north;
	t_texture	*south;
	t_texture	*east;
	t_texture	*west;
	t_player	player;
	t_keyboard	keyboard;
	t_mouse		mouse;
}				t_data;

int				ft_destroy(t_data *data);

// validation
int				ft_validate_cub_file(char *file);
int				ft_check_textures(t_validation *checks, char **split);
int				ft_check_colors(t_validation *checks, char **split);
int				ft_check_map(char *file, int fd);
bool			ft_is_line_of_map(char *line);

// initialization
void	        ft_init_null(t_data **data);
void			ft_init_keyboard(t_data **data);
void			ft_init_player(t_data **data, char **map);
int				ft_initialization(t_data **data, char *file);

// parsing
int				ft_parse(t_data **data, char *file);
int				ft_get_textures(t_data **data, char **split);
int				ft_get_colors(t_data **data, char **split);

// messaging
void			ft_err_message(char *s1, char *s2);
void			ft_err_message_exit(char *s1, char *s2);

// keyboard handling
int				ft_keydown(int key, void *param);
int				ft_keyup(int key, void *param);
int				ft_mousemove(int x, int y, void *param);
int				ft_mouse_up(int button, int x, int y, void *param);
int				ft_mouse_down(int button, int x, int y, void *param);

// actions
void			ft_action_w(t_data *data);
void			ft_action_a(t_data *data);
void			ft_action_s(t_data *data);
void			ft_action_d(t_data *data);
int				ft_wnd_resize(t_data **data, int delta_x, int delta_y);

// utils
char			*ft_trim_newlines(char *line);
size_t			ft_ptr_len(char **ptr);
int				ft_hex_to_int(const char *str);
void			ft_free_ptr(char ***ptr);
int				ft_valid_numbers(char *s);
int				ft_is_wall_blocked(char **map, int y, int x);
int				ft_closed_vertical(char **map, int y, int x);
int				ft_closed_horizontal(char **map, int y, int x);
int				ft_open_file(char *file, int *fd);
void			ft_free(char **ptr);
void			ft_init_checks(t_validation *checks);
void			ft_update_check_tex_and_cols(t_validation *checks);
int				ft_get_map_height(char *file);
char			**ft_get_map(char *file, int fd);

// clearing
void			ft_cleardata(t_data **data);

// raycasting
int				ft_raycast(t_data **data);
void    ft_clean_window(t_data *data);
void    ft_draw_wall_slice(t_data *data, t_img **img, float *section, int x);
void    ft_get_x_frame(t_player p, float *x_line, int *xa, float angle);
void    ft_get_y_frame(t_player p, float *y_line, int *ya, float angle);
float   ft_absf(float val);
int ft_is_colission(float x, float y, char **map, int h);
void    ft_putpxl(t_img **img, int x, int y, uint32_t color);
void ft_update_players_pos_and_dir(t_data **data, float angle);
float	ft_x_dir(float dist, float angle);
float	ft_y_dir(float dist, float angle);
float   ft_dist_vertical(t_data *data, t_player p, float angle);
float   ft_dist_horizontal(t_data *data, t_player p, float angle);

#endif
