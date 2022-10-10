/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:55:34 by samantha          #+#    #+#             */
/*   Updated: 2022/10/10 11:52:55 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>
#include "philo.h"


int	ft_is_nb_of_meals_reached(t_set *set_philo)
{
	if (set_philo->count_meal >= set_philo->data->nb_of_meal)
	{
		pthread_mutex_lock(&set_philo->data->meal_mutex);
		set_philo->data->ate_enough = set_philo->data->ate_enough + 1;
		pthread_mutex_unlock(&set_philo->data->meal_mutex);
	}
	if (set_philo->data->ate_enough >= set_philo->data->nb_of_philo)
		return (1);
	return (0);
}

int	ft_time_to_eat(t_set *set_philo)
{
	int	meal_duration;

	meal_duration = set_philo->data->time_to_eat * 1000;
	set_philo->start_meal = ft_get_key_moment(set_philo->data);
	set_philo->deathline = set_philo->start_meal + set_philo->data->time_to_die;
	printf("%d %d is eating\n", set_philo->start_meal,
		set_philo->idx + 1);
	set_philo->count_meal = set_philo->count_meal + 1;
	ft_is_nb_of_meals_reached(set_philo);
	printf("philo %d: count meal reach : %d\n", set_philo->idx + 1, set_philo->count_meal);
	if (ft_usleep(set_philo, meal_duration) == -4)
		return (-4);
	return (0);
}

int	ft_time_to_sleep(t_set *set_philo)
{
	int	nap_time;

	nap_time = set_philo->data->time_to_sleep * 1000;
	printf("%d %d is sleeping\n", ft_get_key_moment(set_philo->data),
		set_philo->idx + 1);
	if (ft_usleep(set_philo, nap_time) == -4)
		return (-4);
	return (0);
}

int	ft_is_dead(t_set *set_philo)
{
	if (ft_get_key_moment(set_philo->data) >= set_philo->deathline)
	{
		pthread_mutex_lock(&set_philo->data->death_lock);
		if (set_philo->data->death_flag == 0)
		{
			set_philo->data->death_flag = 1;
			printf("%d %d died\n", ft_get_key_moment(set_philo->data),
				set_philo->idx + 1);
		}
		pthread_mutex_unlock(&set_philo->data->death_lock);
		return (1);
	}
	pthread_mutex_lock(&set_philo->data->death_lock);
	if (set_philo->data->death_flag)
	{
		pthread_mutex_unlock(&set_philo->data->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&set_philo->data->death_lock);
	return (0);
}
