/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:15:52 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/10/11 20:18:08 by mel-hadj         ###   ########.fr       */
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
	return (0);
}