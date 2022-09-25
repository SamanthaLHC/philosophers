/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:03:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/25 15:44:40 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>

void	*ft_simulation(void *arg)
{
	t_thread_data	*th_data;

	th_data = (t_thread_data *) arg;
	pthread_mutex_lock(th_data->mutex_fork_arr + i);
	printf("\"fork number: %d\"\n",)i;
	pthread_mutex_unlock(th_data->mutex_fork_arr + i);
	return (NULL);
}

// int	ft_generate_fork(t_thread_data *th_data)
// {
// 	unsigned int	i;
// 	int				err;

// 	i = 0;
// 	while (i < th_data->nb_of_philo)
// 	{
// 		err = pthread_mutex_init(th_data->mutex_fork_arr + i, NULL);
// 		if (err != 0)
// 			printf("error in mutex init\n");
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_philo(t_thread_data *th_data)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (i < th_data->nb_of_philo)
// 	{
// 		th_data->i = i;
// 		if (pthread_create(th_data->philosophe + i, NULL,
// 				&ft_simulation, th_data) != 0)
// 			return (1);
// 		// printf("Philosophe '%u' is thinking.\n", i + 1);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < th_data->nb_of_philo)
// 	{
// 		if (pthread_join(th_data->philosophe[i], NULL) != 0)
// 			return (2);
// 		// printf ("WAIT FOR THREAD NUMBER: %d\n",i + 1);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&th_data->mutex_fork_arr[i]);
// 	return (0);
// }

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
		ft_generate_fork_and_philo(&th_data);
	}
	else
		return (1);
}
