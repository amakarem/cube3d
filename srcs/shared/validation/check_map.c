/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:24:21 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/08 20:14:56 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_outside_horizontal(char **map, int y, int x)
{
	int		_x;
	bool	left;
	bool	right;

	_x = x;
	left = true;
	right = true;
	while (_x--)
	{
		if (map[y][x] == '0')
		{
			left = false;
			break ;
		}
		else if (map[y][x] == '1')
			break ;
	}
	while (map[y][x])
	{
		if (map[y][x] == '0')
		{
			right = false;
			break ;
		}
		else if (map[y][x] == '1')
			break ;
		x++;
	}
	printf("l r\n");
	return (left && right);
}

int	ft_outside_vertical(char **map, int y, int x)
{
	int		_y;
	bool	top;
	bool	bottom;

	_y = y;
	top = true;
	bottom = true;
	printf("o u1\n");
	while (_y--)
	{
		if (map[y][x] == '0')
		{
			top = false;
			break ;
		}
		else if (map[y][x] == '1')
			break ;
	}
	printf("o u2\n");
	while (map[y])
	{
		if (map[y][x] == '0')
		{
			bottom = false;
			break ;
		}
		else if (map[y][x] == '1')
			break ;
		y++;
	}
	printf("o u\n");
	return (top && bottom);
}

int	ft_is_outside_map(char **map, int y, int x)
{
	return (ft_outside_horizontal(map, y, x) && ft_outside_vertical(map, y, x));
}

static int	ft_is_map_closed(char **map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				if (!ft_is_wall_blocked(map, y, x))
					return (0);
			}
			else if (map[y][x] == ' ')
			{
				printf("aa\n");
				if (!ft_is_outside_map(map, y, x))
					return (printf("cc\n"), 0);
				printf("bb\n");
			}
			x++;
		}
		y++;
	}
	return (1);
}

// Returns false, if the map contains one invalid character or
// if a line consists only of spaces (empty line).
// Otherwise true.
static int	ft_valid_map_characters(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i] && map[i][0])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strncmp("0", &map[i][j], 1) && ft_strncmp("1", &map[i][j],
					1) && ft_strncmp("N", &map[i][j], 1) && ft_strncmp("S",
					&map[i][j], 1) && ft_strncmp("E", &map[i][j], 1)
				&& ft_strncmp("W", &map[i][j], 1) && ft_strncmp(" ", &map[i][j], 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_is_present_player_and_unique(char **map)
{
	size_t	i;
	size_t	j;
	size_t	players;

	i = 0;
	players = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strncmp("N", &map[i][j], 1) || !ft_strncmp("S", &map[i][j],
					1) || !ft_strncmp("E", &map[i][j], 1) || !ft_strncmp("W",
					&map[i][j], 1))
				players++;
			j++;
		}
		i++;
	}
	return (players == 1);
}

int	ft_check_map(char *file, int fd)
{
	char	**map;

	map = ft_get_map(file, fd);
	int i = 0;
	while (map[i])
	{
		printf("map[i] = %s\n", map[i++]);
	}
	if (!map)
		return (0);
	if (!ft_valid_map_characters(map))
	{
		ft_free_ptr(&map);
		return (ft_err_message("Error\n",
				"Invalid map character or an empty line."), 0);
	}
	if (!ft_is_present_player_and_unique(map))
	{
		ft_free_ptr(&map);
		return (ft_err_message("Error\n",
				"Either more than 1 player or none in the map."), 0);
	}
	if (!ft_is_map_closed(map))
	{
		ft_free_ptr(&map);
		return (ft_err_message("Error\n", "Map is not closed by walls."), 0);
	}
	return (ft_free_ptr(&map), 1);
}
