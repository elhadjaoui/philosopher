/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:31:51 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/10/23 21:44:36 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void	think(t_philo *philo)
{
	pthread_mutex_lock((philo->print));
	printf("%d %d is thinking\n", current_time(philo->start), philo->id);
	pthread_mutex_unlock((philo->print));
}

void	take_fork1(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork[philo->id - 1]));
	pthread_mutex_lock((philo->print));
	printf("%d %d has taken a fork1\n", current_time(philo->start), philo->id);
	pthread_mutex_unlock((philo->print));
}

void	take_fork2(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork[philo->id % philo->num_philo]));
	pthread_mutex_lock((philo->print));
	printf("%d %d has taken a fork2\n", current_time(philo->start), philo->id);
	pthread_mutex_unlock((philo->print));
}

void	eat(t_philo *philo)
{
	philo->eating = 1;
	philo->last_ate = current_time(philo->start);
	pthread_mutex_lock((philo->print));
	printf("%d %d is eating\n", current_time(philo->start), philo->id);
	pthread_mutex_unlock((philo->print));
	busy(philo->time_to_eat, philo->last_ate, philo->start);
	philo->eating = 0;
	if (philo->data_eat_count > 0)
		philo->eat_count++;
	pthread_mutex_unlock(&(philo->fork[philo->id - 1]));
	pthread_mutex_unlock(&(philo->fork[philo->id % philo->num_philo]));
}

void	to_bed(t_philo *philo)
{
	pthread_mutex_lock((philo->print));
	printf("%d %d is sleeping\n", current_time(philo->start), philo->id);
	pthread_mutex_unlock((philo->print));
	philo->last_slept = current_time(philo->start);
	busy(philo->time_to_sleep, philo->last_slept, philo->start);
}

void	died(t_philo philo)
{
	pthread_mutex_lock(philo.print);
	printf("%d %d died\n", current_time(philo.start), philo.id);
}
