/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:13:34 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/28 11:31:50 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_err_message(char *s1, char *s2)
{
	if (s1)
	{
		while (*s1)
			write(STDERR_FILENO, s1++, 1);
	}
	if (s2)
	{
		while (*s2)
			write(STDERR_FILENO, s2++, 1);
	}
	write(STDERR_FILENO, "\n", 1);
}

void	ft_err_message_exit(char *s1, char *s2)
{
	ft_err_message(s1, s2);
	exit(1);
}
