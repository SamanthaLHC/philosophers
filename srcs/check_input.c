/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:18:13 by sam               #+#    #+#             */
/*   Updated: 2022/09/22 13:55:45 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>


   //         / \            //
  //		 / | \          //
 //         /  .  \        //
//		   /_______\      //

// NOT FINISH SHOULD CHECK IF ARG[1] > 0

int	ft_check_args(int ac, char **av)
{
	int	i;
	int	i_char;

	i = 1;
	i_char = 0;
	while (av[i] && i < ac)
	{
		if (av[i][0] == '-')
		{
			printf("Usage error: you have to pass a positiv number.\n");
			return (-2);
		}
		while (av[i][i_char])
		{
			if (!ft_isdigit(av[i][i_char]))
			{
				printf("Usage error: only digits required.\n");
				return (-2);
			}
			i_char++;
		}
		i_char = 0;
		i++;
	}
	return (0);
}