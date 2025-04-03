/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:48:57 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/03 22:24:18 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_destroy(t_data *data)
{
	if (data)
		ft_cleardata(&data);
	exit(0);
}

void	ft_mlx_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, ft_destroy, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_keydown, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, ft_keyup, data);
	mlx_hook(data->mlx_win, 4, 1L << 2, ft_mouse_down, data);
	mlx_hook(data->mlx_win, 5, 1L << 3, ft_mouse_up, data);
	mlx_hook(data->mlx_win, 6, 1L << 6, ft_mousemove, data);
}

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("map[%i] = %s\n", i, map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc != 2 || !*argv[1])
		ft_err_message_exit("Wrong number of arguments!", NULL);
	if (!ft_validate_cub_file(argv[1]))
		ft_err_message_exit("Error\n", ".cub file validation failed!");
	if (!ft_initialization(&data, argv[1]) || !ft_parse(&data, argv[1]))
	{
		ft_cleardata(&data);
		ft_err_message_exit("Initialization failed!", NULL);
	}
	if (!ft_raycast(&data))
	{
		ft_cleardata(&data);
		ft_err_message_exit("Raycasting failed!", NULL);
	}
	printf("%p und %p\n", data->buffer, data->buffer->img);
	ft_mlx_hooks(data);
	mlx_loop(data->mlx_ptr);
	return (ft_cleardata(&data), 0);
}
