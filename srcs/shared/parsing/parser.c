/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:50:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/11 22:02:43 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_get_data(t_data *data, int fd)
{
	char	*line;
	char	**split;

	while (1)
	{
		line = ft_trim_newlines(get_next_line(fd));
		if (!line)
			break ;
		if (!*line)
		{
			free(line);
			continue ;
		}
		split = ft_split(line, ' ');
		ft_free(&line);
		if (!split)
			return (0);
		if (!ft_get_textures(data, split) || !ft_get_colors(data, split))
		{
			ft_free_ptr(&split);
			break ;
		}
		ft_free_ptr(&split);
	}
	return (1);
}

int	ft_parse(t_data *data, char *file)
{
	int	fd;

	if (ft_open_file(file, &fd) == -1)
		return (0);
	if (!ft_get_data(data, fd))
		return (close(fd), 0);
	return (close(fd), 1);
}
