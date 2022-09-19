/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:55:43 by dabel-co          #+#    #+#             */
/*   Updated: 2022/09/19 17:30:48 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mem(t_philo *x)
{
	//do thingy		
}

int	check_meals(t_philo *x)
{
	int	i;

	i = 0;
	while (1)
	{
		if (x->meals == x->info->repetitions)
			i++;
		else
			return (0);
		if (i == x->info->size)
		{
			x->info->repetitions = -1;
			return (1);
		}
		x = x->next;
	}
}

useconds_t	get_time(void)
{
	struct timeval	ti;

	gettimeofday(&ti, NULL);
	return (ti.tv_sec * 1000 + ti.tv_usec / 1000);
}

void	ft_usleep(useconds_t wait_time)
{
	useconds_t	current_time;
	useconds_t	desired_time;

	current_time = get_time();
	desired_time = current_time;
	while (desired_time - current_time < wait_time)
	{
		usleep(wait_time);
		desired_time = get_time();
	}
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
			return (-1);
		atoi = atoi * 10 + (str[i] - '0');
		i++;
	}
	return (atoi * n);
}
