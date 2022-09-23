/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:55:27 by dabel-co          #+#    #+#             */
/*   Updated: 2022/09/19 17:30:50 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_philo *x, int i)
{
	int	time;

	time = get_time() - x->info->init_time;
	if (x->info->dead != 0 || x->info->repetitions == -1)
		return (1);
	if (i == 0)
		printf("%s[%d] %sPhilo %d has taken a fork\n", CYAN, time, WHITE, x->id);
	if (i == 1)
		printf("%s[%d] %sPhilo %d is thinking\n", CYAN, time, WHITE, x->id);
	if (i == 2)
		printf("%s[%d] %sPhilo %d is sleeping\n", CYAN, time, WHITE, x->id);
	if (i == 3)
	{	
		printf("%s[%d] %sPhilo %d has taken a fork\n", CYAN, time, WHITE, x->id);
		printf("\033[0;36m[%d] \33[0;37mPhilo %d is eating\n",
			get_time() - x->info->init_time, x->id);
	}
	return (0);
}

int	philo_sequence(t_philo *x)
{
	pthread_mutex_lock(&x->fork);
	if (print_status(x, 0) != 0)
		return (1);
	pthread_mutex_lock(&x->next->fork);
	if (print_status(x, 3) != 0)
		return (1);
	x->last_meal = get_time() - x->info->init_time;
	ft_usleep(x->info->eat);
	x->meals++;
	pthread_mutex_unlock(&x->fork);
	pthread_mutex_unlock(&x->next->fork);
	if (print_status(x, 2) != 0)
		return (1);
	ft_usleep(x->info->sleep);
	if (print_status(x, 1) != 0)
		return (1);
	return (0);
}

void	*p_routine(t_philo *x)
{
	pthread_mutex_init(&x->fork, NULL);
	if (x->id % 2 == 0)
		usleep(100);
	x->meals = 0;
	x->last_meal = get_time() - x->info->init_time;
	while (1)
	{
		philo_sequence(x);
		if (x->info->dead != 0 || x->info->repetitions == -1)
			break ;
	}
	return (0);
}

int	philo_monitor(t_philo *x)
{
	useconds_t	actual_time;

	while (1)
	{
		actual_time = get_time() - x->info->init_time;
		if (actual_time >= x->last_meal + x->info->die)
		{
			x->info->dead = x->id;
			printf("%s[%d] %sPhilo %d is dead\n", CYAN, actual_time, RED, x->id);
			return (x->id);
		}
		if (x->info->repetitions != 0 && check_meals(x))
		{
			usleep(20);
			printf("All philos have eaten\n");
			return (0);
		}
		x = x->next;
	}
	return (0);
}

int	launch_philos(t_philo *x, t_philo_info *info)
{
	int	i;

	i = 0;
	x->info->init_time = get_time();
	while (i < info->size)
	{
		pthread_create(&x->philo_th, NULL, (void *(*)(void *)) & p_routine, x);
		x = x->next;
		i++;
	}
	philo_monitor(x);
	while (i < info->size - 1)
	{
		pthread_join(x->philo_th, NULL);
		x = x->next;
		i++;
	}
	return (0);
}
