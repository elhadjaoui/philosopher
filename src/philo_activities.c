/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:31:51 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/10/17 21:26:59 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

void	think(t_philo *philo)
{
	printf("%d %d is thinking\n", current_time(philo->start), philo->id);
}

void	take_fork1(t_philo *philo)
{
	pthread_mutex_lock(&philo[philo->id - 1].fork);
	printf("%d %d has taken a fork  (id = %d)\n", current_time(philo->start), philo->id, philo->id - 1);
}

void	take_fork2(t_philo *philo)
{
	pthread_mutex_lock(&philo[philo->id % philo->num_philo].fork);
	printf("%d %d has taken a fork (id = %d)\n", current_time(philo->start), philo->id, (philo->id)% philo->num_philo);

}
void	eat(t_philo *philo)
{
	philo->eating = 1;
	philo->last_ate = current_time(philo->start);
	// if (g_data.eat_count > 0)
	// 	ph->eat_count++;
	// busy();
	usleep(50000);
	printf("%d %d is eating\n", current_time(philo->start), philo->id);
	philo->eating = 0;
	pthread_mutex_unlock(&philo[philo->id % philo->num_philo].fork);
	pthread_mutex_unlock(&philo[philo->id - 1].fork);
}

void	to_bed(t_philo *philo)
{
	printf("%d %d is sleeping\n", current_time(philo->start), philo->id);
	philo->last_slept = current_time(philo->start);
	// busy();
}
