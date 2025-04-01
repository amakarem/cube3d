/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:22:58 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/01 16:19:23 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int ft_check_colors(t_validation *checks, char **split)
{
	if (ft_strncmp(split[0], "F", ft_strlen(split[0])) && ft_strncmp(split[0], "C", ft_strlen(split[0])))
		return (1);
    if (!ft_strncmp(split[0], "F", ft_strlen(split[0])))
    {
        if (checks->floor)
            return (ft_err_message("Error\n", "Duplicate floor color definition."), 0);
        checks->floor = true;
    }
    else if (!ft_strncmp(split[0], "C", ft_strlen(split[0])))
    {
        if (checks->ceiling)
            return (ft_err_message("Error\n", "Duplicate ceiling color definition."), 0);
        checks->ceiling = true;
    }
    if (checks->ceiling == true || checks->floor == true)
    {
        if (ft_ptr_len(split) != 2)
            return (ft_err_message("Error\n", "Invalid floor/ceiling color input"), 0);
        else if (!ft_valid_numbers(split[1]))
            return (ft_err_message("Error\n", "Invalid floor/ceiling color format"), 0);
    }
	printf("checked color\n");
    return (1);
}
