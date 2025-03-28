/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:16:28 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/28 17:13:33 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int  ft_validate_line(char *line)
{
    char    **split;

    split = ft_split(line, ' ');
    if (!split)
        return (0);
    if (!ft_check_textures(split) ||
        !ft_check_colors(split) ||
        !ft_check_map(split))
        return (ft_free_ptr(&split), 0);
    return (ft_free_ptr(&split), 1);
}

static int  ft_validate_cub_format(char *file)
{
    int     fd;
    char    *line;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        write(STDERR_FILENO, "Error\n", 6);
        ft_err_message("Could not open .cub file", NULL);
        return (close(fd), 0);
    }
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        if (!ft_validate_line(line))
            return (close(fd), 0);
        free(line);
    }
    return (close(fd), 1);
}

int ft_validate_cub_file(char *file)
{
    char    *format;

    if (ft_strlen(file) < 5)
    {
        write(STDERR_FILENO, "Error\n", 6);
        ft_err_message(file, ": invalid .cub filename");
        return (0);
    }
    format = file + (ft_strlen(file) - 4);
    if (ft_strncmp(format, ".cub", 4) != 0)
    {
        write(STDERR_FILENO, "Error\n", 6);
        ft_err_message(file, ": invalid .cub file extension");
        return (0);
    }
    if (!ft_validate_cub_format(file))
        return (0);
    return (ft_err_message(".cub file was validated successfully!", NULL), 1);
}
