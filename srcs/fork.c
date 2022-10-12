/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:16:32 by samantha          #+#    #+#             */
/*   Updated: 2022/10/12 11:59:12 by sle-huec         ###   ########.fr       */
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

int	take_first_fork(int i_have_the_fork, pthread_mutex_t *fork,
	t_set *set_philo)
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
	return (i_have_the_fork);
}

int	take_second_fork(int i_have_the_fork2, pthread_mutex_t *fork2,
	t_set *set_philo)
{
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
	return (i_have_the_fork2);
}
