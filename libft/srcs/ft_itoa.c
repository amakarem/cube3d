/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:52:52 by tkeil             #+#    #+#             */
/*   Updated: 2024/10/08 12:52:52 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_calc_length(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		if (n == INT_MIN)
			n = INT_MAX;
		else
			n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_strrev(char *s)
{
	char	c;
	size_t	last;
	size_t	i;

	i = 0;
	last = ft_strlen(s) - 1;
	while (i < last)
	{
		c = s[i];
		s[i++] = s[last];
		s[last--] = c;
	}
}

static void	ft_fill(char *ptr, int n)
{
	int	p;
	int	i;

	p = 1;
	i = 0;
	if (n < 0)
	{
		p = -p;
		n = -n;
	}
	while (n > 0)
	{
		ptr[i++] = n % 10 + '0';
		n /= 10;
	}
	if (p < 0)
		ptr[i++] = '-';
	ptr[i] = '\0';
	ft_strrev(ptr);
}

char	*ft_itoa(int n)
{
	size_t	length;
	char	*ptr;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	length = ft_calc_length(n);
	ptr = (char *)malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (NULL);
	ft_fill(ptr, n);
	return (ptr);
}

// #include <stdio.h>
// int main(void)
// {
//     int zahl = INT_MIN;
//     printf("zahl = %s\n", ft_itoa(zahl));
//     return (0);
// }