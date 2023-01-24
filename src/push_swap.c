/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:43:24 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/24 12:16:28 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sorted_at(t_list *lst);

int	main(int argc, char const *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**args;
	int		i;
	int		*n;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = (char **)argv + 1;
	stack_b.lst = 0;
	i = -1;
	while (args[++i])
	{
		n = malloc(sizeof(int));
		if (!n)
			return (-1);
		*n = ft_atoi(args[i]);
		if (argc == 2)
			free(args[i]);
		ft_lstadd_back(&stack_a.lst, ft_lstnew((void *)n));
	}
	if (argc == 2)
		free(args);
		stack_a.c = 'a';
		stack_b.c = 'b';
	// printf("sorted? %d\n", sorted_at(stack_a));
	sort(&stack_a, &stack_b);
}
