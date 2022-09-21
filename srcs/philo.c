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
#include <stdio.h>
#include <pthread.h>

// void	start_routine()
// {

// }

// void	ft_philo(unsigned int nb_of_philo, unsigned int time_to_die,
// unsigned int time_to_eat, unsigned int time_to_sleep,
//unsigned int nb_of_meal)
// {
		pthread_t 

// }

// 



int	main(int ac, char **av)
{
	if (ac > 6 || ac < 5)
	{
		printf("Usage error: you have to pass 4 or 5 numbers as arguments.\n");
		return (-1);
	}
	if (ft_check_args(ac, av) == 0)
		printf("totti va bene, can run the program.\n");
		// ft_philo(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]),
		// 	ft_atoi(av[4]), ft_atoi(av[5]));
	else
		return (1);
}