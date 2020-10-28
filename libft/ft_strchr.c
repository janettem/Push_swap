/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 09:23:11 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/05 15:30:56 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (s)
	{
		str = (char *)s;
		while (*str)
		{
			if (*str == c)
				return (str);
			str++;
		}
		if (*str == c)
			return (str);
	}
	return ((char *)NULL);
}
