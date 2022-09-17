/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:55:27 by dabel-co          #+#    #+#             */
/*   Updated: 2022/09/17 17:06:48 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int print_status(t_philo *x, int i) //make this not suck
{
	if (x->info->dead != 0)
		return (1);
	if ( i == 0)
		printf("Philo %d has taken a fork\n", x->id);
	if ( i == 1)
		printf("Philo %d is eating\n", x->id);
	if ( i == 2)
		printf("Philo %d is thinking\n", x->id);
	if ( i == 3)
		printf("Philo %d is sleeping\n",x->id);
	if ( i == 4)
		printf("Philo %d is dead\n", x->id);
	if (i == 5)
	{	
		printf("Philo %d has taken a fork\n", x->id);
		printf("Philo %d is eating\n", x->id);
	}
	return (0);
}
int philo_sequence(t_philo *x)
{
	pthread_mutex_lock(&x->fork); 
	if (print_status(x, 0) != 0) 
		return 1;
	pthread_mutex_lock(&x->next->fork); 
	if (print_status(x, 5) != 0)
		return 1;
	x->last_meal=get_time();
	ft_usleep(x->info->eat, x);
	x->meals++;
	pthread_mutex_unlock(&x->fork);
	pthread_mutex_unlock(&x->next->fork);
	if (print_status(x, 3) != 0)
		return 1;
	ft_usleep(x->info->sleep, x);
	if (print_status(x, 2) != 0) 
		return 1;	
}

void *p_routine(t_philo *x)
{
//	printf("hello! This is philo number %d\n", x->id);
	pthread_mutex_init(&x->fork, NULL);
	if (x->id % 2 == 0)
		usleep(100);
	x->last_meal = get_time();
	while (1)
	{
		philo_sequence(x);
		if (x->info->dead != 0)
			break;
	}
}

int philo_monitor(t_philo *x, t_philo_info *info)
{
	useconds_t aux;
	while (1)
	{
		aux = get_time();
		//printf("%d\n", x->last_meal);
		if (x->last_meal + x->info->die > aux)
		{
			printf("SOMEONE DIED %d\n", x->id);
			x->info->dead = x->id;
			return(0);
		}
		x = x->next;
	}
	//printf("someone died\n");
	return (0);
}

int launch_philos(t_philo *x, t_philo_info *info)
{
	int i;

	i = 0;
	x->info->init_time = get_time();
	while (i < info->size)
	{
		pthread_create(&x->philo_th, NULL, (void *(*)(void *)) & p_routine, x);
		x = x->next;
		i++;
	}
	philo_monitor(x, info);
	i = 0;
	/*while (i < info->size - 1)
	{
		pthread_join(x->philo_th, NULL);
		x = x->next;
		i++;
	}  */
	return (0);
	//free and clean exit
}
