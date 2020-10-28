/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:48:22 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/06 09:59:29 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		index;

	if (!s)
		return ((char *)NULL);
	if (!(str = ft_strnew(ft_strlen(s))))
		return ((char *)NULL);
	index = 0;
	while (s[index])
	{
		str[index] = f(index, s[index]);
		index++;
	}
	return (str);
}
