/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:00:45 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/23 13:28:10 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted_at(t_list *lst)
{
	t_list	*cur;
	int		ind;
	int		fst_ind;
	int		fst_nb;

	if (!lst)
		return (0);
	cur = lst;
	ind = 0;
	fst_ind = 0;
	fst_nb = *(int *)cur->content;
	while (cur->next)
	{
		if (*(int *)cur->content > *(int *)(cur->next->content))
		{
			if (*(int *)cur->next->content > fst_nb || fst_ind)
				return (-1);
			else if (*(int *)cur->next->content == fst_nb)
				return (ind);
			fst_nb = *(int *)cur->next->content;
			fst_ind = ind + 1;
		}
		cur = cur->next;
		ind++;
	}
	if (*(int *)cur->content > *(int *)lst->content && fst_ind)
		return (-1);
	return (fst_ind);
}

int	put_after(t_list *lst, int a)
{
	int	max;
	int	below;

	max = -1;
	below = -1;
	while (lst)
	{
		if (*(int *)lst->content > max)
			max = *(int *)lst->content;
		if (*(int *)lst->content > below && *(int *)lst->content < a)
			below = *(int *)lst->content;
		if (lst->next)
			if (*(int *)lst->content < a && *(int *)lst->next->content > a)
				return (*(int *)lst->content);
		lst = lst->next;
	}
	if (below >= 0)
		return (below);
	else
		return (max);
}

int	lst_getind(t_list *lst, int a)
{
	int i = 0;

	while (*(int *)lst->content != a)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
