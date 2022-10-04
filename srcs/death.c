/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:56:46 by samantha          #+#    #+#             */
/*   Updated: 2022/10/04 21:06:19 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

//one condition leading to the death: no meal.

int	ft_calculate_lifespan_left(t_set *set_philo)
{
	int	lifespan_left;
	int	time_limit_before_death;

	time_limit_before_death = set_philo->data->time_to_die;
	if (set_philo->start_meal < 0)
		lifespan_left = time_limit_before_death;
	else
		lifespan_left = time_limit_before_death - set_philo->start_meal;
	printf("TIME BEFORE DEATH for PHILO %d should be: %d\n", set_philo->idx + 1, lifespan_left);
	return (lifespan_left);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

//  to fix:
// - debugg: tous les lifespan ne s'affichent pas (boucle? tableau?)
// - calcul incorrect: données en output ne corresopndent pas avec les attendus

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


//check if the time without meal passed
// void ft_check_longevity()
// {
// }

//if the time is passed the philo shoud die
//print the death message
// void	ft_trigger_the_death(t_set *set_philo)
// {	
// }

// check if the philo is dead or not: condition for joining
// int	ft_is_dead(t_set *set_philo)
// {
// }
