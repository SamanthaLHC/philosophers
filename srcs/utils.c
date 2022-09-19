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

int	ft_atoi(const char *str)
{
	int	i = 0;
	int result = 0;
	int pos_or_neg = 1;

	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
	 || str[i] == '\f')
		i++;	
	if (str[i] == '-')
	{
		pos_or_neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while((str[i] && str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * pos_or_neg);
}
