/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:43:24 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/30 13:53:12 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	init_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->lst = 0;
	stack_a->c = 'a';
	stack_b->c = 'b';
	stack_a->twin = stack_b;
	stack_b->twin = stack_a;
}

int	main(int argc, char const *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	parse(&stack_a, argc, argv);
	init_stacks(&stack_a, &stack_b);
	if (ft_lstsize(stack_a.lst) > 5)
		complexe_sort(&stack_a, &stack_b);
	else
		simple_sort(&stack_a, &stack_b);
	while (is_sorted_at(stack_a.lst) > 0)
	{
		if (is_sorted_at(stack_a.lst) > ft_lstsize(stack_a.lst) / 2)
			print_call(&stack_a, r_rotate);
		else
			print_call(&stack_a, rotate);
	}
	ft_lstclear(&stack_a.lst, free);
	ft_lstclear(&stack_b.lst, free);
}
