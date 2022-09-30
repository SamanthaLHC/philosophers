/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:26:00 by samantha          #+#    #+#             */
/*   Updated: 2022/09/30 16:08:40 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	ft_takes_forks(pthread_mutex_t *fork, pthread_mutex_t *fork2,
		t_set *set_philo)
{
	if (pthread_mutex_lock(fork) == 0)
	{
		ft_print_key_moment(set_philo->data);
		printf("Philo %d takes fork %d\n", set_philo->idx + 1,
			set_philo->idx + 1);
	}
	if (pthread_mutex_lock(fork2) == 0)
	{
		ft_print_key_moment(set_philo->data);
		printf("Philo %d takes fork %d\n", set_philo->idx + 1,
			(set_philo->idx + 1) % set_philo->data->nb_of_philo + 1);
	}
}

void	ft_releases_forks(pthread_mutex_t *fork, pthread_mutex_t *fork2,
		t_set *set_philo)
{
	if (pthread_mutex_unlock(fork2) == 0)
	{
		ft_print_key_moment(set_philo->data);
		printf("Philo %d released fork %d\n", set_philo->idx + 1,
			(set_philo->idx + 1) % set_philo->data->nb_of_philo + 1);
	}
	if (pthread_mutex_unlock(fork) == 0)
	{
		ft_print_key_moment(set_philo->data);
		printf("Philo %d released fork %d\n", set_philo->idx + 1,
			set_philo->idx + 1);
	}
}

void	launch_philo(pthread_mutex_t *fork, pthread_mutex_t *fork2,
		t_set *set_philo, int odd)
{
	if ((odd && set_philo->idx % 2 != 0)
		|| (!odd && set_philo->idx % 2 == 0))
	{
		ft_takes_forks(fork, fork2, set_philo);
		if (ft_time_to_eat(set_philo) < 0)
			return ;
		ft_releases_forks(fork, fork2, set_philo);
	}
	else
		if (ft_time_to_sleep(set_philo) < 0)
			return ;
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
	launch_philo(fork, fork2, set_philo, 0);
	launch_philo(fork, fork2, set_philo, 1);
	return (NULL);
}
