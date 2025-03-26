/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:06:56 by tkeil             #+#    #+#             */
/*   Updated: 2024/10/08 13:06:56 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char) c;
	while (*s)
	{
		if (*s == cc)
			return ((char *) s);
		s++;
	}
	if (cc == '\0')
		return ((char *) s);
	return (NULL);
}

// int main(void)
// {
// 	char *s;
// 	s = "teste";
// 	printf("  last address: %p\n", (s + 4));
// 	printf("needed address: %p\n", (s + 5));
// 	printf("          test: %p\n", ft_strchr("teste", '\0'));
// 	return (0);
// }