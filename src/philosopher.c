/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:20:41 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/10/11 20:49:20 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"


int simulation(t_data *data)
{
	return (1);
}

t_data	initialize_data(char **av)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->num_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
}

int	main(int ac, char **av)
{
	t_data *data;

	data = malloc(sizeof(t_data ));
	if (ac == 5 || ac == 6)
	{
		if (argument_checker(av))
		{
			printf("Error\nPlease enter a valid arguments");
			return(1);
		}
		initialize_data(av);
		simulation(data);
	}
	else
	{
		printf("Error\nMore or Few arguments");
		return(1);
	}
	return 0;
}