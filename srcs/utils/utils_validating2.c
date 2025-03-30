/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validating2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:52:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/30 14:19:03 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    ft_update_check_tex_and_cols(t_validation *checks)
{
    if (checks->north_tex && checks->south_tex && checks->east_tex &&
        checks->west_tex && checks->floor && checks->ceiling)
    {
        checks->tex_and_cols = true;
    }
}

void    ft_init_checks(t_validation *checks)
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

bool ft_is_line_of_map(char *line)
{
    size_t  i;

    i = 0;
    while (line[i])
    {
        while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
            i++;
        if ((ft_strncmp(line, "NO", 2) || ft_strncmp(line, "SO", 2) ||
            ft_strncmp(line, "EA", 2) || ft_strncmp(line, "WE", 2) ||
            ft_strncmp(line, "F", 1) || ft_strncmp(line, "C", 1)) &&
            (line[i] == '0' || line[i] == '1' || line[i] == 'N' ||
                line[i] == 'S' || line[i] == 'E' || line[i] == 'W'))
        {
            return (true);
        }
    }
    return (false);
}

int ft_get_map_height(char *file)
{
    int     fd;
    int     count;
    char    *line;
    bool    map_start;
    
    if (ft_open_file(file, &fd) == -1)
        return (ft_err_message("Could not open file.", NULL), 0);
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

char    **ft_get_map(char *file, int fd)
{
    int     height;
    char    **map;
    char    *line;
    bool    map_start;
    size_t  i;

    map_start = false;
    height = ft_get_map_height(file);
    map = malloc(sizeof(char *) * (height + 1));
    if (!map)
        return (NULL);
    i = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        if (ft_is_line_of_map(line))
            map_start = true;
        if (map_start)
            map[i++] = line;
        ft_free(&line);
    }
    return (map[i] = NULL, map);
}
