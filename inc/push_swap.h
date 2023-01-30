/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin42 <fgeslin42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:14:22 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/29 15:02:08 by fgeslin42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	t_list			*lst;
	char			c;
	struct s_stack	*twin;
}	t_stack;

void	parse(t_stack *stack_a, int argc, char const *argv[]);

void	complexe_sort(t_stack *stack_a, t_stack *stack_b);
void	simple_sort(t_stack *stack_a, t_stack *stack_b);

void	smart_rotate(t_stack *stack, int from_start, int from_end);
int		is_sorted_at(t_list *lst);
int		put_before(t_list *lst, int a);

void	swap(t_stack *stack);
void	push(t_stack *stack);
void	rotate(t_stack *stack);
void	r_rotate(t_stack *stack);

#endif