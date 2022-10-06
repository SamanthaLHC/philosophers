/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samantha <samantha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:51:44 by sle-huec          #+#    #+#             */
/*   Updated: 2022/10/06 14:56:20 by samantha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>

typedef struct s_data
{
	unsigned int	nb_of_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	nb_of_meal;
	int				start_time;
	int				*fork;
	pthread_mutex_t	*mutex_fork_arr;
	pthread_t		*philosophe;
}	t_data;

typedef struct s_set
{
	unsigned int	idx;
	unsigned int	count_meal;
	int				start_meal;
	int				deathline;
	t_data			*data;
}	t_set;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//								utils_libft.c								  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

int				ft_isdigit(char c);
unsigned int	ft_atoi(char *str);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//								check_input.c								  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

int				ft_check_args(int ac, char **av);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//								handle_struct.c								  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

int				ft_save_in_struct(int ac, char **av, t_data *data);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//								generate.c (main)							  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

int				ft_generate_fork(t_data *data);
int				ft_generate_philo(t_data *data);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//								routine.c									  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void			*ft_simulation(void *arg);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//							get_time.c										  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void			ft_init_time(t_data *data);
int				ft_get_key_moment(t_data *data);
int				ft_usleep(t_set *set_philo, int waiting_time);

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
//						key_moment.c										  //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

int				ft_time_to_eat(t_set *set_philo);
int				ft_time_to_sleep(t_set *set_philo);
int				ft_is_dead(t_set *set_philo);

#endif