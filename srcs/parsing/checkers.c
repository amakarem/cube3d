/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:57:34 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/28 17:11:57 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_check_textures(char **split)
{
    if (!ft_strncmp(split[0], "NO", ft_strlen(split[0])) || !ft_strncmp(split[0], "SO", ft_strlen(split[0])) ||
        !ft_strncmp(split[0], "WE", ft_strlen(split[0])) || !ft_strncmp(split[0], "EA", ft_strlen(split[0])))
    {
        if (ft_ptr_len(split) != 2)
        {
            write(STDERR_FILENO, "Error\n", 6);
            ft_err_message(split[1], ": invalid texture path");
            return (0);
        }
        else if (!*split[1] || open(split[1], O_RDONLY) == -1)
        {
            write(STDERR_FILENO, "Error\n", 6);
            ft_err_message(split[1], ": could not open texture file");
            return (0);
        }
        close(split[1]);
    }
    return (1);
}

static int ft_valid_numbers(char *s)
{
    char **cols;

    if (!s || !*s)
        return (0);
    cols = ft_split(s, ',');
    if (!cols)
        return (0);
    if (ft_ptr_len(cols) != 3)
        return (ft_free_ptr(&cols), 0);
    while (*s)
    {
        if (!ft_isdigit(*s) && *s != ' ' && !(*s >= 9 && *s <= 13))
            return (ft_free_ptr(&cols), 0);
        s++;
    }
    return (ft_free_ptr(&cols), 1);
}

int ft_check_colors(char **split)
{
    if (!ft_strncmp(split[0], "F", ft_strlen(split[0])) || !ft_strncmp(split[0], "C", ft_strlen(split[0])))
    {
        if (ft_ptr_len(split) != 2)
        {
            write(STDERR_FILENO, "Error\n", 6);
            ft_err_message("Invalid floor/ceiling color input", NULL);
            return (0);
        }
        else if (!ft_valid_numbers(split[1]))
        {
            write(STDERR_FILENO, "Error\n", 6);
            ft_err_message("Invalid floor/ceiling color format", NULL);
            return (0);
        }
    }
    return (1);
}

int ft_check_map(char **split)
{
    size_t i;
    size_t j;

    i = 0;
    while (split[i])
    {
        j = 0;
        while (split[i][j])
        {
            if (ft_strncmp("0", split[i][j], 1) && ft_strncmp("1", split[i][j], 1) &&
                ft_strncmp("N", split[i][j], 1) && ft_strncmp("S", split[i][j], 1) &&
                ft_strncmp("E", split[i][j], 1) && ft_strncmp("W", split[i][j], 1) &&
                ft_strncmp(" ", split[i][j], 1))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
