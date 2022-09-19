/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:03:51 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/19 13:30:19 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	ft_generate_philo(int nb_of_philo)
{

}

void	ft_philo(unsigned int nb_of_philo, unsigned int time_to_die,
unsigned int time_to_eat, unsigned int time_to_sleep, unsigned int nb_of_meal)
{
	nb_of_philo = ft_generate_philo(nb_of_philo);
	
}

int	main(int ac, char **av)
{
	if (ac >= 5)
		ft_philo(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]),
			ft_atoi(av[4]), ft_atoi(av[5]));
	else
		return (printf("Usage error: no arg or too much arg.\n"));
}