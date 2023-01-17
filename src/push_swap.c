/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:43:24 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/17 16:04:37 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sorted_at(t_list *lst);

int	main(int argc, char const *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		i;
	int		*n;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	stack_b = 0;
	args = ft_split(argv[1], ' ');
	i = -1;
	while (args[++i])
	{
		n = malloc(sizeof(int));
		if (!n)
			return (-1);
		*n = ft_atoi(args[i]);
		free(args[i]);
		ft_lstadd_back(&stack_a, ft_lstnew((void *)n));
	}
	free(args);
	printf("sorted? %d\n", sorted_at(stack_a));
	sort(stack_a, stack_b);
}
