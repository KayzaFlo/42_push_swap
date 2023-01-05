/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:28 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/05 16:02:17 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	debugprint(t_list **a, t_list **b, char *f) // Debug
{
	printf("------\n");
	printf("Exec '%s':\n", f);
	while (*a || *b)
	{
		if (*a)
		{
			printf("%d", *(int *)(*a)->content);
			a = &(*a)->next;
		}
		printf("\t");
		if (*b)
		{
			printf("%d", *(int *)(*b)->content);
			b = &(*b)->next;
		}
		printf("\n");
	}
	printf("-\t-\na\tb\n");
}

static void	choosefun(t_list **a, t_list **b, char *f)
{
	if (f[0] == 's')
	{
		if (f[1] == 'a' || f[1] == 's')
			swap(a);
		if (f[1] == 'b' || f[1] == 's')
			swap(b);
	}
	if (f[0] == 'p')
	{
		if (f[1] == 'a')
			push(b, a);
		if (f[1] == 'b')
			push(a, b);
	}
	if (f[0] == 'r')
	{
		if (f[1] == 'a')
			rotate(a);
		if (f[1] == 'b')
			rotate(b);
		if (f[1] == 'r')
		{
			if (f[2] == '\0')
			{
				rotate(a);
				rotate(b);
			}
			if (f[2] == 'a')
				r_rotate(a);
			if (f[2] == 'b')
				r_rotate(b);
			if (f[2] == 'r')
			{
				r_rotate(a);
				r_rotate(b);
			}
		}
	}
	debugprint(a, b, f); // Debug
}

void	sort(t_list *stack_a, t_list *stack_b)
{
	debugprint(&stack_a, &stack_b, "init"); // Debug
	choosefun(&stack_a, &stack_b, "sa"); // Debug
	choosefun(&stack_a, &stack_b, "pb"); // Debug
	choosefun(&stack_a, &stack_b, "pb"); // Debug
	choosefun(&stack_a, &stack_b, "pb"); // Debug
	choosefun(&stack_a, &stack_b, "sa"); // Debug
	choosefun(&stack_a, &stack_b, "pa"); // Debug
	choosefun(&stack_a, &stack_b, "pa"); // Debug
	choosefun(&stack_a, &stack_b, "pa"); // Debug
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
