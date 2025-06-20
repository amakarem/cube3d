/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:21:08 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/12 00:27:35 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_destroy(t_data *data)
{
	ft_cleardata(&data);
	exit(0);
}

int	ft_game_loop(t_data *data)
{
	ft_clean_window(data);
	ft_move_player(data, &data->player);
	if (!ft_raycast(data))
	{
		ft_cleardata(&data);
		ft_err_msg_exit("Raycasting failed!", NULL);
	}
	return (0);
}

void	ft_mlx_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, ft_destroy, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_keydown, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, ft_keyup, data);
	mlx_hook(data->mlx_win, 4, 1L << 2, ft_mouse_down, data);
	mlx_hook(data->mlx_win, 5, 1L << 3, ft_mouse_up, data);
	mlx_hook(data->mlx_win, 6, 1L << 6, ft_mousemove, data);
	mlx_loop_hook(data->mlx_ptr, ft_game_loop, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc != 2 || !*argv[1])
		ft_err_msg_exit("Wrong number of arguments!", NULL);
	if (!ft_validate_cub_file(argv[1]))
		ft_err_msg_exit("Error\n", ".cub file validation failed!");
	if (!ft_initialization(&data, argv[1]) || !ft_parse(data, argv[1]))
	{
		ft_cleardata(&data);
		ft_err_msg_exit("Initialization failed!", NULL);
	}
	ft_mlx_hooks(data);
	return (ft_cleardata(&data), 0);
}
