/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:48:57 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/11 20:02:45 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_destroy(t_data *data)
{
	ft_cleardata(&data);
	exit(0);
}

int	ft_game_loop(t_data *data)
{
	ft_move_player(data, &data->player);
	ft_raycast(data);
	return (0);
}

void	ft_mlx_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, ft_destroy, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_keydown, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, ft_keyup, data);
	mlx_loop_hook(data->mlx_ptr, ft_game_loop, data);
	mlx_loop(data->mlx_ptr);
}

void	leaks(void)
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	atexit(&leaks);
	data = NULL;
	if (argc != 2 || !*argv[1])
		ft_err_message_exit("Wrong number of arguments!", NULL);
	if (!ft_validate_cub_file(argv[1]))
		ft_err_message_exit("Error\n", ".cub file validation failed!");
	if (!ft_initialization(&data, argv[1]) || !ft_parse(data, argv[1]))
	{
		ft_cleardata(&data);
		ft_err_message_exit("Initialization failed!", NULL);
	}
	ft_mlx_hooks(data);
	return (ft_cleardata(&data), 0);
}
