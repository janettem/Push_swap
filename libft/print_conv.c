/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:02:55 by jmetelin          #+#    #+#             */
/*   Updated: 2020/01/27 13:54:37 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_conv_aft_pfx(t_conv *conv, int prt)
{
	if (conv->prc > conv->len && (conv->conv == 'p' || is_num_conv(conv->conv)))
	{
		while (conv->prc-- > conv->len)
			ft_putchar('0');
	}
	else if (!conv->flags[2] && conv->flags[1] && conv->mfw > conv->ttl_len)
	{
		while (conv->mfw-- > conv->ttl_len)
		{
			ft_putchar('0');
			prt++;
		}
	}
	if (conv->conv == 'c')
		ft_putchar(conv->s[0]);
	else
		ft_putstr(conv->s);
	if (conv->flags[0] && conv->conv == 'f' && !conv->prc)
		ft_putchar('.');
	while (conv->flags[2] && conv->mfw-- > conv->ttl_len)
	{
		ft_putchar(' ');
		prt++;
	}
	return (prt);
}

int			print_conv(t_conv *conv, int prt)
{
	while (!conv->flags[2] && (!conv->flags[1] || (conv->prc >= 0 &&
					is_num_conv(conv->conv))) && conv->mfw-- > conv->ttl_len)
	{
		ft_putchar(' ');
		prt++;
	}
	if (conv->sign)
		ft_putchar('-');
	else if (conv->conv == 'p' || (conv->flags[0] && (conv->conv == 'x' ||
					conv->conv == 'X') && conv->s[0] != '0' && conv->s[0]))
		ft_putstr(conv->conv == 'X' ? "0X" : "0x");
	else if (conv->flags[0] && conv->conv == 'o' && conv->s[0] != '0')
		ft_putchar('0');
	else if ((conv->flags[4] || conv->flags[3]) && (conv->conv == 'd' ||
				conv->conv == 'i' || conv->conv == 'f'))
		ft_putchar(conv->flags[4] ? '+' : ' ');
	prt = print_conv_aft_pfx(conv, prt);
	return (prt);
}
