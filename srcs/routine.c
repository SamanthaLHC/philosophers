/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:26:00 by samantha          #+#    #+#             */
/*   Updated: 2022/10/10 17:28:22 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int	ft_takes_forks(pthread_mutex_t *fork, pthread_mutex_t *fork2,
		t_set *set_philo)
{
	int	i_have_the_fork;
	int	i_have_the_fork2;
	int	is_dead;

	i_have_the_fork = 0;
	i_have_the_fork2 = 0;
	is_dead = ft_is_dead(set_philo);
	while (!is_dead && (!i_have_the_fork || !i_have_the_fork2))
	{
		i_have_the_fork = take_first_fork(i_have_the_fork, fork, set_philo);
		i_have_the_fork2 = take_second_fork(i_have_the_fork2, fork2, set_philo);
		is_dead = ft_is_dead(set_philo);
	}
	if (is_dead && i_have_the_fork)
		ft_releases_fork(fork, set_philo);
	if (is_dead && i_have_the_fork2)
		ft_releases_fork2(fork2, set_philo);
	return (is_dead);
}

int	launch_philo(pthread_mutex_t *fork, pthread_mutex_t *fork2,
		t_set *set_philo)
{
	int	even_flag;

	even_flag = set_philo->idx % 2;
	while (!ft_is_dead(set_philo) && set_philo->data->ate_enough
		< set_philo->data->nb_of_philo)
	{
		printf("ATE ENOUGH = %d\n", set_philo->data->ate_enough);
		printf(" true or not : %d\n", set_philo->data->ate_enough != set_philo->data->nb_of_philo);
		if (even_flag)
		{
			if (ft_takes_forks(fork, fork2, set_philo) == 1)
				return (-4);
			if (ft_time_to_eat(set_philo) == -4)
			{
				ft_releases_both_fork(fork, fork2, set_philo);
				return (-4);
			}
			ft_releases_both_fork(fork, fork2, set_philo);
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
		// free everything
		return (NULL);
	}
	return (NULL);
}
