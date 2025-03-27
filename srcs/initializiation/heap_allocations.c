/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_allocations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:32:59 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/27 14:42:16 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_init_var(t_data *data)
{
	int		w;
	int		h;

	data->var = malloc(sizeof(t_mlx));
	if (!data->var)
		return (0);
	if (data->wnd.wnd_w > 0)
		w = data->wnd.wnd_w;
	else
		w = WIDTH;
	if (data->wnd.wnd_h > 0)
		h = data->wnd.wnd_h;
	else
		h = HEIGHT;
	data->var->mlx_ptr = NULL;
	data->var->mlx_win = NULL;
	data->var->mlx_ptr = mlx_init();
	data->var->mlx_win = mlx_new_window(data->var->mlx_ptr, w, h, "cub3D");
	if (!data->var->mlx_ptr || !data->var->mlx_win)
		return (0);
	return (1);
}

int	ft_initialization(t_data *data)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->buffer = NULL;
	data->var = NULL;
	if (!ft_init_var(data))
		return (0);
	return (1);
}
