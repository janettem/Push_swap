/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:40:50 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/06 09:58:57 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		str[index] = f(s[index]);
		index++;
	}
	return (str);
}
