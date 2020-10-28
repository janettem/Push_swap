/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbrs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:41:42 by jmetelin          #+#    #+#             */
/*   Updated: 2020/02/20 14:28:35 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_dup(t_stack *stack, int item)
{
	int		i;

	i = stack->top - 1;
	while (i >= 0)
	{
		if (stack->items[i--] == item)
			return (1);
	}
	return (0);
}

static int	a_to_i(const char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	sign = 0;
	i = 0;
	if (ft_strlen(str) > 11)
		handle_error();
	if (str[i] == '-')
	{
		sign = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + str[i++] - '0';
	if (i < 1 || (i == 1 && sign) || str[i])
		handle_error();
	if (sign)
		nbr *= -1;
	if (nbr < -2147483648 || nbr > 2147483647)
		handle_error();
	return (nbr);
}

void		fill(t_stack *stack, char **nbrs)
{
	int		item;
	int		i;

	i = stack->max_size - 1;
	while (i >= 0)
	{
		if (is_dup(stack, item = a_to_i(nbrs[i--])))
			handle_error();
		push(stack, item);
	}
}

t_stack		*initialize(int size)
{
	t_stack	*stack;
	int		*items;

	stack = (t_stack *)malloc(sizeof(t_stack));
	items = (int *)malloc(sizeof(int) * size);
	if (!stack || !items)
		handle_error();
	stack->items = items;
	stack->max_size = size;
	stack->top = 0;
	return (stack);
}

char		**get_nbrs(char **av, int ac)
{
	char	**nbrs;
	char	*tmp[2];
	int		i;

	i = 1;
	tmp[0] = ft_strdup(av[i]);
	while (++i < ac)
	{
		tmp[1] = ft_strjoin(tmp[0], " ");
		free(tmp[0]);
		tmp[0] = ft_strjoin(tmp[1], av[i]);
		free(tmp[1]);
	}
	nbrs = ft_strsplit(tmp[0], ' ');
	free(tmp[0]);
	return (nbrs);
}
