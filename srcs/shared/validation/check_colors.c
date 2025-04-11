/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:22:58 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/12 00:27:35 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_check_floor(t_validation *checks, char **split)
{
	if (!ft_strncmp(split[0], "F", ft_strlen(split[0])))
	{
		if (checks->floor)
			return (ft_err_msg("Error\n",
					"Duplicate floor color definition."), 0);
		checks->floor = true;
	}
	return (1);
}

static int	ft_check_ceiling(t_validation *checks, char **split)
{
	if (!ft_strncmp(split[0], "C", ft_strlen(split[0])))
	{
		if (checks->ceiling)
			return (ft_err_msg("Error\n",
					"Duplicate ceiling color definition."), 0);
		checks->ceiling = true;
	}
	return (1);
}

int	ft_check_colors(t_validation *checks, char **split)
{
	if (ft_strncmp(split[0], "F", ft_strlen(split[0])) && ft_strncmp(split[0],
			"C", ft_strlen(split[0])))
		return (1);
	if (!ft_check_floor(checks, split))
		return (0);
	else if (!ft_check_ceiling(checks, split))
		return (0);
	if (checks->ceiling == true || checks->floor == true)
	{
		if (ft_ptr_len(split) != 2)
			return (ft_err_msg("Error\n",
					"Invalid floor/ceiling color input"), 0);
		else if (!ft_valid_numbers(split[1]))
			return (ft_err_msg("Error\n",
					"Invalid floor/ceiling color format"), 0);
	}
	printf("checked color\n");
	return (1);
}
