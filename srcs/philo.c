/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:03:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/23 17:55:38 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>

void	*ft_simulation(void *arg)
{
	t_thread_data	*th_data;

	th_data = (t_thread_data *) arg;
	printf("MUTEX PTR------> %p\n",th_data->mutex_fork_arr + th_data->i);
	printf("in ft_simulation___ TH_DATA->i------> %d\n",th_data->i);
	// pthread_mutex_lock(th_data->mutex_fork_arr + th_data->i);
	// printf("\"fork number: %d \"\n", th_data->i);
	// pthread_mutex_unlock(&th_data->mutex_fork_arr[th_data->i]);
	return (NULL);
}

int	ft_generate_fork(t_thread_data *th_data)
{
	unsigned int	i;
	int				err;

	i = 0;
	while (i < th_data->nb_of_philo)
	{
		printf("here generate fork %d\n", i + 1);
		err = pthread_mutex_init(th_data->mutex_fork_arr + i, NULL);
		if (err != 0)
			printf("error in mutex init\n");
		i++;
	}
	return (0);
}

int	ft_philo(t_thread_data *th_data)
{
	unsigned int	i;

	i = 0;
	while (i < th_data->nb_of_philo)
	{
		// printf("\"__in ft_philo:i = %d \"\n", th_data->i);
		th_data->i = i;
		if (pthread_create(th_data->philosophe + i, NULL,
				&ft_simulation, th_data) != 0)
			return (1);
		else
			printf("in ft_philo _____ i------> %d\n",i);
		printf("Philosophe '%u' is thinking.\n", i + 1);
		i++;
	}
	i = 0;
	while (i < th_data->nb_of_philo)
	{
		if (pthread_join(th_data->philosophe[i], NULL) != 0)
			return (2);
		printf ("WAIT FOR THREAD NUMBER: %d\n",i + 1);
		// after a successfull join we have to free all the terminate 
		// thread 's ressources if it is required
		i++;
	}
	pthread_mutex_destroy(&th_data->mutex_fork_arr[i]);
	return (0);
}

int	main(int ac, char **av)
{		
	t_thread_data	th_data;

	if (ac > 6 || ac < 5)
	{
		printf("Usage error: you have to pass 4 or 5 numbers as arguments.\n");
		return (-2);
	}
	if (ft_check_args(ac, av) == 0)
	{
		if (ft_save_in_struct(ac, av, &th_data))
			return (-15);
		ft_generate_fork(&th_data);
		ft_philo(&th_data);
	}
	else
		return (1);
}
