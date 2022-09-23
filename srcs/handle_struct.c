/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:05:38 by sam               #+#    #+#             */
/*   Updated: 2022/09/23 13:22:54 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_save_in_struct(int ac, char **av, t_thread_data	*th_data)
{
	th_data->nb_of_philo = ft_atoi(av[1]);
	th_data->time_to_die = ft_atoi(av[2]);
	th_data->time_to_eat = ft_atoi(av[3]);
	th_data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 5)
		th_data->nb_of_meal = 0;
	else if (ac == 6)
		th_data->nb_of_meal = ft_atoi(av[5]);
	th_data->philosophe = malloc(sizeof(*th_data->philosophe)
			* (th_data->nb_of_philo));
	if (!th_data->philosophe)
		return (-15);
	th_data->mutex_fork_arr = malloc(sizeof(pthread_mutex_t)
			* (th_data->nb_of_philo));
	if (!th_data->mutex_fork_arr)
		return (-15);
	return (0);
}

// a faire :

// void	ft_free_clean_struct(t_thread_data *th_data)
// {
	  //DESTROY MUTEX
// }