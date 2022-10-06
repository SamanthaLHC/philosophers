/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:26:00 by samantha          #+#    #+#             */
/*   Updated: 2022/10/06 15:27:50 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	ft_takes_forks(pthread_mutex_t *fork, pthread_mutex_t *fork2,
		t_set *set_philo)
{
	// while (!ft_is_dead(set_philo))
	// {
		if (pthread_mutex_lock(fork) == 0)
		{
			printf("%d %d has taken a fork (%d)\n",
				ft_get_key_moment(set_philo->data), set_philo->idx + 1,
				set_philo->idx + 1);
		}
		if (pthread_mutex_lock(fork2) == 0)
		{
			printf("%d %d has taken a fork (%d)\n",
				ft_get_key_moment(set_philo->data), set_philo->idx + 1,
				(set_philo->idx + 1) % set_philo->data->nb_of_philo + 1);
		}
	// }
}

void	ft_releases_forks(pthread_mutex_t *fork, pthread_mutex_t *fork2,
		t_set *set_philo)
{
	(void) set_philo;
	// printf("%-7d Philo %d is releasing fork %d\n",
	// 	ft_get_key_moment(set_philo->data), set_philo->idx + 1,
	// 	(set_philo->idx + 1) % set_philo->data->nb_of_philo + 1);
	if (pthread_mutex_unlock(fork2) != 0)
		return ;
	// printf("%-7d Philo %d is releasing fork %d\n",
	// 	ft_get_key_moment(set_philo->data), set_philo->idx + 1,
	// 	set_philo->idx + 1);
	if (pthread_mutex_unlock(fork) != 0)
		return ;
}

// -4 ->is dead
// -2 -> usleep error
int	launch_philo(pthread_mutex_t *fork, pthread_mutex_t *fork2,
		t_set *set_philo)
{
	int	even_flag;

	printf("Starting with deathline %i\n", set_philo->deathline);
	even_flag = set_philo->idx % 2;
	while (1)
	{
		if (even_flag)
		{
			ft_takes_forks(fork, fork2, set_philo);
			if (ft_time_to_eat(set_philo) == -4)
			{
				ft_releases_forks(fork, fork2, set_philo);
				return (-4);
			}
			ft_releases_forks(fork, fork2, set_philo);
		}
		if (ft_time_to_sleep(set_philo) == -4)
			return (-4);
		even_flag = 1;
	}
	return (0);
}

void	*ft_simulation(void *arg)
{
	t_set			*set_philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*fork2;

	set_philo = (t_set *) arg;
	fork = set_philo->data->mutex_fork_arr + set_philo->idx;
	fork2 = set_philo->data->mutex_fork_arr + ((set_philo->idx + 1)
			% set_philo->data->nb_of_philo);
	if (launch_philo(fork, fork2, set_philo) == -4)
	{
		printf("%d %d died\n", ft_get_key_moment(set_philo->data),
			set_philo->idx + 1);
		// free everything
		return (NULL);
	}
	else if (launch_philo(fork, fork2, set_philo) == -2)
	{
		//free everything
		return (NULL);
	}
	return (NULL);
}
