/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:05:38 by sam               #+#    #+#             */
/*   Updated: 2022/10/04 15:40:28 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_save_arg_in_struct(int ac, char **av, t_data *data)
{
	data->nb_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 5)
		data->nb_of_meal = 0;
	else if (ac == 6)
		data->nb_of_meal = ft_atoi(av[5]);
	return (0);
}

int	ft_init_thread_and_mutex_arrays(t_data *data)
{
	data->philosophe = malloc(sizeof(*data->philosophe)
			* (data->nb_of_philo));
	if (!data->philosophe)
		return (-15);
	data->mutex_fork_arr = malloc(sizeof(pthread_mutex_t)
			* (data->nb_of_philo));
	if (!data->mutex_fork_arr)
		return (-15);
	return (0);
	data->fork = malloc(sizeof(*data->fork)
			* (data->nb_of_philo));
	if (!data->fork)
		return (-15);
}

int	ft_save_philo_data_in_array(t_data *data)
{
	data->start_meal = malloc(sizeof(*data->start_meal)
			* (data->nb_of_philo));
	if (!data->start_meal)
		return (-15);
	data->lifespan_left = malloc(sizeof(*data->lifespan_left)
			* (data->nb_of_philo));
	if (!data->lifespan_left)
		return (-15);
	return (0);
}

int	ft_save_in_struct(int ac, char **av, t_data *data)
{
	if (ft_save_arg_in_struct(ac, av, data) < 0)
		return (-15);
	if (ft_init_thread_and_mutex_arrays(data) < 0)
		return (-15);
	if (ft_save_philo_data_in_array(data) < 0)
		return (-15);
	return (0);
}


// a faire :

// void	ft_free_clean_struct(t_set *th_data)
// {
		//DESTROY MUTEX
// }