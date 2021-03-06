/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:35:31 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/10/11 18:27:34 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philosopher.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cp;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	cp = (char *)malloc(i + 1);
	if (!cp)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
