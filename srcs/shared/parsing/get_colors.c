/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:40:31 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/11 20:08:23 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_get_col(uint32_t *col, char *rgb, int endian)
{
	int		r;
	int		g;
	int		b;
	char	**split;

	(void)endian;
	split = ft_split(rgb, ',');
	if (!split)
		return (0);
	r = ft_atoi(split[0]) & 0xFF;
	g = ft_atoi(split[1]) & 0xFF;
	b = ft_atoi(split[2]) & 0xFF;
	*col = (r << 16) | (g << 8) | b;
	ft_free_ptr(&split);
	return (1);
}

int	ft_get_colors(t_data *data, char **split)
{
	if (!ft_strncmp(split[0], "F", ft_strlen(split[0])))
	{
		if (!ft_get_col(&data->floor_color, split[1], data->buffer->endian))
			return (0);
	}
	else if (!ft_strncmp(split[0], "C", ft_strlen(split[0])))
	{
		if (!ft_get_col(&data->ceiling_color, split[1], data->buffer->endian))
			return (0);
	}
	return (1);
}
