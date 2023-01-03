/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manips.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:03:44 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/03 16:50:25 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_list *lst)
{
	void *temp;

	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
}

void	push(t_list **take, t_list **to)
{
	// void *temp;

	if (!*take)
		return ;
	ft_lstadd_back(to, *take);
	*take = (*take)->next;
	(*to)->next = 0;
}

// void	rotate(t_list *lst)
// {

// }

// void	r_rotate(t_list *lst)
// {

// }
