/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:48:13 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/02 15:29:49 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	int		len;

	start = 0;
	len = ft_strlen(s) - 1;
	if (len < 0)
		return (ft_strdup(""));
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	len -= start - 1;
	if (len < 1)
		return (ft_strdup(""));
	if (!(str = ft_strsub(s, start, len)))
		return ((char *)NULL);
	return (str);
}
