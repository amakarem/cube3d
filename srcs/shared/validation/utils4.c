/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 20:48:38 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/08 20:49:36 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_init_checks(t_validation *checks)
{
	checks->north_tex = false;
	checks->south_tex = false;
	checks->east_tex = false;
	checks->west_tex = false;
	checks->floor = false;
	checks->ceiling = false;
	checks->map_started = false;
	checks->tex_and_cols = false;
	checks->validated = false;
}

char	*ft_get_map_line(int fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = ft_trim_newlines(get_next_line(fd));
		if (!line || ft_is_line_of_map(line))
			return (line);
		ft_free(&line);
	}
	return (NULL);
}

int	ft_fill_lines(char ***map, int width, int height, int fd)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	line = ft_get_map_line(fd);
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (x < (int)ft_strlen(line))
				(*map)[y][x] = line[x];
			else
				(*map)[y][x] = ' ';
			x++;
		}
		ft_free(&line);
		(*map)[y][x] = '\0';
		y++;
		line = ft_trim_newlines(get_next_line(fd));
	}
	return (ft_free(&line), 1);
}
