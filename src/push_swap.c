/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:43:24 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/03 16:49:27 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void printlst(void *param)
{
	printf("%d\t", *(int *)param);
}

int main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		i;
	// t_list	*elem;
	int		*n;

	argc = 0;
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
	printf("a:");
	ft_lstiter(stack_a, printlst);
	printf("\nb:");
	ft_lstiter(stack_b, printlst);
	printf("EOF\n");
	// swap(stack_a);
	push(&stack_a, &stack_b);
	printf("a:");
	ft_lstiter(stack_a, printlst);
	printf("\nb:");
	ft_lstiter(stack_b, printlst);
	printf("EOF\n");	return 0;
}
