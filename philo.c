/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:55:27 by dabel-co          #+#    #+#             */
/*   Updated: 2022/09/08 18:36:32 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_routine(t_philo *x)
{
	printf("hello! This is philo number %d\n", x->id);
}

void *philo_monitor(t_philo *x)
{

}

int launch_philos(t_philo *x, t_philo_info *info)
{
	int i;

	i = 0;
	while (i < info->size)
	{
		pthread_create(&x->philo_th, NULL, (void *(*)(void *)) &philo_routine, x);
		usleep(500);
		x = x->next;
		i++;
	}
}
