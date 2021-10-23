/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:15:52 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/10/23 21:28:28 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	argument_checker(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				return (1);
	}
	if (ft_atoi(av[1]) == 0)
		return (1);
	return (0);
}

int	current_time(struct timeval start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000)
		- (start.tv_sec * 1000 + start.tv_usec / 1000));
}
void	busy(int time_stop, int last, struct timeval start_time)
{

	usleep((time_stop - 20) * 1000);
	while (current_time(start_time) - last < time_stop)
		;
}