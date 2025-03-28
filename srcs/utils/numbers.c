/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:51:09 by tkeil             #+#    #+#             */
/*   Updated: 2025/03/28 12:08:12 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// convert 0xFFFF color values to integers
int	ft_hex_to_int(const char *str)
{
	int		i;
	int 	sum;
    int		index;

	i = 2;
	sum = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
            index = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
            index = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
            index = str[i] - 'A' + 10;
		else
			return (-1);
		sum = sum * 16 + index;
		i++;
	}
	return (sum);
}
