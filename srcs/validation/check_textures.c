/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:21:49 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/29 16:23:03 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int ft_check_north_south(t_validation *checks, char **split)
{
    if (!ft_strncmp(split[0], "NO", ft_strlen(split[0])))
    {
        if (checks->north_tex)
            return (ft_err_message("Error\n", "Duplicate north texture definition."), 0);
        checks->north_tex = true;
    }
    else if (!ft_strncmp(split[0], "SO", ft_strlen(split[0])))
    {
        if (checks->south_tex)
            return (ft_err_message("Error\n", "Duplicate south texture definition."), 0);
        checks->south_tex = true;
    }
    return (1);
}

static int ft_check_east_west(t_validation *checks, char **split)
{
    if (!ft_strncmp(split[0], "EA", ft_strlen(split[0])))
    {
        if (checks->east_tex)
            return (ft_err_message("Error\n", "Duplicate east texture definition."), 0);
        checks->east_tex = true;
    }
    else if (!ft_strncmp(split[0], "WE", ft_strlen(split[0])))
    {
        if (checks->west_tex)
            return (ft_err_message("Error\n", "Duplicate west texture definition."), 0);
        checks->west_tex = true;
    }
    return (1);
}

int ft_check_textures(t_validation *checks, char **split)
{
    if (!ft_check_north_south(checks, split))
        return (0);
    if (!ft_check_east_west(checks, split))
        return (0);
    if (checks->north_tex == true || checks->south_tex == true ||
        checks->east_tex == true || checks->west_tex == true)
    {
        if (ft_ptr_len(split) != 2)
        {
            write(STDERR_FILENO, "Error\n", 6);
            return (ft_err_message(split[1], ": invalid texture path"), 0);
        }
        else if (!*split[1] || open(split[1], O_RDONLY) == -1)
        {
            write(STDERR_FILENO, "Error\n", 6);
            return (ft_err_message(split[1], ": could not open texture file"), 0);
        }
        close(split[1]);
    }
    return (1);
}
