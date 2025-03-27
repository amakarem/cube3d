/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:48:57 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/27 14:31:54 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_destroy(t_data *data)
{
	if (data)
		ft_cleardata(data);
	exit(0);
}

int main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc != 2 || !*argv[1])
		ft_err_message("Wrong number of arguments! You must give ...", NULL);
	if (!ft_initialization(data))
	{
		ft_cleardata(data);
		ft_err_message("Initialization failed!", NULL);
	}
	if (!ft_parse_map(data, argv))
	{
		ft_cleardata(data);
		ft_err_message("Parsing the map failed!", NULL);
	}
	mlx_hook(data->var->mlx_win, 17, 0, ft_destroy, data);
	mlx_hook(data->var->mlx_win, 2, 1L << 0, ft_keydown, data);
	mlx_hook(data->var->mlx_win, 3, 1L << 1, ft_keyup, data);
	mlx_hook(data->var->mlx_win, 4, 1L << 2, ft_mouse_down, data);
	mlx_hook(data->var->mlx_win, 5, 1L << 3, ft_mouse_up, data);
	mlx_hook(data->var->mlx_win, 6, 1L << 6, ft_mousemove, data);
	mlx_loop(data->var->mlx_ptr);
	ft_cleardata(data);
	return (0);
}
