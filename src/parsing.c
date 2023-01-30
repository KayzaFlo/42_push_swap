/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin42 <fgeslin42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:43:24 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/29 15:02:31 by fgeslin42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	free_parse(char **strs_ptr, int i)
{
	while (--i >= 0)
		free(strs_ptr[i]);
	free(strs_ptr);
}

void	parse(t_stack *stack_a, int argc, char const *argv[])
{
	char	**args;
	int		i;
	int		*n;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = (char **)argv + 1;
	i = -1;
	while (args[++i])
	{
		n = malloc(sizeof(int));
		if (!n)
		{
			free_parse(args, i);
			exit (-1);
		}
		*n = ft_atoi(args[i]);
		ft_lstadd_back(&stack_a->lst, ft_lstnew((void *)n));
	}
	if (argc == 2)
		free_parse(args, i);
}
