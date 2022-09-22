/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:05:38 by sam               #+#    #+#             */
/*   Updated: 2022/09/22 16:09:26 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	ft_save_in_struct(unsigned int philo, unsigned int death,
		unsigned int eat, unsigned int sleep, unsigned int meal,
		t_thread_data	*th_data)
{
		th_data->nb_of_philo = philo;
		th_data->time_to_die = death;
		th_data->time_to_eat = eat;
		th_data->time_to_sleep = sleep;
		th_data->nb_of_meal = meal;
		th_data->philosophe = malloc(sizeof(*th_data->philosophe) 
			* (th_data->nb_of_philo));
		if (!th_data->philosophe)
			return (-15);
		th_data->mutex_fork_arr = malloc(sizeof(pthread_mutex_t)
			* (th_data->nb_of_philo));
		if (!th_data->mutex_fork_arr)
			return (-15);
		return (0);
}

// a faire :

// void	ft_free_clean_struct(t_thread_data *th_data)
// {
	  //DESTROY MUTEX
// }