/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:03:15 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/28 20:19:53 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_is_map_closed(char **map)
{
    size_t  x;
    size_t  y;

    y = 0;
    while (map[y][x])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '0' || map[y][x] == 'N' ||
                map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
            {
                if (!ft_is_wall_blocked(map, y, x))
                    return (0);
            }
            x++;
        }
        y++;
    }
    return (1);
}


int ft_valid_map_characters(char **map)
{
    size_t  i;
    size_t  j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (ft_strncmp("0", map[i][j], 1) && ft_strncmp("1", map[i][j], 1) &&
                ft_strncmp("N", map[i][j], 1) && ft_strncmp("S", map[i][j], 1) &&
                ft_strncmp("E", map[i][j], 1) && ft_strncmp("W", map[i][j], 1) &&
                ft_strncmp(" ", map[i][j], 1))
                return (0);            
            j++;
        }
        i++;
    }
}

int ft_is_present_player_and_unique(char **map)
{
    size_t  i;
    size_t  j;
    size_t  players;

    i = 0;
    players = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (!ft_strncmp("N", map[i][j], 1) && !ft_strncmp("S", map[i][j], 1) &&
                !ft_strncmp("E", map[i][j], 1) && !ft_strncmp("W", map[i][j], 1))
                players++;
            j++;
        }
        i++;
    }
    return (players == 1);
}
