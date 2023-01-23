/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:14:22 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/23 13:11:22 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include <stdio.h>

void	sort(t_list *stack_a, t_list *stack_b);

int		is_sorted_at(t_list *lst);
int		put_after(t_list *lst, int a);
int		lst_getind(t_list *lst, int a);

void	swap(t_list **lst);
void	push(t_list **take, t_list **to);
void	rotate(t_list **lst);
void	r_rotate(t_list **lst);

#endif