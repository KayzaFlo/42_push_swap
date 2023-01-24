/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:28 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/24 14:21:21 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	complexe_sort(t_stack *stack_a, t_stack *stack_b)
{
	static int	limit = 100;
	t_list	*lst;
	int		hold_fst;
	int		hold_snd;
	int		i;
	int		subdiv;

//PUSH STACK FROM A TO B
	hold_fst = 0;
	hold_snd = 0;
	subdiv = 28;
	while (hold_fst != -1)
	{
		lst = stack_a->lst;
		hold_fst = -1;
		hold_snd = -1;
		i = 0;
		while (lst)
		{
			if (*(int *)lst->content > limit - subdiv && *(int *)lst->content <= limit)
			{
				if (hold_fst == -1)
					hold_fst = i;
				hold_snd = i;
			}
			i++;
			lst = lst->next;
		}
		if (hold_fst == -1)
			break ;
		if (hold_fst < ft_lstsize(stack_a->lst) - hold_snd)
			while (hold_fst > 0)
			{
				rotate(stack_a);
				hold_fst--;
			}
		else
			while (hold_snd < ft_lstsize(stack_a->lst))
			{
				r_rotate(stack_a);
				hold_snd++;
			}
		push(stack_a, stack_b);
	}
// REPOSITIONNE
	if (limit + 1 < ft_lstsize(stack_a->lst))
	while (*(int *)stack_a->lst->content != limit + 1)
	{
		rotate(stack_a);
	}
//PUSH STACK BACK FROM B TO A
	int	min;
	int	max;
	while (stack_b->lst)
	{
		lst = stack_b->lst;
		min = 9999;
		max = 0;
		hold_fst = -1;
		hold_snd = -1;
		i = 0;
		while (lst)
		{
			if (*(int *)lst->content < min)
			{
				min = *(int *)lst->content;
				hold_fst = i;
			}
			if (*(int *)lst->content > max)
			{
				max = *(int *)lst->content;
				hold_snd = i;
			}
			i++;
			lst = lst->next;
		}
		if (hold_fst < ft_lstsize(stack_b->lst) - hold_snd)
		{
			while (hold_fst > 0)
			{
				rotate(stack_b);
				hold_fst--;
			}
		}
		else
		{
			while (hold_snd < ft_lstsize(stack_b->lst))
			{
				r_rotate(stack_b);
				hold_snd++;
			}
		}
		push(stack_b, stack_a);
		if (*(int *)stack_a->lst->content == min)
			rotate(stack_a);
	}
//REBOOT AND TRY AGAIN
	limit -= subdiv;
	if (limit > 0)
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
