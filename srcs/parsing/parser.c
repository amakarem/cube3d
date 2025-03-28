/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:50:02 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/28 16:58:25 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int ft_validate_map(char *file)
// {
//     int     fd;
//     int     
//     char    *line;
    
//     fd = open(file, O_RDONLY);
// 	if (fd == -1)
// 		return (perror("Error opening file"), 0);
//     while (1)
//     {
//         line = get_next_line(fd);
//         if (!line)
//             break ;
//         if (!ft_validate_line(line, ))
//             return (free(line), 0);
//         free(line);
//     }
//     return (1);
// }

int ft_open_cub_file(int *fd, char *file)
{
    *fd = open(file, O_RDONLY);
	if (*fd == -1)
		return (ft_err_message("Error opening file", NULL), 0);
    
}

int ft_create_matrix(t_data *data, char *file)
{
    int     fd;
    char    *line;
    
    (void)data;
    if (!ft_open_cub_file(&fd, file))
        return (0);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;

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
