/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:54:59 by jmetelin          #+#    #+#             */
/*   Updated: 2019/11/06 09:49:34 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	if (str)
	{
		while (ft_isspace(*str))
			str++;
		if (*str == '-')
			sign = -1;
		if (*str == '+' || *str == '-')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			result = result * 10 + *str - '0';
			str++;
		}
	}
	return (result * sign);
}
