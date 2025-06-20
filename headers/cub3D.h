/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:50:31 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/12 00:31:21 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1024
# define HEIGHT 768
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
// SPEED [3.0f pixels / frame]
# define SPEED 0.1f
// ROTATION_SPEED [0.07f radiants / pixels difference]
# define ROTATION_SPEED 0.006f
# define WALL_DISTANCE 0.2f

typedef enum s_tex_names
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}				t_tex_names;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_img		*buffer;
	int			wnd_w;
	int			wnd_h;
	int			center_h;
	char		**map;
	int			map_height;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	t_texture	tex[4];
	t_player	player;
	t_keyboard	keyboard;
	t_mouse		mouse;
}				t_data;

// shared
int				ft_destroy(t_data *data);
void			ft_rotate(t_player *p, float angle);

// validation
int				ft_validate_cub_file(char *file);
int				ft_check_textures(t_validation *checks, char **split);
int				ft_check_colors(t_validation *checks, char **split);
int				ft_check_map(char *file, int fd);
bool			ft_is_line_of_map(char *line);
int				ft_fill_lines(char ***map, int width, int height, int fd);
char			*ft_get_map_line(int fd);
void			ft_init_checks(t_validation *checks);
bool			ft_check_bottom(char **map, int y, int x);
bool			ft_check_top(char **map, int y, int x);
int				ft_outside_horizontal(char **map, int y, int x);
bool			ft_check_right(char **map, int y, int x);
bool			ft_check_left(char **map, int y, int x);
int				ft_is_outside_map(char **map, int y, int x);
int				ft_outside_vertical(char **map, int y, int x);
int				ft_outside_horizontal(char **map, int y, int x);
bool			ft_has_left_wall(char **map, int y, int x);
bool			ft_has_right_wall(char **map, int y, int x);
bool			ft_has_top_wall(char **map, int y, int x);
bool			ft_has_bottom_wall(char **map, int y, int x);

// initialization
void			ft_init_keyboard(t_data **data);
void			ft_init_player(t_player *p, char **map);
int				ft_initialization(t_data **data, char *file);

// parsing
int				ft_parse(t_data *data, char *file);
int				ft_get_textures(t_data *data, char **split);
int				ft_get_colors(t_data *data, char **split);

// messaging
void			ft_err_msg(char *s1, char *s2);
void			ft_err_msg_exit(char *s1, char *s2);

// keyboard handling
int				ft_keydown(int key, void *param);
int				ft_keyup(int key, void *param);

// utils
char			*ft_trim_newlines(char *line);
size_t			ft_ptr_len(char **ptr);
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
int				ft_raycast(t_data *data);
void			ft_clean_window(t_data *data);
void			ft_draw_slice(t_data *data, t_img **img, float raydir[][2],
					int x);
float			ft_absf(float val);
void			ft_putpxl(t_img **img, int x, int y, uint32_t color);
t_rayhit		ft_rayhit(t_dda dda, int side, float *raydir, t_player player);
void			ft_move_player(t_data *data, t_player *p);
void			ft_get_dda(t_dda *dda, float *raydir, t_player player);
void			ft_init_slice(t_data *data, t_slice *slice, t_rayhit rayhit,
					float *raydir);
#endif