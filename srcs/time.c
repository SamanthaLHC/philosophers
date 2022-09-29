/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:06:08 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/29 12:50:27 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "philo.h"

// Save in struct the time ath the programme's start
void	ft_init_time(t_data *data)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, NULL);
	data->start_time = cur_time.tv_usec * 1000 + cur_time.tv_usec / 1000;
}

// get time at the keys actions's moments.
unsigned int	ft_current_time(void)
{
	struct timeval	cur_time;
	unsigned int	time;
	
	gettimeofday(&cur_time, NULL);
	time = cur_time.tv_usec * 1000 + cur_time.tv_usec / 1000;
	return (time);
}

// ajouter une enum en deuxieme parametre pour ajouter les messages
// correspondant aux actions ??
void	ft_print_key_moment(t_data *data)
{
	unsigned int	key_moment;

	key_moment = ft_current_time() - data->start_time;
	printf("%u  ", key_moment);
}

int	ft_time_to_eat(t_set *set_philo)
{
	unsigned int meal_duration = set_philo->data->time_to_eat * 1000;
	if (usleep(meal_duration) < 0)
		return (-1);
	ft_print_key_moment(set_philo->data);
	printf("Philo %d eats\n", set_philo->idx + 1);
	return (0);
}

// int ft_is_time_of_death()
// {
// }

// //enum dans .h ? ret permettant d identifier l etat (eat / die / sleep)??
// int ft_which_state()
