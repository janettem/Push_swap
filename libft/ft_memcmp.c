/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:11:36 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/05 15:45:36 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	if ((!s1 || !s2) && n > 0)
		return (1);
	else if ((!s1 && !s2) || ((!s1 || !s2) && !n))
		return (0);
	while (n-- > 0)
	{
		c1 = *(unsigned char *)s1++;
		c2 = *(unsigned char *)s2++;
		if (c1 != c2)
			return (c1 - c2);
	}
	return (0);
}
