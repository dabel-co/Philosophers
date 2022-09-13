/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:55:27 by dabel-co          #+#    #+#             */
/*   Updated: 2022/09/13 19:05:32 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_sequence(t_philo *x)
{
	pthread_mutex_lock(&x->fork);
	printf("Philo %d has taken a fork\n", x->id);
	pthread_mutex_lock(&x->next->fork);
	printf("Philo %d is eating\n", x->id);
	//reset time
	ft_usleep(x->info->eat);
	pthread_mutex_unlock(&x->fork);
	pthread_mutex_unlock(&x->next->fork);
	//sleep
	
}

void *philo_routine(t_philo *x)
{
//	printf("hello! This is philo number %d\n", x->id);
	pthread_mutex_init(&x->fork, NULL);
	//if (x->id % 2 == 0)
	//	usleep(100);
	while (1)
	{
		philo_sequence(x);
	}
}

void *philo_monitor(t_philo *x)
{
	while (1)
	{
		if (x->last_meal >= x->info->die)
		{
			x->info->dead = x->id;
			break;
		}
		x = x->next;
	}
	//printf("someone died\n");
}

int launch_philos(t_philo *x, t_philo_info *info)
{
	int i;

	i = 0;
	//x->info->time = getimeofday
	//philo_monitor(x);
	while (i < info->size)
	{
		pthread_create(&x->philo_th, NULL, (void *(*)(void *)) &philo_routine, x);
		//sleep(1);
		x = x->next;
		i++;
	}
	sleep(10);
	i = 0;
	while (i < info->size)
	{
		pthread_join(&x->philo_th, NULL);
		x = x->next;
		i++;
	}
}
