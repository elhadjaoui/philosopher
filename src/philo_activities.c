/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:31:51 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/10/19 19:11:47 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void	think(t_philo *philo)
{
	// pthread_mutex_lock(&philo->print);
	printf("%d %d is thinking\n", current_time(philo->start), philo->id);
	// pthread_mutex_unlock(&philo[philo->id - 1].print);
}

void	take_fork1(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	// pthread_mutex_lock(&philo->print);
	printf("%d %d has taken a fork1 add= %p\n", current_time(philo->start), philo->id, &philo->fork);
	// pthread_mutex_unlock(&philo->print);
}

void	take_fork2(t_philo *philo)
{
	t_philo *tmp;

	if (philo->id == philo->num_philo)
		tmp  = philo - (philo->num_philo -1) ;
	else 
		tmp = philo;
	pthread_mutex_lock(&tmp->fork);
	// pthread_mutex_lock(&philo->print);
	printf("%d %d has taken a fork2 add = %p\n", current_time(philo->start), philo->id, &tmp->fork);
	// pthread_mutex_unlock(&philo->print);
}
void	eat(t_philo *philo)
{
	t_philo *tmp;

	if (philo->id == philo->num_philo)
		tmp  = philo - (philo->num_philo -1) ;
	else 
		tmp = philo;

	philo->eating = 1;
	philo->last_ate = current_time(philo->start);
	// if (g_data.eat_count > 0)
	// 	ph->eat_count++;
	// pthread_mutex_lock(&philo->print);
	printf("%d %d is eating\n", current_time(philo->start), philo->id);
	busy();
	// pthread_mutex_unlock(&philo->print);
	philo->eating = 0;
	pthread_mutex_unlock(&tmp->fork);
	pthread_mutex_unlock(&tmp->fork);
}

void	to_bed(t_philo *philo)
{
	// pthread_mutex_lock(&philo->print);
	printf("%d %d is sleeping\n", current_time(philo->start), philo->id);
	// pthread_mutex_unlock(&philo->print);
	busy();
	philo->last_slept = current_time(philo->start);
}
