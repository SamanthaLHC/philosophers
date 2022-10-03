/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:56:46 by samantha          #+#    #+#             */
/*   Updated: 2022/10/03 16:15:11 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

// save the start time of the meal in struct with key moment
// set the count_meal variable (stoppp the simulation if n meal)

void	ft_init_start_meal_arr(t_set *set_philo)
{
	unsigned int	i;

	i = 0;
	while (i < set_philo->data->nb_of_philo)
	{
		set_philo->data->start_meal[i] = 0;
		i++;
	}
}

void	ft_save_start_meal(t_set *set_philo)
{
	unsigned int	i;

	i = 0;
	while (i < set_philo->data->nb_of_philo)
	{
		set_philo->data->start_meal[set_philo->idx] = ft_get_key_moment(set_philo->data);
		i++;
	}
	// idem: faire un tableau de count_meal
	// set_philo->count_meal = set_philo->count_meal + 1;
}

//measure the time spend by the philo without eating anything
//  set the deat_flag variable ?
// and check if the time without meal passed
// int	ft_check_time_after_meal(t_set *set_philo)
// {
// }

//if the time is passed the philo shoud die

// void	ft_trigger_the_death(t_set *set_philo)
// {	
// }

// set the format of time to die and print the death message
// int	ft_time_to_die(t_set *set_philo)
// {	
// }


// check if the philo is dead or not: condition for joining
// int	ft_is_dead(t_set *set_philo)
// {
// }