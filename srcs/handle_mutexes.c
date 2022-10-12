/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mutexes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:20:41 by sle-huec          #+#    #+#             */
/*   Updated: 2022/10/12 10:42:42 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	ft_lock_meal(t_set *set_philo)
{
	unsigned int	tmp;

	pthread_mutex_lock(&set_philo->data->meal_mutex);
	tmp = set_philo->data->ate_enough;
	pthread_mutex_unlock(&set_philo->data->meal_mutex);
	return (tmp);
}

void	ft_init_mutexes(t_data *data)
{
	pthread_mutex_init(&data->meal_mutex, NULL);
	pthread_mutex_init(&data->death_lock, NULL);
	pthread_mutex_init(&data->test_mutex, NULL);
}

void	ft_destroy_mutexes(t_data *data)
{
	unsigned int	i;

	i = 0;
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->death_lock);
	pthread_mutex_destroy(&data->test_mutex);
	while (i < data->nb_of_philo)
	{
		pthread_mutex_destroy(&data->mutex_fork_arr[i]);
		i++;
	}
}
