/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:44:01 by jmetelin          #+#    #+#             */
/*   Updated: 2020/02/20 14:43:00 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_bigger_nbrs(t_stack *b, t_stack *a)
{
	int		smallest;

	sort_b(b);
	while (a->top > 1 && a->items[a->top - 1] < b->items[b->top - 1])
	{
		rotate(a);
		ft_printf("ra\n");
	}
	while (b->top > 0 && b->items[b->top - 1] > a->items[0])
	{
		push_inst(a, b);
		ft_printf("pa\n");
	}
	smallest = get_smallest(a);
	while (a->items[a->top - 1] != smallest)
	{
		reverse_rotate(a);
		ft_printf("rra\n");
	}
}

static int	b_is_sorted(t_stack *b, t_stack *a)
{
	int		item;
	int		smallest;
	int		biggest;
	int		i;

	i = b->top - 1;
	if (i >= 0)
	{
		smallest = get_smallest(b);
		biggest = get_biggest(b);
		item = b->items[i];
		while (--i >= 0)
		{
			if (item < b->items[i] && item != smallest)
				return (0);
			item = b->items[i];
		}
		if (a->top > 0 && biggest > a->items[a->top - 1])
			push_bigger_nbrs(b, a);
	}
	return (1);
}

static int	are_sorted(t_stack *a, t_stack *b)
{
	int		item;
	int		i;

	i = a->top - 1;
	if (i > 0)
	{
		item = a->items[i];
		while (--i >= 0)
		{
			if (item > a->items[i])
				return (0);
			item = a->items[i];
		}
	}
	if (!b_is_sorted(b, a))
		return (0);
	return (1);
}

static void	sort_few_nbrs(t_stack *a, t_stack *b)
{
	while (a->top > 1 && !are_sorted(a, b))
	{
		if (a->items[a->top - 1] > a->items[a->top - 2] &&
				a->items[a->top - 1] > a->items[0])
		{
			rotate(a);
			ft_printf("ra\n");
		}
		else if (a->items[a->top - 2] > a->items[a->top - 1] &&
				a->items[a->top - 2] > a->items[0])
		{
			swap(a);
			rotate(a);
			ft_printf("sa\nra\n");
		}
		else if (a->items[0] > a->items[a->top - 1] &&
				a->items[0] >= a->items[a->top - 2])
			put_smallest_to_top(a, b);
	}
	sort_b(b);
	while (b->top > 0)
	{
		push_inst(a, b);
		ft_printf("pa\n");
	}
}

int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**nbrs;
	int		size;

	if (ac > 1)
	{
		nbrs = get_nbrs(av, ac);
		size = 0;
		while (nbrs[size])
			size++;
		a = initialize(size);
		fill(a, nbrs);
		b = initialize(size);
		if (!is_sorted(a, b))
		{
			if (a->top < 20)
				sort_few_nbrs(a, b);
			else
				sort_many_nbrs(a, b);
		}
	}
	return (0);
}
