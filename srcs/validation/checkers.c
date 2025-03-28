/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:57:34 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/28 20:20:05 by tkeil            ###   ########.fr       */
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

int ft_check_colors(char **split)
{
    if (!ft_strncmp(split[0], "F", ft_strlen(split[0])) || !ft_strncmp(split[0], "C", ft_strlen(split[0])))
    {
        if (ft_ptr_len(split) != 2)
        {
            ft_err_message("Error\n", "Invalid floor/ceiling color input");
            return (0);
        }
        else if (!ft_valid_numbers(split[1]))
        {
            ft_err_message("Error\n", "Invalid floor/ceiling color format");
            return (0);
        }
    }
    return (1);
}

int ft_check_map(char **map)
{
    if (!ft_valid_map_characters(map))
        return (ft_err_message("Error\n", "Invalid map character."), 0);
    if (!ft_is_present_player_and_unique(map))
        return (ft_err_message("Error\n", "Either more than 1 player or none set in the map."), 0);
    if (!ft_is_map_closed(map))
        return (ft_err_message("Error\n", "Map is not closed by walls."), 0);
    return (1);
}
