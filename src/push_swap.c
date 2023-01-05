/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:43:24 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/05 14:44:08 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void debugprint(t_list **a, t_list **b, char *f)
{
	printf("------\n");
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

int main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		i;
	int		*n;

	if (argc != 2)
	{
		printf("Error\n");
		return (-1);
	}
	stack_b = 0;
	args = ft_split(argv[1], ' ');
	i = -1;
	while(args[++i])
	{
		n = malloc(sizeof(int));
		if (!n)
			return (-1);
		*n = ft_atoi(args[i]);
		ft_lstadd_back(&stack_a, ft_lstnew((void *)n));
	}
	debugprint(&stack_a, &stack_b, "sa");
	debugprint(&stack_a, &stack_b, "pb");
	debugprint(&stack_a, &stack_b, "pb");
	debugprint(&stack_a, &stack_b, "pb");
	debugprint(&stack_a, &stack_b, "rr");
	debugprint(&stack_a, &stack_b, "rrr");
	debugprint(&stack_a, &stack_b, "sa");
	debugprint(&stack_a, &stack_b, "pa");
	debugprint(&stack_a, &stack_b, "pa");
	debugprint(&stack_a, &stack_b, "pa");
}
