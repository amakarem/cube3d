/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:50:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/30 16:41:42 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int ft_get_data(t_data **data, int fd)
{
    char    *line;
    char    **split;

    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        split = ft_split(line, ' ');
        if (!split)
            return (ft_free_ptr(&split), 0);
        if (!ft_get_textures(data, split) || !ft_get_colors(data, split))
            break ;
        ft_free(&line);
    }
    return (1);
}

int ft_parse(t_data **data, char *file)
{
    int fd;

    if (ft_open_file(file, &fd))
        return (0);
    if (!ft_get_data(data, fd))
        return (close(fd), 0);
    return (close(fd), 1);
}
