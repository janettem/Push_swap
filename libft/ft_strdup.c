/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:14:37 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/05 15:08:50 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*s2_offset;

	if (!s1)
		return ((char *)NULL);
	if (!(s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return ((char *)NULL);
	s2_offset = s2;
	while (*s1)
		*s2_offset++ = *s1++;
	*s2_offset = '\0';
	return (s2);
}
