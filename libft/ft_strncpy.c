/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:23:44 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/05 15:13:23 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	if (dst && src)
	{
		while (src[index] && index < len)
		{
			dst[index] = src[index];
			index++;
		}
		while (index < len)
			dst[index++] = '\0';
	}
	return (dst);
}
