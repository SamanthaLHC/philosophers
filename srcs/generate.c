/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:03:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/30 18:25:45 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int	ft_generate_fork(t_data *data)
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
		if (pthread_create(data->philosophe
				+ i, NULL, &ft_simulation, &arr_struct_settings[i]) != 0)
			return (1);
		i++;
	}
	// move join thread in anothor func
	i = 0;
	while (i < data->nb_of_philo)
	{
		if (pthread_join(data->philosophe[i], NULL) != 0)
			return (2);
		printf ("%-7u Philo %d finished.\n", ft_get_key_moment(data), i + 1);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_fork_arr[i]);
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
		ft_generate_fork(&data);
		ft_generate_philo(&data);
		// HERE: call a function free_tabs_and_destroy_mutex
	}
	else
		return (1);
}
