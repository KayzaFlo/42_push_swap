/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:28 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/30 11:49:00 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	before;

	while (is_sorted_at(stack_a->lst) == -1)
	{
		if (ft_lstsize(stack_a->lst) > 3)
			print_call(stack_b, push);
		else
			print_call(stack_a, swap);
	}
	while (stack_b->lst)
	{
		before = put_before(stack_a->lst, *(int *)stack_b->lst->content);
		smart_rotate(stack_a, before, before);
		print_call(stack_a, push);
	}
}
