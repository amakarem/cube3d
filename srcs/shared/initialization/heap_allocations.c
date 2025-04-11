/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_allocations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:32:59 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/11 21:56:53 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_window(t_data **data)
{
	int		h;
	int		w;
	void	*mlx;

	mlx = (*data)->mlx_ptr;
	h = (*data)->wnd_h * ((*data)->wnd_h > 0) + HEIGHT * ((*data)->wnd_h == 0);
	w = (*data)->wnd_w * ((*data)->wnd_w > 0) + WIDTH * ((*data)->wnd_w == 0);
	(*data)->mlx_win = mlx_new_window(mlx, w, h, "cub3D");
	if (!(*data)->mlx_win)
		return (0);
	(*data)->wnd_w = w;
	(*data)->wnd_h = h;
	(*data)->center_h = h / 2;
	return (1);
}

int	ft_init_image(t_data **data)
{
	int		w;
	int		h;
	void	*mlx;
	t_img	*img;

	mlx = (*data)->mlx_ptr;
	w = (*data)->wnd_w;
	h = (*data)->wnd_h;
	(*data)->buffer = malloc(sizeof(t_img));
	if (!(*data)->buffer)
		return (0);
	img = (*data)->buffer;
	img->img = mlx_new_image(mlx, w, h);
	if (!img->img)
		return (0);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->linelen,
			&img->endian);
	if (!img->data)
		return (0);
	img->width = w;
	img->height = h;
	return (1);
}

// sets everything to NULL -> in case something can not allocate,
// the cleardata function
// just frees all available heap allocations and it
// doesn't occur a bad access error.
void	ft_init_null(t_data **data)
{
	(*data)->mlx_ptr = NULL;
	(*data)->mlx_win = NULL;
	(*data)->buffer = NULL;
	(*data)->map = NULL;
	(*data)->wnd_h = 0;
	(*data)->wnd_w = 0;
	(*data)->floor_color = 0;
	(*data)->ceiling_color = 0;
	(*data)->tex[NORTH].img = NULL;
	(*data)->tex[SOUTH].img = NULL;
	(*data)->tex[EAST].img = NULL;
	(*data)->tex[WEST].img = NULL;
}

int	ft_create_map(t_data **data, char *file)
{
	int		fd;
	size_t	i;

	if (ft_open_file(file, &fd) == -1)
		return (0);
	(*data)->map = ft_get_map(file, fd);
	if (!(*data)->map)
		return (close(fd), 0);
	i = 0;
	while ((*data)->map[i])
		i++;
	(*data)->map_height = i;
	return (close(fd), 1);
}

int	ft_initialization(t_data **data, char *file)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (0);
	ft_init_null(data);
	(*data)->mlx_ptr = mlx_init();
	if (!(*data)->mlx_ptr)
		return (0);
	if (!ft_init_window(data) || !ft_init_image(data))
		return (0);
	if (!ft_create_map(data, file))
		return (0);
	ft_init_keyboard(data);
	ft_init_player(&(*data)->player, (*data)->map);
	return (1);
}
