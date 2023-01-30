/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:43:24 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/30 16:27:40 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	free_parse(char **strs_ptr)
{
	int	i;

	i = 0;
	while (strs_ptr[i])
		i++;
	while (--i >= 0)
		free(strs_ptr[i]);
	free(strs_ptr);
}

static void	check_dig(char **args, int i)
{
	int		j;

	j = -1;
	while (args[i][++j])
	{
		if (args[i][j] >= '0' && args[i][j] <= '9')
			continue ;
		if (args[i][j] == '-' && j == 0 && args[i][j + 1] != '\0')
			continue ;
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit (-1);
	}
}

static int	check_dup(char **args, int **n, t_stack *stack, int i)
{
	t_list	*lst;

	lst = stack->lst;
	*n = malloc(sizeof(int));
	if (!*n)
		return (1);
	**n = atoi_overflow(args[i]);
	while (lst)
	{
		if (**n == *(int *)lst->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	parse(t_stack *stack_a, int argc, char const *argv[])
{
	char	**args;
	int		arg;
	int		i;
	int		*n;

	arg = 0;
	n = 0;
	while (++arg < argc)
	{
		args = ft_split(argv[arg], ' ');
		i = -1;
		while (args[++i])
		{
			check_dig(args, i);
			if (check_dup(args, &n, stack_a, i))
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				free_parse(args);
				exit (-1);
			}
			ft_lstadd_back(&stack_a->lst, ft_lstnew((void *)n));
		}
		free_parse(args);
	}
}
