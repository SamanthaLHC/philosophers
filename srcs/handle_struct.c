/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:05:38 by sam               #+#    #+#             */
/*   Updated: 2022/09/21 18:02:07 by sam              ###   ########.fr       */
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
			* (th_data->nb_of_philo + 1));
		if (!th_data->philosophe)
			return (-15);
		return (0);
}