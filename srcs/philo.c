/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:03:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/22 16:18:24 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>

//creer un tableau malloqué de mutex, un mutex = une forkette
//dans ma struct
//dans ma structure assigne une position en fonction d un philo (droite ou gauche)

void	*ft_simulation(void *arg)
{
	t_thread_data	th_data;

	th_data = *(t_thread_data *) arg;
	printf("protect my forkette\n");
	pthread_mutex_lock(th_data.mutex_fork_arr + 1);
	printf("\"My precious fork, I don't want to share it\"\n");
	pthread_mutex_unlock(&th_data.mutex_fork_arr[1]);
	return NULL;
}

int	ft_generate_fork(t_thread_data *th_data)
{
	unsigned int	i;
	int	err;
	
	i = 0;
	while (i < th_data->nb_of_philo)
	{
		// pthread_mutex_t fork;
		// th_data->mutex_fork_arr[i] = fork;
		printf("here generate fork\n");
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
			if (pthread_create(th_data->philosophe + i, NULL, &ft_simulation,
				&th_data) != 0)
				return (1);
			printf("Philosophe '%u' is thinking.\n", i);
			i++;
		}
		i = 0;
		while (i < th_data->nb_of_philo)
		{
			if (pthread_join(th_data->philosophe[i], NULL) != 0)
				return (2);
			// after a successfull join we have to free all the terminate 
			// thread 's ressources if it is required
			printf("Philosophe '%u' is dead, poor thing.\n", i);
			i++;
		}
		pthread_mutex_destroy(&th_data->mutex_fork_arr[1]);
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
		av[5] = 0;
		if (ft_save_in_struct(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]),
					ft_atoi(av[4]), ft_atoi(av[5]), &th_data) < 0)
			return (-15);
		ft_generate_fork(&th_data);
		ft_philo(&th_data);
	}
	else
		return (1);
}