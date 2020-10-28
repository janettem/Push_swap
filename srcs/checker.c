/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:36:54 by jmetelin          #+#    #+#             */
/*   Updated: 2020/02/20 14:43:08 by jmetelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exe_insts(t_stack *a, t_stack *b, int *insts, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (insts[i] == 0 || insts[i] == 2)
			swap(a);
		if (insts[i] == 1 || insts[i] == 2)
			swap(b);
		else if (insts[i] == 3)
			push_inst(a, b);
		else if (insts[i] == 4)
			push_inst(b, a);
		else if (insts[i] == 5 || insts[i] == 7)
			rotate(a);
		if (insts[i] == 6 || insts[i] == 7)
			rotate(b);
		else if (insts[i] == 8 || insts[i] == 10)
			reverse_rotate(a);
		if (insts[i] == 9 || insts[i] == 10)
			reverse_rotate(b);
		i++;
	}
}

static int	*add_elem(int *tmp, int size, int elem)
{
	int		*array;
	int		i;

	if (!(array = (int *)malloc(sizeof(int) * size)))
		handle_error();
	i = 0;
	while (i < size - 1)
	{
		array[i] = tmp[i];
		i++;
	}
	if (size > 1)
		free(tmp);
	array[i] = elem;
	return (array);
}

static void	get_inst(char *str, int *inst)
{
	if (ft_strequ(str, "sa"))
		*inst = 0;
	else if (ft_strequ(str, "sb"))
		*inst = 1;
	else if (ft_strequ(str, "ss"))
		*inst = 2;
	else if (ft_strequ(str, "pa"))
		*inst = 3;
	else if (ft_strequ(str, "pb"))
		*inst = 4;
	else if (ft_strequ(str, "ra"))
		*inst = 5;
	else if (ft_strequ(str, "rb"))
		*inst = 6;
	else if (ft_strequ(str, "rr"))
		*inst = 7;
	else if (ft_strequ(str, "rra"))
		*inst = 8;
	else if (ft_strequ(str, "rrb"))
		*inst = 9;
	else if (ft_strequ(str, "rrr"))
		*inst = 10;
	else
		handle_error();
}

static int	*get_insts(int *size)
{
	int		*insts;
	int		inst;
	char	*line;

	*size = 0;
	while (get_next_line(0, &line) > 0)
	{
		get_inst(line, &inst);
		free(line);
		*size += 1;
		insts = add_elem(insts, *size, inst);
	}
	return (insts);
}

int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*insts;
	int		size;
	char	**nbrs;

	if (ac > 1)
	{
		nbrs = get_nbrs(av, ac);
		size = 0;
		while (nbrs[size])
			size++;
		a = initialize(size);
		fill(a, nbrs);
		b = initialize(size);
		insts = get_insts(&size);
		exe_insts(a, b, insts, size);
		if (is_sorted(a, b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
