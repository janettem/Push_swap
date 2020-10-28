/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:33:07 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/06 10:01:47 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*str_offset;

	if (!s)
		return ((char *)NULL);
	if (!(str = ft_strnew(len)))
		return ((char *)NULL);
	str_offset = str;
	while (len-- > 0)
		*str_offset++ = s[start++];
	*str_offset = '\0';
	return (str);
}
