/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:05:38 by sam               #+#    #+#             */
/*   Updated: 2022/10/11 15:45:27 by sle-huec         ###   ########.fr       */
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
	data->fork_available = malloc(sizeof(*data->fork_available)
			* (data->nb_of_philo));
	if (!data->fork_available)
		return (-15);
	return (0);
}

int	ft_save_in_struct(int ac, char **av, t_data *data)
{
	if (ft_save_arg_in_struct(ac, av, data) < 0)
		return (-15);
	if (ft_init_thread_and_mutex_arrays(data) < 0)
		return (-15);
	return (0);
}

void	ft_init_settings_philo(t_set *arr_struct_settings, t_data *data,
	unsigned int i)
{
	arr_struct_settings->data = data;
	arr_struct_settings->idx = i;
	arr_struct_settings->start_meal = -1;
	arr_struct_settings->deathline = data->time_to_die;
	arr_struct_settings->count_meal = 0;
}

void	ft_free_and_destroy(t_data *data)
{
	unsigned int	i;

	i = 0;
	free(data->philosophe);
	free(data->mutex_fork_arr);
	free(data->fork_available);
	ft_destroy_mutexes(data);
}
