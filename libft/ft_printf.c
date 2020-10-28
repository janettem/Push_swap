/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 09:17:55 by jmetelin          #+#    #+#             */
/*   Updated: 2020/01/27 13:53:39 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_num_conv(int c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

static int	get_flags(const char *restrict format, int i, int *flags)
{
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
	flags[4] = 0;
	while (format[i] == '#' || format[i] == '0' || format[i] == '-' ||
			format[i] == ' ' || format[i] == '+')
	{
		if (format[i] == '#')
			flags[0] = 1;
		else if (format[i] == '0')
			flags[1] = 1;
		else if (format[i] == '-')
			flags[2] = 1;
		else if (format[i] == ' ')
			flags[3] = 1;
		else
			flags[4] = 1;
		i++;
	}
	return (i);
}

static int	get_args(const char *restrict format, int i, t_conv *conv)
{
	i = get_flags(format, i, conv->flags);
	conv->mfw = 0;
	while (format[i] >= '0' && format[i] <= '9')
		conv->mfw = conv->mfw * 10 + format[i++] - '0';
	conv->prc = -1;
	if (format[i] == '.')
	{
		conv->prc = 0;
		while (format[++i] >= '0' && format[i] <= '9')
			conv->prc = conv->prc * 10 + format[i] - '0';
	}
	conv->mod = 0;
	if (format[i] == 'h' || format[i] == 'l' || format[i] == 'L')
	{
		conv->mod = format[i++];
		if ((format[i] == 'h' && format[i - 1] == 'h') ||
				(format[i] == 'l' && format[i - 1] == 'l'))
		{
			conv->mod *= 2;
			i++;
		}
	}
	conv->conv = format[i];
	return (i);
}

static int	put_conv(const char *restrict format, va_list ap, t_conv *conv,
		int *i)
{
	int		prt;

	prt = 0;
	*i += 1;
	if (!(conv->flags = (int *)malloc(sizeof(int) * 5)))
		exit(EXIT_FAILURE);
	*i = get_args(format, *i, conv);
	if (conv->conv != 'c' && conv->conv != 's' && conv->conv != 'p' &&
			!is_num_conv(conv->conv) && conv->conv != 'f' && conv->conv != '%')
	{
		if (conv->conv)
			ft_putchar(conv->conv);
		free(conv->flags);
		return (!conv->conv ? prt : ++prt);
	}
	get_conv_val(ap, conv);
	conv_to_str(conv);
	get_conv_len(conv);
	prt += conv->ttl_len;
	prt = print_conv(conv, prt);
	free(conv->s);
	free(conv->flags);
	return (prt);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	t_conv	*conv;
	int		prt;
	int		i;

	va_start(ap, format);
	if (!(conv = (t_conv *)malloc(sizeof(t_conv))))
		exit(EXIT_FAILURE);
	prt = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			prt++;
		}
		else
			prt += put_conv(format, ap, conv, &i);
		if (format[i])
			i++;
	}
	free(conv);
	va_end(ap);
	return (prt);
}
