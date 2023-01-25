/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:28 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/25 17:41:52 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_to_nearest(t_stack *stack, int from_start, int from_end)
{
	if (lst_getind(stack->lst, from_start) <
		ft_lstsize(stack->lst) - lst_getind(stack->lst, from_end))
			while(lst_getind(stack->lst, from_start) > 0)
				rotate(stack);
		else
			while (lst_getind(stack->lst, from_end) > 0)
				r_rotate(stack);
}

int	is_in_chunk(int n, t_list *lst_a, t_list *lst_b, int chunk_size)
{
	int	count;
	int	size;

	count = 0;
	size = ft_lstsize(lst_a) + ft_lstsize(lst_b);
	while (lst_a)
	{
		if (*(int *)lst_a->content < n)
			count++;
		lst_a = lst_a->next;
	}
	while (lst_b)
	{
		if (*(int *)lst_b->content < n)
			count++;
		lst_b = lst_b->next;
	}
	return((size - 1 - count) / chunk_size);
}

void	complexe_sort(t_stack *stack_a, t_stack *stack_b)
{
	static int	chunk = 0;
	static int	repos = 0;
	t_list	*lst;
	int		hold_fst;
	int		hold_snd;
	int		i;
	int		chunk_size;
	int	min;
	int	max;

//PUSH STACK FROM A TO B
	hold_fst = 0;
	hold_snd = 0;
	chunk_size = (ft_lstsize(stack_a->lst) + ft_lstsize(stack_b->lst)) /
		((ft_lstsize(stack_a->lst) + ft_lstsize(stack_b->lst)) / 34 + 1); //~34 pour 100, ~75 pour 500
	while (hold_fst != -1)
	{
		lst = stack_a->lst;
		hold_fst = -1;
		hold_snd = -1;
		i = 0;
		while (lst)
		{
			if (is_in_chunk(*(int *)lst->content, stack_a->lst, stack_b->lst, chunk_size) == chunk)
			{
				if (hold_fst == -1)
				{
					hold_fst = i;
					min = *(int *)lst->content;
				}
				hold_snd = i;
				max = *(int *)lst->content;
			}
			i++;
			lst = lst->next;
		}
		if (hold_fst == -1)
			break ;
		rotate_to_nearest(stack_a, min, max);
		push(stack_a, stack_b);
	}
// REPOSITIONNE
	if (chunk > 0)
		rotate_to_nearest(stack_a, repos, repos);
	if (chunk == 0)
		repos = *(int *)stack_b->lst->content;
//PUSH STACK BACK FROM B TO A
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
		if (lst_getind(stack_b->lst, min) < lst_getind(stack_b->lst, max))
			rotate_to_nearest(stack_b, min, max);
		else
			rotate_to_nearest(stack_b, max, min);
		if (*(int *)stack_b->lst->content < repos)
			repos = *(int *)stack_b->lst->content;
		push(stack_b, stack_a);
		if (*(int *)stack_a->lst->content == min)
			rotate(stack_a);
	}
//REBOOT AND TRY AGAIN
	chunk++;
	if (chunk * chunk_size < ft_lstsize(stack_a->lst))
		complexe_sort(stack_a, stack_b);
}

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	ind;

	while (is_sorted_at(stack_a->lst) == -1)
	{
		if (ft_lstsize(stack_a->lst) > 3)
			push(stack_a, stack_b);
		else
			swap(stack_a);
	}
	while (stack_b->lst)
	{
		ind = lst_getind(stack_a->lst,
			put_after(stack_a->lst, *(int *)stack_b->lst->content));
		if (ind < ft_lstsize(stack_a->lst) - ind - 1)
		{
			while (ind >= 0)
			{
				rotate(stack_a);
				ind--;
			}
		}
		else
		{
			while (ind < ft_lstsize(stack_a->lst) - 1)
			{
				r_rotate(stack_a);
				ind++;
			}
		}
		push(stack_b, stack_a);
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_lstsize(stack_a->lst) > 5)
		complexe_sort(stack_a, stack_b);
	else
		small_sort(stack_a, stack_b);
	while (is_sorted_at(stack_a->lst) > 0)
	{
		if (is_sorted_at(stack_a->lst) > ft_lstsize(stack_a->lst) / 2)
			r_rotate(stack_a);
		else
			rotate(stack_a);
	}
	ft_lstclear(&stack_a->lst, free);
	ft_lstclear(&stack_b->lst, free);
}
