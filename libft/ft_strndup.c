/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:38:32 by jmetelin          #+#    #+#             */
/*   Updated: 2020/01/17 11:12:44 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	char	*s2_offset;
	int		len;

	if (!s1)
		return ((char *)NULL);
	if ((size_t)(len = ft_strlen(s1)) < n)
		n = len;
	if (!(s2 = (char *)malloc(sizeof(char) * (n + 1))))
		return ((char *)NULL);
	s2_offset = s2;
	while (n-- > 0)
		*s2_offset++ = *s1++;
	*s2_offset = '\0';
	return (s2);
}
