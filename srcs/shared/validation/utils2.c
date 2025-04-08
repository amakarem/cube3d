/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:52:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/08 20:49:31 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_update_check_tex_and_cols(t_validation *checks)
{
	if (checks->north_tex && checks->south_tex && checks->east_tex
		&& checks->west_tex && checks->floor && checks->ceiling)
	{
		checks->tex_and_cols = true;
	}
}

bool	ft_is_line_of_map(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (false);
	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
		i++;
	if ((ft_strncmp(line, "NO", 2) && ft_strncmp(line, "SO", 2)
			&& ft_strncmp(line, "EA", 2) && ft_strncmp(line, "WE", 2)
			&& ft_strncmp(line, "F", 1) && ft_strncmp(line, "C", 1))
		&& (line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W'))
	{
		return (true);
	}
	return (false);
}

int	ft_get_map_height(char *file)
{
	int		fd;
	int		count;
	char	*line;
	bool	map_start;

	if (ft_open_file(file, &fd) == -1)
		return (ft_err_message("Could not open .cub file.", NULL), 0);
	count = 0;
	map_start = false;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_is_line_of_map(line))
			map_start = true;
		if (map_start)
			count++;
		ft_free(&line);
	}
	return (close(fd), count);
}

int	ft_get_map_width(char *file)
{
	int		fd;
	size_t	count;
	char	*line;
	bool	map_start;

	if (ft_open_file(file, &fd) == -1)
		return (ft_err_message("Could not open .cub file.", NULL), 0);
	count = 0;
	map_start = false;
	while (1)
	{
		line = ft_trim_newlines(get_next_line(fd));
		if (!line)
			break ;
		if (ft_is_line_of_map(line))
			map_start = true;
		if (map_start && ft_strlen(line) > count)
			count = ft_strlen(line);
		ft_free(&line);
	}
	return (close(fd), count);
}

char	**ft_get_map(char *file, int fd)
{
	int		i;
	int		height;
	int		width;
	char	**map;

	height = ft_get_map_height(file);
	width = ft_get_map_width(file);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = malloc(sizeof(char) * (width + 1));
		if (!map[i])
			return (ft_free_ptr(&map), NULL);
		i++;
	}
	ft_fill_lines(&map, width, height, fd);
	return (map[height] = NULL, map);
}
