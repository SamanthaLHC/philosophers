/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:16:26 by sle-huec          #+#    #+#             */
/*   Updated: 2022/10/12 10:29:20 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

void	ft_free_and_destroy(t_data *data)
{
	free(data->philosophe);
	free(data->mutex_fork_arr);
	free(data->fork_available);
	ft_destroy_mutexes(data);
}