/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:13:33 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/06 11:09:29 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int		digits;

	digits = 0;
	while (n > 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	str[11];
	int		len;

	if (!n)
		ft_putstr_fd("0", fd);
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (!n || n == -2147483648)
		return ;
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	len += count_digits(n);
	str[len--] = '\0';
	while (n > 0)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	if (!len)
		str[len] = '-';
	ft_putstr_fd(str, fd);
}
