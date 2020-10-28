/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:52:21 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/05 15:27:21 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	index;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	index = dst_len;
	if (dstsize <= index)
		return (dstsize + src_len);
	if (dst && src)
	{
		dstsize--;
		while (index < dstsize && *src)
			dst[index++] = *src++;
		dst[index] = '\0';
	}
	return (dst_len + src_len);
}
