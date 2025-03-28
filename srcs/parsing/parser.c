/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:50:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/28 18:31:18 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int    ft_get_textures(t_data **data, char *line)
{
    char **split;

    split = ft_split(line, ' ');
    if (!split)
        return (0);
    (*data)->north->img = mlx_xpm_file_to_image((*data)->mlx_ptr, split[1], (*data)->north->width, (*data)->north->height);
}

int ft_get_data(t_data **data, int fd)
{
    int     fd;
    char    *line;
    
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        ft_get_textures(data, line);
        ft_get_colors(data, line);
        ft_get_map(data, line);
        free(line);
    }
    return (1);
}

int ft_parse_map(t_data **data, char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd = -1)
        return (ft_err_message("Error opening .cub file", NULL), 0);
    if (!ft_get_data(data, fd))
        return (0);
    return (1);
}
