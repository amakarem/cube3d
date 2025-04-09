/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:07:19 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/09 14:54:28 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_closed_horizontal(char **map, int y, int x)
{
	bool	left;
	bool	right;

	left = ft_has_left_wall(map, y, x);
	right = ft_has_right_wall(map, y, x);
	return (left && right);
}

int	ft_closed_vertical(char **map, int y, int x)
{
	bool	top;
	bool	bottom;

	top = ft_has_top_wall(map, y, x);
	bottom = ft_has_bottom_wall(map, y, x);
	return (top && bottom);
}

// checks whether the current is blocked by a '1' vertically and horizontally
// if not, then the map is not closed by walls.
int	ft_is_wall_blocked(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == ' ')
		return (1);
	return (ft_closed_horizontal(map, y, x) && ft_closed_vertical(map, y, x));
}

// check if the color values r/g/b are in the range 0
// - 255 and if the string contains only digits
int	ft_check_nums(char *s)
{
	size_t	i;
	int		num;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	num = ft_atoi(s);
	if (!(num >= 0 && num <= 255))
		return (0);
	return (1);
}

// check if the floor/ceiling color strings are valid
int	ft_valid_numbers(char *s)
{
	char	**cols;

	if (!s || !*s)
		return (0);
	cols = ft_split(s, ',');
	if (!cols)
		return (0);
	if (ft_ptr_len(cols) != 3)
		return (ft_free_ptr(&cols), 0);
	if (!ft_check_nums(cols[0]) || !ft_check_nums(cols[1])
		|| !ft_check_nums(cols[2]))
	{
		return (ft_free_ptr(&cols), 0);
	}
	return (ft_free_ptr(&cols), 1);
}
