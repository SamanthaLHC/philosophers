/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:03:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/28 18:00:21 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	ft_takes_forks(pthread_t *fork, pthread_t *fork2, t_set *set_philo)
{
		if (pthread_mutex_lock(fork) == 0)
		{
			ft_print_key_moment(set_philo->data);
			printf("\"Philo %d takes fork %d\"\n", set_philo->idx + 1, set_philo->idx + 1);
		}
		if (pthread_mutex_lock(fork2) == 0)
		{
			ft_print_key_moment(set_philo->data);
			printf("\"Philo %d takes fork %d\"\n", set_philo->idx + 1, set_philo->idx + 2);
		}
}

void	ft_releases_forks(pthread_t *fork, pthread_t *fork2, t_set *set_philo)
{
		if (pthread_mutex_unlock(fork2) == 0)
		{
			ft_print_key_moment(set_philo->data);
			printf("\"Philo %d releases fork %d\"\n", set_philo->idx + 1, set_philo->idx + 2);
		}
		if (pthread_mutex_unlock(fork) == 0)
		{
			ft_print_key_moment(set_philo->data);
			printf("\"Philo %d releases fork %d\"\n", set_philo->idx + 1, set_philo->idx + 1);
		}
}

void	*ft_simulation(void *arg)
{
	t_set			*set_philo;
	pthread_mutex_t	fork;
	pthread_mutex_t	fork2;

	set_philo = (t_set *) arg;
	fork = *(set_philo->data->mutex_fork_arr + set_philo->idx);
	// fork2 = *(set_philo->data->mutex_fork_arr + ((set_philo->idx + 1)
	// 	% set_philo->data->nb_of_philo));
	fork2 = *(set_philo->data->mutex_fork_arr + set_philo->idx + 1);
	
	// should i move this initialisation in top of main ? 
	ft_init_time(set_philo->data);
	ft_takes_forks(&fork, &fork2, &set_philo);
	// ft_time_to_eat(set_philo->data);
	ft_releases_forks(&fork, &fork2, &set_philo);
	return (NULL);
	// handle the last philo : should take the last fork and the first fork:
	// --> Use modulo nb_of_philo ? 
}

int ft_generate_fork(t_data *data)
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
	return 0;
}

int	ft_generate_philo(t_data *data)
{
	unsigned int	i;
	t_set			*arr_struct_settings;

	i = 0;
	arr_struct_settings = malloc(sizeof(*arr_struct_settings) * data->nb_of_philo);
	if (!arr_struct_settings)
		return (15);
	while (i < data->nb_of_philo)
	{
		(arr_struct_settings + i)->data = data;
		(arr_struct_settings + i)->idx = i;
		if (pthread_create(data->philosophe
				+ i, NULL, &ft_simulation, &arr_struct_settings[i]) != 0)
			return (1);
		// else
		// {
		// 	ft_print_key_moment(data);
		// 	printf("Philo '%u' is thinking...\n", i + 1);
		// }
		i++;
	}
	// fonction death, sleep idkn
	i = 0;
	while (i < data->nb_of_philo)
	{
		if (pthread_join(data->philosophe[i], NULL) != 0)
			return (2);
		ft_print_key_moment(data);
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
		ft_generate_fork(&data);
		ft_generate_philo(&data);
	}
	else
		return (1);
}
