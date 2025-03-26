/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:05:01 by tkeil             #+#    #+#             */
/*   Updated: 2024/10/08 13:05:01 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	*ptr;
// 	ptr = ft_itoa(n);
// 	if (!ptr)
// 		return ;
// 	ft_putstr_fd(ptr, fd);
// 	free(ptr);
// }
//  int main(void)
// {
//      ft_putnbr_fd(2147483647, 1);
//      return (0);
//  }