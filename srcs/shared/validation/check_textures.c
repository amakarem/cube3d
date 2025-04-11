/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:21:49 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/12 00:27:35 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_check_extension(char *file)
{
	char	*extension;
	size_t	file_len;

	file_len = ft_strlen(file);
	if (file_len < 5)
		return (0);
	extension = file + (file_len - 4);
	if (!ft_strncmp(extension, ".xpm", 4) || !ft_strncmp(extension, ".png", 4))
		return (1);
	return (0);
}

static int	ft_check_north_south(t_validation *checks, char **split)
{
	if (!ft_strncmp(split[0], "NO", ft_strlen(split[0])))
	{
		if (checks->north_tex)
			return (ft_err_msg("Error\n",
					"Duplicate north texture definition."), 0);
		checks->north_tex = true;
	}
	else if (!ft_strncmp(split[0], "SO", ft_strlen(split[0])))
	{
		if (checks->south_tex)
			return (ft_err_msg("Error\n",
					"Duplicate south texture definition."), 0);
		checks->south_tex = true;
	}
	return (1);
}

static int	ft_check_east_west(t_validation *checks, char **split)
{
	if (!ft_strncmp(split[0], "EA", ft_strlen(split[0])))
	{
		if (checks->east_tex)
			return (ft_err_msg("Error\n",
					"Duplicate east texture definition."), 0);
		checks->east_tex = true;
	}
	else if (!ft_strncmp(split[0], "WE", ft_strlen(split[0])))
	{
		if (checks->west_tex)
			return (ft_err_msg("Error\n",
					"Duplicate west texture definition."), 0);
		checks->west_tex = true;
	}
	return (1);
}

int	ft_check_textures(t_validation *checks, char **split)
{
	int	fd;

	if (ft_strncmp(split[0], "NO", ft_strlen(split[0])) && ft_strncmp(split[0],
			"SO", ft_strlen(split[0])) && ft_strncmp(split[0], "EA",
			ft_strlen(split[0])) && ft_strncmp(split[0], "WE",
			ft_strlen(split[0])))
		return (1);
	if (!ft_check_north_south(checks, split))
		return (0);
	if (!ft_check_east_west(checks, split))
		return (0);
	if (checks->north_tex == true || checks->south_tex == true
		|| checks->east_tex == true || checks->west_tex == true)
	{
		if (ft_ptr_len(split) != 2)
			return (ft_err_msg("Error\n", "Invalid texture path."), 0);
		if (!ft_check_extension(split[1]))
			return (ft_err_msg("Error\n", "Wrong texture extension."), 0);
		if (ft_open_file(split[1], &fd) == -1)
			return (ft_err_msg("Error\n", "Couldn't open texture."), 0);
		close(fd);
	}
	printf("checked texture\n");
	return (1);
}
