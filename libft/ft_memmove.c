/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:11:00 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/05 14:40:43 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	if (dst && src)
	{
		d = (char *)dst;
		s = (char *)src;
		if (d < s)
		{
			while (len-- > 0)
				*d++ = *s++;
		}
		else
		{
			d += len;
			s += len;
			while (len-- > 0)
				*--d = *--s;
		}
	}
	return (dst);
}
