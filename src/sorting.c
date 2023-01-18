/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:28 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/18 15:29:07 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// static void	better_sort(t_list **stack_a, t_list **stack_b);

static void	choosefun(t_list **a, t_list **b, char *f)
{
	printf("%s\n", f);
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
	// better_sort(a, b);
}

// int	is_sorted(t_list *lst)
// {
// 	int	a;
//
// 	if (!lst)
// 		return (0);
// 	a = *(int *)lst->content;
// 	while (lst->next)
// 	{
// 		if (a > *(int *)(lst->next->content))
// 			return (0);
// 		lst = lst->next;
// 		a = *(int *)lst->content;
// 	}
// 	return (1);
// }

int	sorted_at(t_list *lst)
{
	int		i;
	int		ret;
	int		a;
	int		first;
	t_list	*cur;

	if (!lst)
		return (0);
	cur = lst;
	i = 0;
	ret = 0;
	a = *(int *)cur->content;
	first = a;
	while (cur->next)
	{
		if (a > *(int *)(cur->next->content))
		{
			if (*(int *)cur->next->content > first || ret)
				return (-1);
			else if (*(int *)cur->next->content == first)
				return (i);
			first = *(int *)cur->next->content;
			cur = cur->next;
			a = *(int *)cur->content;
			ret = i + 1;
			// i = 0;
			continue ;
			// return (0);
		}
		cur = cur->next;
		a = *(int *)cur->content;
		i++;
	}
	if (*(int *)cur->content > *(int *)lst->content && ret)
		return (-1);
	return (ret);
}

// static void	sorting(t_list **stack_a, t_list **stack_b)
// {
// 	t_list *temp;
// 	int		sort;
// 	int		size;
//
// 	size = ft_lstsize(*stack_a);
// 	if (*stack_a)
// 	{
// 		sort = sorted_at(*stack_a);
// 		if (sort > 0)
// 		{
// 			if (sort > size / 2)
// 				choosefun(stack_a, stack_b, "rra");
// 			else
// 				choosefun(stack_a, stack_b, "ra");
// 			return ;
// 		}
// 		if (!*stack_b && !sort)
// 			return ;
// 		choosefun(stack_a, stack_b, "sa");
// 		return ;
//
// 		if ((*stack_a)->next)
// 		{
// 			if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
// 			{
// 				choosefun(stack_a, stack_b, "sa");
// 				return ;
// 			}
// 		}
// 		temp = *stack_b;
// 		while(temp)
// 		{
// 			if (*(int *)(*stack_a)->content < *(int *)temp->content)
// 			{
// 				choosefun(stack_a, stack_b, "pa");
// 				return ;
// 			}
// 			temp = temp->next;
// 		}
// 		if (is_sorted(*stack_a))
// 			choosefun(stack_a, stack_b, "pa");
// 		else
// 			choosefun(stack_a, stack_b, "pb");
// 		return ;
// 	}
// }

// void	better_sort(t_list **stack_a, t_list **stack_b)
// {
// 	int		sort;
// 	int		size;

// 	size = ft_lstsize(*stack_a);
// 	if (size > 3)
// 			choosefun(stack_a, stack_b, "pb");
// 	if (!*stack_a)
// 		return ;
// 	sort = sorted_at(*stack_a);
// 	if (sort > 0)
// 	{
// 		if (sort > size / 2)
// 			choosefun(stack_a, stack_b, "rra");
// 		else
// 			choosefun(stack_a, stack_b, "ra");
// 		return ;
// 	}
// 	if (sort == -1)
// 		choosefun(stack_a, stack_b, "sa");
// 	if (!*stack_b)
// 		return ;
		
// }

int	put_after(t_list *lst, int a)
{
	int	min;
	int	max;

	min = *(int *)lst->content;
	max = *(int *)lst->content;
	while (lst->next)
	{
		if (*(int *)lst->content < min)
			min = *(int *)lst->content;
		if (*(int *)lst->next->content > max)
			max = *(int *)lst->next->content;
		// printf ("HUH\n");
		if (*(int *)lst->content < a && *(int *)lst->next->content > a)
// {			printf("%d\n", *(int *)lst->content);
		return (*(int *)lst->content);
// }
		lst = lst->next;
	}
	return (max);
}

int	get_index(t_list *lst, int a)
{
	int i = 0;

	while (*(int *)lst->content != a)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	sort(t_list *stack_a, t_list *stack_b)
{
	int	ind;
	// better_sort(&stack_a, &stack_b);

	while (sorted_at(stack_a) == -1)
	{
		if (ft_lstsize(stack_a) > 3)
			choosefun(&stack_a, &stack_b, "pb");
		else
			choosefun(&stack_a, &stack_b, "sa");
	}
	while (stack_b)
	{
		ind = get_index(stack_a, put_after(stack_a, *(int *)stack_b->content));
		// printf ("HUH %d\n", ind);
		if (ind + 1 > ft_lstsize(stack_a) / 2)
			while (++ind < ft_lstsize(stack_a))
				choosefun(&stack_a, &stack_b, "rra");
		else
			while (--ind >= 0)
				choosefun(&stack_a, &stack_b, "ra");
		choosefun(&stack_a, &stack_b, "pa");
	}
	while (sorted_at(stack_a) > 0)
	{
		if (sorted_at(stack_a) > ft_lstsize(stack_a) / 2)
			choosefun(&stack_a, &stack_b, "rra");
		else
			choosefun(&stack_a, &stack_b, "ra");
	}

	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
