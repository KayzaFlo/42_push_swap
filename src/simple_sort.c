/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:28 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/27 13:01:27 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	before;

	while (is_sorted_at(stack_a->lst) == -1)
	{
		if (ft_lstsize(stack_a->lst) > 3)
			push(stack_b);
		else
			swap(stack_a);
	}
	while (stack_b->lst)
	{
		before = put_before(stack_a->lst, *(int *)stack_b->lst->content);
		smart_rotate(stack_a, before, before);
		push(stack_a);
	}
}
