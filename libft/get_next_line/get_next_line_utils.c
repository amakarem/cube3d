/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:35:38 by tkeil             #+#    #+#             */
/*   Updated: 2024/11/20 14:15:20 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen2(s))
		return (ft_strdup2(""));
	size = ft_strlen2(s + start);
	if (size > len)
		size = len;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr2(const char *str, int c)
{
	char	cc;

	cc = (char) c;
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == cc)
			return ((char *) str);
		str++;
	}
	if (cc == '\0')
		return ((char *) str);
	return (NULL);
}

char	*ft_strdup2(const char *s)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen2(s);
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*s;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen2(s1) + ft_strlen2(s2);
	s = (char *) malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
