/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controllers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:33:39 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/28 17:30:23 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_mouse_down(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (button == 1)
	{
		data->mouse.mouse_down = true;
		data->mouse.mouse_x = x;
		data->mouse.mouse_y = y;
	}
	return (0);
}

int	ft_mouse_up(int button, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (button == 1)
		data->mouse.mouse_down = false;
	return (0);
}

int	ft_mousemove(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->mouse.mouse_down)
	{
        write(STDOUT_FILENO, "mouse move action", 17);
	}
	return (0);
}

int	ft_keyup(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == ESC || !data)
		ft_destroy(data);
	if (key == CTRL)
    {
        data->mouse.ctrl_down = false;
    }
	if (!data->mouse.ctrl_down && key == P)
	{
		if (!ft_wnd_resize(&data, 100, 100))
			return (ft_cleardata(&data), 0);
	}
	else if (!data->mouse.ctrl_down && key == M)
	{
		if (!ft_wnd_resize(&data, -100, -100))
			return (ft_cleardata(&data), 0);
	}
	return (0);
}

int	ft_keydown(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == CTRL)
		data->mouse.ctrl_down = true;
    if (key = W)
        ft_action_W(data);
    else if (key = A)
        ft_action_A(data);
    else if (key = S)
        ft_action_S(data);
    else if (key = D)
        ft_action_D(data);
	return (0);
}
