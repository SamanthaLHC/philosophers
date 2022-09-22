/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:18:13 by sam               #+#    #+#             */
/*   Updated: 2022/09/22 18:01:45 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	check_neg(char *av)
{
	if (av[0] == '-')
	{
		printf("Usage error: you have to pass a positiv number.\n");
		return (-2);
	}
	return (0);
}

int	str_is_digit(char *av)
{
	int	i_char;

	i_char = 0;
	if (av[0] == '-')
		i_char++;
	while (av[i_char])
	{
		if (!ft_isdigit(av[i_char]))
		{
			printf("Usage error: only digits required.\n");
			return (-2);
		}
		i_char++;
	}
	return (0);
}

int	ft_check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (str_is_digit(av[1]) == -2)
		return (-2);
	if (ft_atoi(av[1]) < 1)
	{
		printf("Minimum number of philosophe is 1.\n");
		return (-2);
	}
	while (av[i] && i < ac)
	{
		if (str_is_digit(av[i]) < 0)
			return (-2);
		if (check_neg(av[i]) < 0)
			return (-2);
		i++;
	}
	return (0);
}
