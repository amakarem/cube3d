/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:29:20 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/06 14:30:42 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_trim_newlines(char *line)
{
	char	*ptr;

	if (!line)
		return (NULL);
	ptr = ft_strtrim(line, "\n");
	return (free(line), ptr);
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
