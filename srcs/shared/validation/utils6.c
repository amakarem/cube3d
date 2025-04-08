/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:26:39 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/08 21:27:24 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_outside_horizontal(char **map, int y, int x)
{
	bool	left;
	bool	right;

	left = ft_check_left(map, y, x);
	right = ft_check_right(map, y, x);
	return (left && right);
}

int	ft_outside_vertical(char **map, int y, int x)
{
	bool	top;
	bool	bottom;

	top = ft_check_top(map, y, x);
	bottom = ft_check_bottom(map, y, x);
	return (top && bottom);
}

int	ft_is_outside_map(char **map, int y, int x)
{
	return (ft_outside_horizontal(map, y, x) && ft_outside_vertical(map, y, x));
}
