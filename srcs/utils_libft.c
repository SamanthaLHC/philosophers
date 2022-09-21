/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:16:26 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/21 16:36:17 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

unsigned int	ft_atoi(char *str)
{
	unsigned int	i;
	unsigned int	result;

	if (str == NULL)
		return (0);
	i = 0;
	result = 0;
	while (str && (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' 
		|| str[i] == '\r' || str[i] == '\f'))
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
