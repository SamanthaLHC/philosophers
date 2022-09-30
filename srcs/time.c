/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:06:08 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/30 16:13:53 by samantha         ###   ########.fr       */
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
unsigned int	ft_current_time(void)
{
	struct timeval	cur_time;
	unsigned int	time;

	gettimeofday(&cur_time, NULL);
	time = cur_time.tv_sec * 1000 + cur_time.tv_usec / 1000;
	return (time);
}

void	ft_print_key_moment(t_data *data)
{
	unsigned int	key_moment;

	key_moment = ft_current_time() - data->start_time;
	printf("%-7u", key_moment);
}

int	ft_time_to_eat(t_set *set_philo)
{
	unsigned int	meal_duration;

	meal_duration = set_philo->data->time_to_eat * 1000;
	ft_print_key_moment(set_philo->data);
	printf("Philo %d is eating\n", set_philo->idx + 1);
	if (usleep(meal_duration) < 0)
		return (-1);
	return (0);
}

int	ft_time_to_sleep(t_set *set_philo)
{
	unsigned int	nap_time;

	nap_time = set_philo->data->time_to_sleep * 1000;
	ft_print_key_moment(set_philo->data);
	printf("Philo %d is sleeping\n", set_philo->idx + 1);
	if (usleep(nap_time) < 0)
		return (-1);
	return (0);
}
