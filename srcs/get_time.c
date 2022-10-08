/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:06:08 by sle-huec          #+#    #+#             */
/*   Updated: 2022/10/08 13:35:37 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "philo.h"

void	ft_init_time(t_data *data)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	data->start_time = cur_time.tv_sec * 1000 + cur_time.tv_usec / 1000;
}

int	ft_get_key_moment(t_data *data)
{
	struct timeval	cur_time;
	int				key_moment;

	gettimeofday(&cur_time, NULL);
	key_moment = cur_time.tv_sec * 1000 + cur_time.tv_usec / 1000;
	key_moment = key_moment - data->start_time;
	return (key_moment);
}

int	ft_usleep(t_set *set_philo, int waiting_time)
{
	int	wake_up_time;
	int	time_left;

	wake_up_time = (waiting_time / 1000) + ft_get_key_moment(set_philo->data);
	time_left = wake_up_time - ft_get_key_moment(set_philo->data);
	while (time_left > 0)
	{
		if (ft_is_dead(set_philo))
			return (-4);
		if (time_left >= 5)
			usleep(5000);
		else
			usleep(time_left * 1000);
		time_left = wake_up_time - ft_get_key_moment(set_philo->data);
	}
	if (ft_is_dead(set_philo))
		return (-4);
	return (0);
}
