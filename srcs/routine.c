/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:26:00 by samantha          #+#    #+#             */
/*   Updated: 2022/10/12 11:49:04 by sle-huec         ###   ########.fr       */
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

int	ft_break(int even_flag, t_set *set_philo, int meal_duration)
{
	if (even_flag)
	{
		ft_usleep(set_philo, meal_duration);
		even_flag = 0;
	}
	return (even_flag);
}

int	launch_philo(pthread_mutex_t *fork, pthread_mutex_t *fork2,
		t_set *set_philo)
{
	int	even_flag;
	int	meal_duration;

	meal_duration = set_philo->data->time_to_eat * 1000;
	even_flag = set_philo->idx % 2;
	while (!ft_is_dead(set_philo)
		&& (set_philo->data->nb_of_meal == 0
			|| ft_lock_meal(set_philo) < set_philo->data->nb_of_philo))
	{
		if (ft_think(set_philo) == -4)
			return (-4);
		even_flag = ft_break(even_flag, set_philo, meal_duration);
		if (ft_takes_forks(fork, fork2, set_philo) == 1)
			return (-4);
		if (ft_time_to_eat(set_philo) == -4)
		{
			ft_releases_both_fork(fork, fork2, set_philo);
			return (-4);
		}
		ft_releases_both_fork(fork, fork2, set_philo);
		if (ft_time_to_sleep(set_philo) == -4)
			return (-4);
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
	set_philo->count_meal = 0;
	if (launch_philo(fork, fork2, set_philo) == -4)
		return (NULL);
	return (NULL);
}
