/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:06:08 by sle-huec          #+#    #+#             */
/*   Updated: 2022/10/05 18:54:24 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "philo.h"

// Save in struct the time at the programme's start
void	ft_init_time(t_data *data)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	data->start_time = cur_time.tv_sec * 1000 + cur_time.tv_usec / 1000;
}

// get time at the keys actions's moments.
int	ft_get_key_moment(t_data *data)
{
	struct timeval	cur_time;
	int				key_moment;

	gettimeofday(&cur_time, NULL);
	key_moment = cur_time.tv_sec * 1000 + cur_time.tv_usec / 1000;
	key_moment = key_moment - data->start_time;
	return (key_moment);
}

//the three functions below,set the time format and print

int	ft_time_to_eat(t_set *set_philo)
{
	int	meal_duration;

	meal_duration = set_philo->data->time_to_eat * 1000;
	set_philo->start_meal = ft_get_key_moment(set_philo->data);
	printf("%d %d is eating\n", ft_get_key_moment(set_philo->data),
		set_philo->idx + 1);
	if (usleep(meal_duration) < 0)
		return (-1);
	printf("start meal :%d Philo : %d\n", set_philo->start_meal,
		set_philo->idx +1);
	printf("TIME BEFORE DEATH for PHILO %d should be: %d\n",
		set_philo->idx + 1, set_philo->lifespan_left);
	return (0);
}

int	ft_time_to_sleep(t_set *set_philo)
{
	int	nap_time;

	nap_time = set_philo->data->time_to_sleep * 1000;
	printf("%d %d is sleeping\n", ft_get_key_moment(set_philo->data),
		set_philo->idx + 1);
	if (usleep(nap_time) < 0)
		return (-1);
	return (0);
}

