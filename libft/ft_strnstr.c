/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:28:15 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/05 15:38:04 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	if (!(n = ft_strlen(needle)))
		return ((char *)haystack);
	while (haystack && *haystack && len-- >= n)
	{
		if (!ft_memcmp(haystack++, needle, n))
			return ((char *)(haystack - 1));
	}
	return ((char *)NULL);
}
