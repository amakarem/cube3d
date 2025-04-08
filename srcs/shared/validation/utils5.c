/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:22:47 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/08 21:25:43 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	ft_check_left(char **map, int y, int x)
{
	while (x--)
	{
		if (map[y][x] == '0')
			return (false);
		else if (map[y][x] == '1')
			break ;
	}
	return (true);
}

bool	ft_check_right(char **map, int y, int x)
{
	while (map[y][x])
	{
		if (map[y][x] == '0')
			return (false);
		else if (map[y][x] == '1')
			break ;
		x++;
	}
	return (true);
}

bool	ft_check_top(char **map, int y, int x)
{
	while (y--)
	{
		if (map[y][x] == '0')
			return (false);
		else if (map[y][x] == '1')
			break ;
	}
	return (true);
}

bool	ft_check_bottom(char **map, int y, int x)
{
	while (map[y])
	{
		if (map[y][x] == '0')
			return (false);
		else if (map[y][x] == '1')
			break ;
		y++;
	}
	return (true);
}
