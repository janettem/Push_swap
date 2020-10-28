/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:02:07 by jmetelin          #+#    #+#             */
/*   Updated: 2020/01/27 13:57:20 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		get_conv_len(t_conv *conv)
{
	if ((conv->len = ft_strlen(conv->s)) == 0 && conv->conv == 'c')
		conv->len++;
	conv->ttl_len = conv->len;
	if (conv->conv == 'p' || conv->conv == 'x' || conv->conv == 'X')
	{
		conv->ttl_len += conv->conv == 'p' ||
			(conv->flags[0] && conv->s[0] != '0' && conv->s[0]) ? 2 : 0;
	}
	else if (conv->conv == 'd' || conv->conv == 'i')
		conv->ttl_len += conv->sign || conv->flags[4] || conv->flags[3] ? 1 : 0;
	else if (conv->conv == 'o')
	{
		conv->len += conv->flags[0] && conv->s[0] != '0' ? 1 : 0;
		conv->ttl_len = conv->len;
	}
	else if (conv->conv == 'f')
	{
		conv->ttl_len += (conv->sign || conv->flags[4] || conv->flags[3] ? 1 :
				0) + (conv->flags[0] && !conv->prc ? 1 : 0);
	}
	if (conv->conv == 'p' || is_num_conv(conv->conv))
		conv->ttl_len += conv->prc > conv->len ? conv->prc - conv->len : 0;
}

static void	get_frac(t_conv *conv, int frac, char *tmp[3])
{
	free(tmp[1]);
	tmp[1] = convt(frac, 10, "0123456789");
	if ((frac = ft_strlen(tmp[1])) < conv->prc)
	{
		frac = conv->prc - frac;
		if (!(tmp[2] = ft_strnew(frac)))
			exit(EXIT_FAILURE);
		if (!(conv->s = ft_strjoin(ft_memset(tmp[2], '0', frac), tmp[1])))
			exit(EXIT_FAILURE);
		free(tmp[2]);
		free(tmp[1]);
		tmp[1] = conv->s;
	}
}

static int	ft_iterative_power(int nb, int power)
{
	int res;

	res = 1;
	while (power-- > 0)
		res *= nb;
	return (res);
}

void		convt_dec(t_conv *conv)
{
	unsigned long long	inte;
	unsigned long long	frac;
	unsigned int		pwr;
	char				*tmp[3];

	inte = (unsigned long long)(conv->prc <= 0 ? conv->d + 0.5 : conv->d);
	if (conv->prc <= 0)
		conv->s = convt(inte, 10, "0123456789");
	else
	{
		pwr = ft_iterative_power(10, conv->prc);
		if ((frac = (unsigned long long)((conv->d - inte) * pwr + 0.5)) >= pwr)
		{
			inte++;
			frac = 0;
		}
		tmp[1] = convt(inte, 10, "0123456789");
		if (!(tmp[0] = ft_strjoin(tmp[1], ".")))
			exit(EXIT_FAILURE);
		get_frac(conv, frac, tmp);
		if (!(conv->s = ft_strjoin(tmp[0], tmp[1])))
			exit(EXIT_FAILURE);
		free(tmp[0]);
		free(tmp[1]);
	}
}

int			get_nbr_len(unsigned long long n, int base)
{
	int		len;

	len = 0;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len < 1 ? 1 : len);
}
