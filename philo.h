/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:51:44 by sle-huec          #+#    #+#             */
/*   Updated: 2022/09/21 16:36:23 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>

typedef struct s_thread_data
{
	unsigned int		nb_of_philo;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	unsigned int		nb_of_meal;
	pthread_mutex_t		mutex_item;
	pthread_t			*philosophe;

} t_thread_data;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//								philo.c (main)								  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//								check_input.c								  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

int				ft_check_args(int ac, char **av);
int				ft_is_interpreted(char c);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//								utils_libft.c								  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

int				ft_isdigit(char c);
unsigned int	ft_atoi(char *str);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//								handle_struct.c								  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

int	ft_save_in_struct(unsigned int philo, unsigned int death, 
		unsigned int eat, unsigned int sleep, unsigned int nb_of_meal,
		t_thread_data *th_data);

#endif