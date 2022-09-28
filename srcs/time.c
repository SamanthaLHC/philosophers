/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:06:08 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/28 16:05:38 by sle-huec         ###   ########.fr       */
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
	data->begin_time = cur_time.tv_usec * 1000 + cur_time.tv_usec / 1000;
}

// get time at the moment of the keys actions ()
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
	unsigned int	result;

	result = ft_current_time() - data->begin_time;
	printf("%u  ", result);
}

//todo

// int	ft_time_to_eat()
// {
// }

// int ft_is_time_of_death()
// {
// }

// //enum dans .h ? ret permettant d identifier l etat (eat / die / sleep)
// int ft_which_state()
