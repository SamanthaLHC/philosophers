/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:03:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/26 16:35:29 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	*ft_simulation(void *arg)
{
	t_set	*set_philo;

	set_philo = (t_set *) arg;
	pthread_mutex_lock(set_philo->data->mutex_fork_arr + set_philo->idx);
	printf("\"fork %d\"\n", set_philo->idx + 1);
	pthread_mutex_unlock(set_philo->data->mutex_fork_arr + set_philo->idx);
	return (NULL);
}

int	ft_generate_fork_and_philo(t_data *data)
{
	unsigned int	i;
	int				err;
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
		err = pthread_mutex_init(data->mutex_fork_arr
				+ arr_struct_settings->idx, NULL);
		if (err != 0)
			printf("error in mutex init\n");
		if (pthread_create(data->philosophe
				+ i, NULL, &ft_simulation, &arr_struct_settings[i]) != 0)
			return (1);
		else
			printf("Philosophe '%u' is thinking...\n", i + 1);
		i++;
	}
	i = 0;
	while (i < data->nb_of_philo)
	{
		if (pthread_join(data->philosophe[i], NULL) != 0)
			return (2);
		printf ("philo '%d' finished.\n", i + 1);
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
		ft_generate_fork_and_philo(&data);
	}
	else
		return (1);
}
