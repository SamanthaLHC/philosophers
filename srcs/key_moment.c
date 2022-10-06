/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:55:34 by samantha          #+#    #+#             */
/*   Updated: 2022/10/06 19:07:58 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>
#include "philo.h"

//set the time format and print
// in time to_eat: save the data usefull to estimate and trigger the death
int	ft_time_to_eat(t_set *set_philo)
{
	int	meal_duration;

	meal_duration = set_philo->data->time_to_eat * 1000;
	set_philo->start_meal = ft_get_key_moment(set_philo->data);
	set_philo->deathline = set_philo->start_meal + set_philo->data->time_to_die;
	printf("%d %d is eating\n", ft_get_key_moment(set_philo->data),
		set_philo->idx + 1);
	if (ft_usleep(set_philo, meal_duration) == -4)
		return (-4);
	printf("start meal :%d Philo : %d\n", set_philo->start_meal,
		set_philo->idx +1);
	printf("DEATH TIME :%d for Philo : %d\n", set_philo->deathline,
		set_philo->idx +1);
	return (0);
}

//set the time format and print
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

		set_philo->data->death_flag = 1;
		return (1);
	}
	else
		return (0);
}
