/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:36:10 by fgeslin42         #+#    #+#             */
/*   Updated: 2023/01/30 13:30:35 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// "" && exit : arg NULL
// "OK\n" : a sorted && b empty
// "KO\n" : a !sorted || b !empty
// "ERROR\n" : nan, int overflow, duplicate, wrong instruction

void	call(char **str_ptr, t_stack *stack, int *i, void f(t_stack *s))
{
	char	*str;

	str = *str_ptr;
	(*i)++;
	if (str[*i] == '\0')
	{
		str = get_next_line(STDIN_FILENO);
		*i = 0;
	}
	if (str[*i] == 'a')
		f(stack);
	else if (str[*i] == 'b')
		f(stack->twin);
	else
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (-1);
	}
}

void	pick_instruction(char **str, t_stack *stack, int *i)
{
	if ((*str)[*i] == 's')
		call(str, stack, i, swap);
	else if ((*str)[*i] == 'p')
		call(str, stack, i, push);
	else if ((*str)[*i] == 'r')
	{
		if ((*str)[(*i) + 1] != 'r')
			call(str, stack, i, rotate);
		else
		{
			(*i)++;
			call(str, stack, i, r_rotate);
		}
	}
	else
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (-1);
	}
}

void	apply_instructions(t_stack *stack)
{
	char	*str;
	int		i;

	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		i = 0;
		pick_instruction(&str, stack, &i);
		i++;
		if (str[i] != '\n')
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit (-1);
		}
		str = get_next_line(STDIN_FILENO);
	}
}

static int	is_sorted(t_stack *stack)
{
	t_list	*lst;

	if (!stack)
		exit (-1);
	if (!stack->lst)
		exit (-1);
	if (!stack->lst->next)
		return (1);
	lst = stack->lst;
	while (lst->next)
	{
		if (*(int *)lst->content > *(int *)lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	main(int argc, char const *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (-1);
	parse(&stack_a, argc, argv);
	stack_b.lst = 0;
	stack_a.c = 'a';
	stack_b.c = 'b';
	stack_a.twin = &stack_b;
	stack_b.twin = &stack_a;
	apply_instructions(&stack_a);
	if (is_sorted(&stack_a) && !stack_b.lst)
	{
		printf("OK\n");
		return (0);
	}
	printf("KO\n");
	return (0);
}
