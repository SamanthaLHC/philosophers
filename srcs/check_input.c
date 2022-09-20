


#include "philo.h"
#include <stdio.h>

int	ft_is_interpreted(char c)
{
	if (c == '/' || c == '=' || c == '*' || c == '<' || c == '/' || c == '$'
		|| c == '>' || c == '!' || c == '#' || c == '&' || c == '[' || c == '['
		|| c == '(' || c == ')')
		return (1);
	else
		return (0);
}

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
			return (-1);
		}
		while (av[i][i_char])
		{
			if (!ft_isdigit(av[i][i_char]) || ft_is_interpreted(av[i][i_char]))
			{
				printf("Usage error: only digits required.\n");
				return (-1);
			}
			i_char++;
		}
		i_char = 0;
		i++;
	}
	return (0);
}