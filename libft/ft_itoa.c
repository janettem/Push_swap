/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:28:55 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/06 11:07:51 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*n_to_str(char *str, int n, int len)
{
	str[len--] = '\0';
	while (n > 0)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	if (!len)
		str[len] = '-';
	return (str);
}

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

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (!n)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	len += count_digits(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return ((char *)NULL);
	n_to_str(str, n, len);
	return (str);
}
