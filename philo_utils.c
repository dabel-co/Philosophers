/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:55:43 by dabel-co          #+#    #+#             */
/*   Updated: 2022/09/13 19:05:34 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

useconds_t	get_time(void)
{
	struct timeval	ti;

	gettimeofday(&ti, NULL);
	return (ti.tv_sec * 1000 + ti.tv_usec / 1000);
}

int	ft_usleep(useconds_t wait_time)
{
	useconds_t current_time;
	useconds_t desired_time;

	current_time = get_time();
	desired_time = current_time + wait_time;
	while (current_time < desired_time)
	{
		current_time = get_time();
		usleep(wait_time);
	}
	return (0);
}
int	ft_atoi(const char *str)
{
	int	i;
	int	atoi;
	int	n;

	i = 0;
	atoi = 0;
	n = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (atoi * n > 214748364 && str[i] - '0' > 7)
			return (-1);
		if (atoi * n < -214748364 && str[i] - '0' >= 8)
			return (0);
		atoi = atoi * 10 + (str[i] - '0');
		i++;
	}
	return (atoi * n);
}

