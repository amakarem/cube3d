/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:49:47 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/09 14:54:24 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	ft_has_left_wall(char **map, int y, int x)
{
	while (x--)
	{
		if (map[y][x] == ' ')
			return (false);
		if (map[y][x] == '1')
			return (true);
	}
	return (false);
}

bool	ft_has_right_wall(char **map, int y, int x)
{
	while (map[y][x])
	{
		if (map[y][x] == ' ')
			return (false);
		if (map[y][x] == '1')
			return (true);
		x++;
	}
	return (false);
}

bool	ft_has_top_wall(char **map, int y, int x)
{
	while (y--)
	{
		if (map[y][x] == ' ')
			return (false);
		if (map[y][x] == '1')
			return (true);
	}
	return (false);
}

bool	ft_has_bottom_wall(char **map, int y, int x)
{
	while (map[y])
	{
		if (map[y][x] == ' ')
			return (false);
		if (map[y][x] == '1')
			return (true);
		y++;
	}
	return (false);
}
