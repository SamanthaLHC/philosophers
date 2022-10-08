/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:26:00 by samantha          #+#    #+#             */
/*   Updated: 2022/10/08 13:16:18 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	ft_releases_fork(pthread_mutex_t *fork, t_set *set_philo)
{
	pthread_mutex_lock(fork);
	set_philo->data->fork_available[set_philo->idx] = 1;
	if (pthread_mutex_unlock(fork) != 0)
		return ;
}

void	ft_releases_fork2(pthread_mutex_t *fork2, t_set *set_philo)
{
	pthread_mutex_lock(fork2);
	set_philo->data->fork_available[(set_philo->idx + 1)
		% set_philo->data->nb_of_philo] = 1;
	if (pthread_mutex_unlock(fork2) != 0)
		return ;
}

void	ft_releases_both_fork(pthread_mutex_t *fork, pthread_mutex_t *fork2,
	t_set *set_philo)
{
	ft_releases_fork(fork, set_philo);
	ft_releases_fork2(fork2, set_philo);
}

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
		if (pthread_mutex_lock(fork) == 0)
		{
			if (set_philo->data->fork_available[set_philo->idx])
			{
				printf("%d %d has taken a fork (%d)\n",
					ft_get_key_moment(set_philo->data), set_philo->idx + 1,
					set_philo->idx + 1);
				set_philo->data->fork_available[set_philo->idx] = 0;
				i_have_the_fork = 1;
			}
		}
		if (pthread_mutex_unlock(fork) != 0)
			return (0);
		if (pthread_mutex_lock(fork2) == 0)
		{
			if (set_philo->data->fork_available[(set_philo->idx + 1)
					% set_philo->data->nb_of_philo])
			{
				printf("%d %d has taken a fork (%d)\n",
					ft_get_key_moment(set_philo->data), set_philo->idx + 1,
					(set_philo->idx + 1) % set_philo->data->nb_of_philo + 1);
				set_philo->data->fork_available[(set_philo->idx + 1)
					% set_philo->data->nb_of_philo] = 0;
				i_have_the_fork2 = 1;
			}
		}
		if (pthread_mutex_unlock(fork2) != 0)
			return (0);
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
	while (1)
	{
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
