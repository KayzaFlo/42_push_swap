/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:03:44 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/27 11:29:04 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack *stack)
{
	t_list	*temp;

	if (!stack)
		exit (-1);
	if (!stack->lst)
		return ;
	if (!stack->lst->next)
		return ;
	temp = stack->lst->next;
	stack->lst->next = temp->next;
	ft_lstadd_front(&stack->lst, temp);
	printf("s%c\n", stack->c);
}

void	push(t_stack *stack)
{
	t_list	*temp;

	if (!stack->twin || !stack)
		exit (-1);
	if (!stack->twin->lst)
		return ;
	temp = stack->twin->lst;
	stack->twin->lst = stack->twin->lst->next;
	ft_lstadd_front(&stack->lst, temp);
	printf("p%c\n", stack->c);
}

void	rotate(t_stack *stack)
{
	t_list	*temp;

	if (!stack)
		exit (-1);
	if (!stack->lst)
		return ;
	temp = stack->lst;
	stack->lst = stack->lst->next;
	ft_lstadd_back(&stack->lst, temp);
	printf("r%c\n", stack->c);
}

void	r_rotate(t_stack *stack)
{
	t_list	*temp;
	t_list	*newlast;

	if (!stack)
		exit (-1);
	if (!stack->lst)
		return ;
	if (!stack->lst->next)
		return ;
	newlast = stack->lst;
	while (newlast->next->next)
		newlast = newlast->next;
	temp = newlast->next;
	newlast->next = NULL;
	ft_lstadd_front(&stack->lst, temp);
	printf("rr%c\n", stack->c);
}
