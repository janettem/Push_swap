/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:38:46 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/06 10:49:12 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if ((!dst || !src) || (!dst && !src))
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n-- > 0)
	{
		if ((*d++ = *s++) == (unsigned char)c)
			return (d);
	}
	return (NULL);
}
