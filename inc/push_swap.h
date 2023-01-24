/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:14:22 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/24 12:11:38 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	t_list	*lst;
	char	c;
} t_stack;

void	sort(t_stack *stack_a, t_stack *stack_b);

int		is_sorted_at(t_list *lst);
int		put_after(t_list *lst, int a);
int		lst_getind(t_list *lst, int a);

void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	r_rotate(t_stack *stack);

#endif