/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:03:44 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/05 16:01:20 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		exit (-1);
	if (!*lst)
		return ;
	if (!(*lst)->next)
		return ;
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	ft_lstadd_front(lst, temp);
}

void	push(t_list **from, t_list **to)
{
	t_list	*temp;

	if (!from || !to)
		exit (-1);
	if (!*from)
		return ;
	temp = *from;
	*from = (*from)->next;
	ft_lstadd_front(to, temp);
}

void	rotate(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		exit (-1);
	if (!*lst)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	ft_lstadd_back(lst, temp);
}

void	r_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*newlast;

	if (!lst)
		exit (-1);
	if (!*lst)
		return ;
	if (!(*lst)->next)
		return ;
	newlast = *lst;
	while (newlast->next->next)
		newlast = newlast->next;
	temp = newlast->next;
	newlast->next = NULL;
	ft_lstadd_front(lst, temp);
}
