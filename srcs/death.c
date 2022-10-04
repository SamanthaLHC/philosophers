/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:56:46 by samantha          #+#    #+#             */
/*   Updated: 2022/10/04 10:57:48 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

//one condition leading to the death: no meal.
void	ft_init_start_meal_arr(t_set *set_philo)
{
	unsigned int	i;

	i = 0;
	while (i < set_philo->data->nb_of_philo)
	{
		set_philo->data->start_meal[i] = -5;
		i++;
	}
}

void	ft_save_start_meal(t_set *set_philo)
{
	unsigned int	i;

	i = 0;
	while (i < set_philo->data->nb_of_philo)
	{
		set_philo->data
			->start_meal[set_philo->idx] = ft_get_key_moment(set_philo->data);
		i++;
	}
	// idem: faire un tableau de count_meal
	// set_philo->count_meal = set_philo->count_meal + 1;
}

//measure the lifespan left
//check if the time without meal passed
// set the death_flag variable ?
int	ft_calculate_lifespan_left(t_set *set_philo)
{
	int	lifespan_left;
	int	death_time;

	death_time = set_philo->data->time_to_die;
	printf("TIME BEFORE DEATH should be: %d\n", death_time);
	return 0;
}

int	
//if the time is passed the philo shoud die
//set the format of time to die and print the death message

// void	ft_trigger_the_death(t_set *set_philo)
// {	
// }

// check if the philo is dead or not: condition for joining
// int	ft_is_dead(t_set *set_philo)
// {
// }