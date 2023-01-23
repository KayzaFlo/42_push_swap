/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:50:28 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/23 17:24:39 by fgeslin          ###   ########.fr       */
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

void	better_sort(t_list **stack_a, t_list **stack_b)
{
	static int	limit = 500;
	t_list	*lst;
	int		hold_fst;
	int		hold_snd;
	int		i;

	hold_fst = 0;
	hold_snd = 0;
	while (hold_fst != -1)
	{
		lst = *stack_a;
		hold_fst = -1;
		hold_snd = -1;
		i = 0;
		while (lst)
		{
			if (*(int *)lst->content > limit - 20 && *(int *)lst->content <= limit)
			{
				if (hold_fst == -1)
					hold_fst = i;
				hold_snd = i;
			}
			i++;
			lst = lst->next;
		}
		if (hold_fst == -1)
			break;
	//printf("AHAHHAHAHA\n");
		if (hold_fst < ft_lstsize(*stack_a) - hold_snd)
			while (hold_fst > 0)
			{
				choosefun(stack_a, stack_b, "ra");
				hold_fst--;
			}
		else
			while (hold_snd < ft_lstsize(*stack_a))
			{
				choosefun(stack_a, stack_b, "rra");
				hold_snd++;
			}
		choosefun(stack_a, stack_b, "pb");
	}

	if (limit + 1 < ft_lstsize(*stack_a))
		while (*(int *)(*stack_a)->content != limit + 1)
		{
			choosefun(stack_a, stack_b, "ra");
		}
	

	int	min;
	int	max;
	while (*stack_b)
	{
		lst = *stack_b;
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
		if (hold_fst < ft_lstsize(*stack_b) - hold_snd)
		{
			while (hold_fst > 0)
			{
				choosefun(stack_a, stack_b, "rb");
				hold_fst--;
			}
		}
		else
		{
			while (hold_snd < ft_lstsize(*stack_b))
			{
				choosefun(stack_a, stack_b, "rrb");
				hold_snd++;
			}
		}
		choosefun(stack_a, stack_b, "pa");
		if (*(int *)(*stack_a)->content == min)
			choosefun(stack_a, stack_b, "ra");
	}
	
	limit -= 20;
	if (limit > 0)
		better_sort(stack_a, stack_b);
}

void	sort(t_list *stack_a, t_list *stack_b)
{
	// int	ind;
	better_sort(&stack_a, &stack_b);

	while (is_sorted_at(stack_a) > 0)
	{
		if (is_sorted_at(stack_a) > ft_lstsize(stack_a) / 2)
			choosefun(&stack_a, &stack_b, "rra");
		else
			choosefun(&stack_a, &stack_b, "ra");
	}

	// while (is_sorted_at(stack_a) == -1)
	// {
	// 	// if (*(int *)stack_a->content > *(int *)stack_a->next->content)
	// 	// 	choosefun(&stack_a, &stack_b, "sa");
	// 	// else
	// 	if (ft_lstsize(stack_a) > 3)
	// 		choosefun(&stack_a, &stack_b, "pb");
	// 	else
	// 		choosefun(&stack_a, &stack_b, "sa");
	// }
	// while (stack_b)
	// {
	// 	ind = lst_getind(stack_a, put_after(stack_a, *(int *)stack_b->content));
	// 	// printf("put_after:%d, ind:%d\n", put_after(stack_a, *(int *)stack_b->content), ind);
	// 	if (ind >= ft_lstsize(stack_a) / 2)
	// 	{
	// 		while (ind < ft_lstsize(stack_a) - 1)
	// 		{
	// 			choosefun(&stack_a, &stack_b, "rra");
	// 			ind++;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		while (ind >= 0)
	// 		{
	// 			choosefun(&stack_a, &stack_b, "ra");
	// 			ind--;
	// 		}
	// 	}
	// 	choosefun(&stack_a, &stack_b, "pa");
	// }
	// while (is_sorted_at(stack_a) > 0)
	// {
	// 	if (is_sorted_at(stack_a) > ft_lstsize(stack_a) / 2)
	// 		choosefun(&stack_a, &stack_b, "rra");
	// 	else
	// 		choosefun(&stack_a, &stack_b, "ra");
	// }

	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
