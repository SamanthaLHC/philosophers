/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:03:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/10/08 13:17:04 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int	ft_generate_mutex_fork(t_data *data)
{
	unsigned int	i;
	int				err;

	i = 0;
	while (i < data->nb_of_philo)
	{
		err = pthread_mutex_init(data->mutex_fork_arr + i, NULL);
		if (err != 0)
			printf("error in mutex init\n");
		i++;
	}
	return (0);
}

int	ft_init_fork_flag(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		data->fork_available[i] = 1;
		i++;
	}
	return (0);
}

int	ft_join(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nb_of_philo)
	{
		if (pthread_join(data->philosophe[i], NULL) != 0)
			return (2);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_fork_arr[i]);
	return (0);
}

int	ft_generate_philo(t_data *data)
{
	unsigned int	i;
	t_set			*arr_struct_settings;

	i = 0;
	arr_struct_settings = malloc(sizeof(*arr_struct_settings)
			* data->nb_of_philo);
	if (!arr_struct_settings)
		return (15);
	while (i < data->nb_of_philo)
	{
		(arr_struct_settings + i)->data = data;
		(arr_struct_settings + i)->idx = i;
		(arr_struct_settings + i)->start_meal = -1;
		(arr_struct_settings + i)->deathline = data->time_to_die;
		data->death_flag = 0;
		if (pthread_create(data->philosophe
				+ i, NULL, &ft_simulation, &arr_struct_settings[i]) != 0)
			return (1);
		i++;
	}
	ft_join(data);
	return (0);
}

int	main(int ac, char **av)
{		
	t_data	data;

	if (ac > 6 || ac < 5)
	{
		printf("Usage error: you have to pass 4 or 5 numbers as arguments.\n");
		return (-2);
	}
	if (ft_check_args(ac, av) == 0)
	{
		if (ft_save_in_struct(ac, av, &data))
			return (-15);
		ft_init_time(&data);
		ft_init_fork_flag(&data);
		ft_init_mutexes(&data);
		ft_generate_mutex_fork(&data);
		ft_generate_philo(&data);
		ft_destroy_mutexes(&data);
	}
	else
		return (1);
}
