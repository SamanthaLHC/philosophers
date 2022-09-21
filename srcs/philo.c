/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:03:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/21 18:35:33 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>

// creer un tableau malloqué de mutex, un mutex = une forkette
//dans ma struct
// dans ma structure assigne une position en fonction d un philo (droite ou gauche)

void	*ft_simulation()
{
	t_thread_data	th_data;
	pthread_mutex_lock(&th_data.mutex_item);
	printf("a precious item, we don't want to share it\n");
	pthread_mutex_unlock(&th_data.mutex_item);
	return NULL;
}

int	ft_philo(t_thread_data *th_data)
{
		unsigned int	i;

		i = 1;
		pthread_mutex_init(&th_data->mutex_item, NULL);
		while (i <= th_data->nb_of_philo)
		{
			if (pthread_create(th_data->philosophe + i, NULL, &ft_simulation, 
				NULL) != 0)
				return (1);
			printf("Philosophe '%u' is thinking.\n", i);
			i++;
		}
		i = 1;
		while (i <= th_data->nb_of_philo)
		{
			if (pthread_join(th_data->philosophe[i], NULL) != 0)
				return (2);
			printf("Philosophe '%u' is dead, poor thing.\n", i);
			i++;
		}
		pthread_mutex_destroy(&th_data->mutex_item);
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
		ft_philo(&th_data);
	}
	else
		return (1);
}