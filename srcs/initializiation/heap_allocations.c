/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_allocations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:32:59 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/28 17:36:44 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_var(t_data *data)
{
	int		w;
	int		h;

	if (data->wnd_w > 0)
		w = data->wnd_w;
	else
		w = WIDTH;
	if (data->wnd_h > 0)
		h = data->wnd_h;
	else
		h = HEIGHT;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, w, h, "cub3D");
	if (!data->mlx_ptr || !data->mlx_win)
		return (0);
	return (1);
}

int	ft_initialization(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	(*data)->buffer = NULL;
	if (!ft_init_var(data))
		return (0);
	return (1);
}
