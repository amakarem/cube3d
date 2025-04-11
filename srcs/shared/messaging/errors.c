/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:13:34 by tkeil             #+#    #+#             */
/*   Updated: 2025/04/12 00:27:35 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_err_msg(char *s1, char *s2)
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

void	ft_err_msg_exit(char *s1, char *s2)
{
	ft_err_msg(s1, s2);
	exit(1);
}
