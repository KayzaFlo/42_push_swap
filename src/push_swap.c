/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:43:24 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/27 12:51:57 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	free_parse(char **strs_ptr, int i)
{
	while (--i >= 0)
		free(strs_ptr[i]);
	free(strs_ptr);
}

static void	parse(t_stack *stack_a, int argc, char const *argv[])
{
	char	**args;
	int		i;
	int		*n;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = (char **)argv + 1;
	i = -1;
	while (args[++i])
	{
		n = malloc(sizeof(int));
		if (!n)
		{
			free_parse(args, i);
			exit (-1);
		}
		*n = ft_atoi(args[i]);
		ft_lstadd_back(&stack_a->lst, ft_lstnew((void *)n));
	}
	if (argc == 2)
		free_parse(args, i);
}

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
		ft_putstr_fd("Error\n", 2);
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
			r_rotate(&stack_a);
		else
			rotate(&stack_a);
	}
	ft_lstclear(&stack_a.lst, free);
	ft_lstclear(&stack_b.lst, free);
}
