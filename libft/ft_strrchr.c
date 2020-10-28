/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:22:27 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/05 15:31:55 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;

	if (s)
	{
		str = (char *)s;
		len = ft_strlen(s);
		while (*str)
			str++;
		if (*str == c)
			return (str);
		if (len)
			str--;
		while (len > 0)
		{
			if (*str == c)
				return (str);
			str--;
			len--;
		}
	}
	return ((char *)NULL);
}
