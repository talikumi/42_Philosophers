/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsociety <fsociety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:51:30 by fsociety          #+#    #+#             */
/*   Updated: 2022/01/30 16:25:57 by fsociety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long int	ft_current(void)
{
	struct timeval	sec;

	gettimeofday(&sec, NULL);
	return (sec.tv_sec * 1000 + sec.tv_usec / 1000);
}

void	ft_usleep(int length)
{
	long int	time;

	time = ft_current();
	while (ft_current() < time + length)
		usleep(length);
}

void	ft_print(t_rules *rules, int phil, char *str)
{
	long int	nb;

	nb = ft_current() - rules->start;
	if (!rules->dead)
		printf("%ld           philosopher %d: %s\n", nb, phil, str);
}
