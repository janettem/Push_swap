/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:20:27 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/05 15:11:35 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*dst_offset;

	dst_offset = dst;
	if (dst && src)
	{
		while (*src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (dst_offset);
}
