/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_staff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:53:31 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/01 18:00:14 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_open_file(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		return (-1);
	return (*fd);
}

void	ft_free(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	ft_free_ptr(char ***ptr)
{
	size_t	i;

	if (!ptr || !*ptr)
		return ;
	i = 0;
	while ((*ptr)[i])
	{
		free((*ptr)[i]);
		i++;
	}
	free(*ptr);
	(*ptr) = NULL;
}

size_t	ft_ptr_len(char **ptr)
{
	size_t	i;

	if (!ptr || !*ptr)
		return (0);
	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

char	*ft_trim_newlines(char *line)
{
	char	*ptr;

	if (!line)
		return (NULL);
	ptr = ft_strtrim(line, "\n");
	return (free(line), ptr);
}
