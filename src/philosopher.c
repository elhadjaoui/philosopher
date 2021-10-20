/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:20:41 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/10/20 21:18:38 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void *myThreadFun(void *ph)
{
	t_philo *philo;
	philo = (t_philo *)ph;
	while (1)
	{
		take_fork1(philo);
		take_fork2(philo);
		eat(philo);
		to_bed(philo);
		think(philo);
	}
	printf("dfad\n");
	return NULL;
}

int initialize_philo(t_data *data, t_philo *philo)
{
	int i;
	i = 0;
	
	while (i < data->num_philo)
	{
		philo[i].id = i + 1;
		// philo[i].last_ate = current_time(data->start);
		philo[i].last_slept = 0;
		philo[i].eating = 0;
		philo[i].eat_count = 0;
		philo[i].num_philo = data->num_philo;
		philo[i].start = data->start;
		philo[i].fork = data->forks;
		i++;
	}
	return (1);
}

int launch_threads(pthread_t *thread, t_philo *philo, t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&(thread[i]), NULL, &myThreadFun, &(philo[i])) != 0)
			return (0);
		i++;
		usleep(100); 
	}
	return(1);
}

int monitor(t_data *data, t_philo *philo)
{
	int	eat;
	int	i;

	while (1)
	{
		eat = 0;
		i = -1;
		while (++i < data->num_philo)
		{
			if (philo[i].eat_count >= g_data.eat_count)
				eat++;
			if (eat == g_data.num_philo && g_data.eat_count > 0)
			{
				pthread_mutex_lock(&g_print);
				return (2);
			}
			if (current_time() - philo[i].last_ate > g_data.to_die
				&& philo[i].eating == 0)
			{
				died();
				return (1);
			}
		}
	}
}
int simulation(t_data *data)
{
	pthread_t *philo_thread;
	t_philo *philo;
	int i;

	i = 0;
	philo_thread = malloc(data->num_philo * sizeof(pthread_t));
	philo = malloc(data->num_philo * sizeof(t_philo));
	initialize_philo(data, philo);
	if (!launch_threads(philo_thread, philo, data))
		return (0);
	if (!monitor(data, philo))
		return(0);
	return (1);
}
void optional_argument(int ac, t_data *data)
{
	data->eat_count = 0;
	if (ac == 6)
	{
		data->eat_count = ft_atoi(av[5]);
		if (data->eat_count <= 0)
			data->eat_count = 0;
	}
}
t_data *initialize_data(char **av, int ac)
{
	int i;
	t_data *data;

	i = 0;
	data = malloc(sizeof(t_data));
	data->num_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	gettimeofday(&(data->start), NULL);
	optional_argument()
	data->forks = malloc(data->num_philo * sizeof(pthread_mutex_t));
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
		{
			printf("\n mutex init has failed\n");
			return (0);
		}
		i++;
	}
	return (data);
}

int main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (argument_checker(av))
		{
			printf("Error\nPlease enter a valid arguments");
			return (1);
		}
		if (!simulation(initialize_data(av, ac)))
			return (1);
	}
	else
	{
		printf("Error\nMore or Few arguments");
		return (1);
	}
	while (1)
	{
	
	}
	
	return 0;
}