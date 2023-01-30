/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:00:45 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/30 11:49:32 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	lst_getind(t_list *lst, int a)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (*(int *)lst->content == a)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

void	smart_rotate(t_stack *stack, int min, int max)
{
	int	from_start;
	int	from_end;

	if (lst_getind(stack->lst, min) < lst_getind(stack->lst, max))
	{
		from_start = min;
		from_end = max;
	}
	else
	{
		from_start = max;
		from_end = min;
	}
	if (lst_getind(stack->lst, from_start)
		< ft_lstsize(stack->lst) - lst_getind(stack->lst, from_end))
		while (lst_getind(stack->lst, from_start) > 0)
			print_call(stack, rotate);
	else
		while (lst_getind(stack->lst, from_end) > 0)
			print_call(stack, r_rotate);
}

int	is_sorted_at(t_list *lst)
{
	t_list	*cur;
	int		ind;
	int		n;

	if (!lst)
		return (0);
	cur = lst;
	ind = 0;
	n = *(int *)cur->content;
	while (cur->next)
	{
		if (*(int *)cur->content > *(int *)(cur->next->content))
		{
			if (*(int *)cur->next->content > n || lst_getind(lst, n) > 0)
				return (-1);
			else if (*(int *)cur->next->content == n)
				return (ind);
			n = *(int *)cur->next->content;
		}
		cur = cur->next;
		ind++;
	}
	if (*(int *)cur->content > *(int *)lst->content && lst_getind(lst, n) > 0)
		return (-1);
	return (lst_getind(lst, n));
}

int	put_before(t_list *lst, int a)
{
	int	min;
	int	just_above;
	int	bool;

	min = *(int *)lst->content;
	just_above = a;
	bool = 0;
	while (lst)
	{
		if (*(int *)lst->content < min)
			min = *(int *)lst->content;
		if ((*(int *)lst->content < just_above || just_above <= a)
			&& *(int *)lst->content > a)
		{
			just_above = *(int *)lst->content;
			bool = 1;
		}
		if (lst->next)
			if (*(int *)lst->content < a && *(int *)lst->next->content > a)
				return (*(int *)lst->next->content);
		lst = lst->next;
	}
	if (bool)
		return (just_above);
	return (min);
}
