/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_overflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:22:07 by fgeslin           #+#    #+#             */
/*   Updated: 2023/01/30 16:27:58 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	overflowed(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit (-1);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	atoi_overflow(const char *str)
{
	int	i;
	int	nbr;
	int	mult;

	i = 0;
	nbr = 0;
	mult = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		mult = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nbr > INT32_MAX / 10 + 1 || nbr < INT32_MIN / 10)
			overflowed();
		if (nbr * 10 * mult > INT32_MAX - (str[i] - '0')
			|| nbr * 10 * mult < INT32_MIN + (str[i] - '0'))
			overflowed();
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * mult);
}
