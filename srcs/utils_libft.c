/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:16:26 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/19 13:20:42 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

unsigned int	ft_atoi(const char *str)
{
	unsigned int	i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
		|| str[i] == '\f')
		i++;
	if (str[i] == '-')
		return (0);
	else if (str[i] == '+')
		i++;
	while ((str[i] && str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}