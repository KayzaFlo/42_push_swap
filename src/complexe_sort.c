/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexe_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:28 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/30 15:06:43 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <math.h> //HMMMM

static int	is_in_chunk(int n, t_stack *stack, int chunk_size)
{
	int		count;
	int		size;
	t_list	*a;
	t_list	*b;

	a = stack->lst;
	b = stack->twin->lst;
	count = 0;
	size = ft_lstsize(a) + ft_lstsize(b);
	while (a)
	{
		if (*(int *)a->content < n)
			count++;
		a = a->next;
	}
	while (b)
	{
		if (*(int *)b->content < n)
			count++;
		b = b->next;
	}
	return ((size - 1 - count) / chunk_size);
}

static void	minmax(t_list *lst, int *is_found, int *min, int *max)
{
	if (!*is_found)
	{
		*is_found = 1;
		*min = *(int *)lst->content;
	}
	*max = *(int *)lst->content;
}

static void	prepare_chunk(t_stack *stack, int chunk, int chunk_size)
{
	t_list		*lst;
	int			is_found;
	int			min;
	int			max;

	is_found = 1;
	while (is_found)
	{
		lst = stack->lst;
		is_found = 0;
		while (lst)
		{
			if (is_in_chunk(*(int *)lst->content, stack, chunk_size) == chunk)
				minmax(lst, &is_found, &min, &max);
			lst = lst->next;
		}
		if (!is_found)
			break ;
		smart_rotate(stack, min, max);
		print_call(stack->twin, push);
	}
}

static void	retreive_chunk(t_stack *stack_a, t_stack *stack_b, int *r)
{
	t_list		*lst;
	int			min;
	int			max;

	while (stack_b->lst)
	{
		lst = stack_b->lst;
		min = *(int *)lst->content;
		max = *(int *)lst->content;
		while (lst)
		{
			if (*(int *)lst->content < min)
				min = *(int *)lst->content;
			if (*(int *)lst->content > max)
				max = *(int *)lst->content;
			lst = lst->next;
		}
		smart_rotate(stack_b, min, max);
		if (*(int *)stack_b->lst->content < *r)
			*r = *(int *)stack_b->lst->content;
		print_call(stack_a, push);
		if (*(int *)stack_a->lst->content == min)
			print_call(stack_a, rotate);
	}
}

void	complexe_sort(t_stack *stack_a, t_stack *stack_b)
{
	static int	chunk = 0;
	static int	repos = 0;
	int			chunk_size;
	float		div;

	div = sqrt(ft_lstsize(stack_a->lst)
			+ ft_lstsize(stack_b->lst)) / 3.4f;
	if (div > 1)
		chunk_size = (ft_lstsize(stack_a->lst)
				+ ft_lstsize(stack_b->lst)) / div;
	else
		chunk_size = ft_lstsize(stack_a->lst) + ft_lstsize(stack_b->lst);
	prepare_chunk(stack_a, chunk, chunk_size);
	if (chunk > 0)
		smart_rotate(stack_a, repos, repos);
	if (chunk == 0)
		repos = *(int *)stack_b->lst->content;
	retreive_chunk(stack_a, stack_b, &repos);
	chunk++;
	if (chunk * chunk_size < ft_lstsize(stack_a->lst))
		complexe_sort(stack_a, stack_b);
}
