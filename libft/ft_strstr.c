/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:57:24 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/05 15:36:11 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n;

	if (!(n = ft_strlen(needle)))
		return ((char *)haystack);
	while (haystack && *haystack)
	{
		if (!ft_memcmp(haystack++, needle, n))
			return ((char *)(haystack - 1));
	}
	return (0);
}
