/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:42:27 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/06 10:02:59 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*str_offset;

	if ((!s1 || !s2) || (!s1 && !s2))
		return ((char *)NULL);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return ((char *)NULL);
	str_offset = str;
	while (*s1)
		*str_offset++ = *s1++;
	while (*s2)
		*str_offset++ = *s2++;
	*str_offset = '\0';
	return (str);
}
