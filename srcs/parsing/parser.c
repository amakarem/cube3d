/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:50:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/27 15:03:14 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_validate_map(char *file)
{
    int     fd;
    char    *line;
    
    fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), 0);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        free(line);
    }
    return (1);
}

int ft_validate_line(char *line)
{
    size_t  i;
    char    **split;

    i = 0;
    split = ft_split(line, ' ');
    if (!split)
    {
        write(STDERR_FILENO, "Error: heap allocation failed!", 30);
        return (0);
    }
    while (split[i])
    {
        
    }
    return (1);
}

int ft_create_matrix(t_data *data, char *file)
{
    int     fd;
    char    *line;
    
    (void)data;
    fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), 0);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        if (!ft_validate_line(line))
            return (free(line), 0);
        free(line);
    }
    return (1);
}

int ft_parse_map(t_data *data, char **argv)
{
    if (!ft_validate_map(argv[1]))
        return (0);
    if (!ft_create_matrix(data, argv[1]))
        return (0);
    return (1);
}
