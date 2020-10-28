/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:22:17 by jmetelin          #+#    #+#             */
/*   Updated: 2020/01/27 13:53:54 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*convt(unsigned long long n, int base, char *digits)
{
	char	*s;
	int		i;

	i = get_nbr_len(n, base);
	if (!(s = ft_strnew(i)))
		exit(EXIT_FAILURE);
	while (--i >= 0)
	{
		s[i] = digits[n % base];
		n /= base;
	}
	return (s);
}

static void	convt_int(t_conv *conv)
{
	int		base;
	char	*digits;

	if (conv->conv == 'p' || conv->conv == 'x' || conv->conv == 'X')
		base = 16;
	else if (conv->conv == 'd' || conv->conv == 'i' || conv->conv == 'u')
		base = 10;
	else
		base = 8;
	if (conv->conv == 'X')
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (conv->mod == 'l' || conv->conv == 'p')
		conv->s = convt((unsigned long)conv->usgd, base, digits);
	else if (conv->mod == 'h' * 2)
		conv->s = convt((unsigned char)conv->usgd, base, digits);
	else if (conv->mod == 'h')
		conv->s = convt((unsigned short)conv->usgd, base, digits);
	else if (conv->mod == 'l' * 2)
		conv->s = convt(conv->usgd, base, digits);
	else
		conv->s = convt((unsigned int)conv->usgd, base, digits);
}

void		conv_to_str(t_conv *conv)
{
	if (conv->conv == 'c' || conv->conv == '%')
	{
		if (!(conv->s = ft_strnew(1)))
			exit(EXIT_FAILURE);
		conv->s[0] = conv->conv == 'c' ? (unsigned char)conv->sgd : '%';
	}
	else if (conv->conv == 's')
		conv->s = ft_strndup(conv->s ? conv->s : "(null)", conv->prc);
	else if (conv->conv == 'p' || is_num_conv(conv->conv))
	{
		convt_int(conv);
		if (conv->s[0] == '0' && !conv->prc)
		{
			free(conv->s);
			conv->s = ft_strdup("");
		}
	}
	else if (conv->conv == 'f')
	{
		if (conv->prc == -1)
			conv->prc = 6;
		convt_dec(conv);
	}
	if (!conv->s)
		exit(EXIT_FAILURE);
}

static void	sgd_to_usgd(t_conv *conv)
{
	if (!conv->mod || conv->mod == 'L' || conv->conv == 'c')
		conv->sgd = (int)conv->sgd;
	else if (conv->mod == 'h' * 2)
		conv->sgd = (signed char)conv->sgd;
	else if (conv->mod == 'h')
		conv->sgd = (short)conv->sgd;
	else if (conv->mod == 'l')
		conv->sgd = (long)conv->sgd;
	if (conv->sgd < 0 && conv->conv != 'c')
	{
		conv->sign = 1;
		conv->usgd = conv->sgd * -1;
	}
	else if (conv->conv != 'c')
		conv->usgd = conv->sgd;
}

void		get_conv_val(va_list ap, t_conv *conv)
{
	conv->sign = 0;
	if (conv->conv == 'c' || conv->conv == 'd' || conv->conv == 'i')
	{
		conv->sgd = va_arg(ap, long long);
		sgd_to_usgd(conv);
	}
	else if (conv->conv == 's')
		conv->s = va_arg(ap, char *);
	else if (conv->conv == 'p' || conv->conv == 'o' || conv->conv == 'u' ||
			conv->conv == 'x' || conv->conv == 'X')
		conv->usgd = va_arg(ap, unsigned long long);
	else if (conv->conv == 'f')
	{
		if (conv->mod == 'L')
			conv->d = va_arg(ap, long double);
		else
			conv->d = va_arg(ap, double);
		if (conv->d < 0.0)
		{
			conv->sign = 1;
			conv->d *= -1.0;
		}
	}
}
