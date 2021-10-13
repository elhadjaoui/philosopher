/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:20:41 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/10/13 21:08:03 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void *myThreadFun(void *ph)
{ 
	t_philo *philo;
	
	philo = (t_philo *) ph;
    printf("ID = %d\n",philo->id);
	return NULL;
}
void	initialize_philo(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	while (i < data->num_philo)
	{
		philo[i].id = i + 1;
		// philo[i].last_ate = current_time();
		philo[i].last_slept = 0;
		philo[i].eating = 0;
		philo[i].eat_count = 0;
		i++;
	}
}

int launch_threads(pthread_t *thread, t_philo *philo, t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&thread[i], NULL, &myThreadFun, &philo[i]) != 0)
			return (0);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < data->num_philo)
	{
		if (pthread_create(&thread[i], NULL, myThreadFun, &philo[i]) != 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	simulation(t_data *data)
{
	pthread_t	*philo_thread;
	t_philo		*philo;

	philo_thread = malloc(data->num_philo * sizeof(pthread_t));	
	philo = malloc(data->num_philo * sizeof(t_philo));
	initialize_philo(data, philo);
	if (!launch_threads(philo_thread, philo, data))
		return (0);
	return (1);
}

t_data	*initialize_data(char **av)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->num_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	return (data);
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (argument_checker(av))
		{
			printf("Error\nPlease enter a valid arguments");
			return(1);
		}
		simulation(initialize_data(av));
	}
	else
	{
		printf("Error\nMore or Few arguments");
		return(1);
	}
	return 0;
}