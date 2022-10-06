/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:06:08 by sle-huec          #+#    #+#             */
/*   Updated: 2022/10/06 15:26:05 by samantha         ###   ########.fr       */
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

int	ft_usleep(t_set *set_philo, int waiting_time)
{
	int	split_time;
	int	count_each_usleep;

	split_time = waiting_time / 5000;
	count_each_usleep = 0;
	

	while (count_each_usleep < split_time)
	{

		if (!ft_is_dead(set_philo))
		{
			usleep(5000);
			count_each_usleep++;
		}
		else
			return (-4);
	}
	return (0);
}
