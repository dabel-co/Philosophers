/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:55:55 by dabel-co          #+#    #+#             */
/*   Updated: 2022/09/08 17:55:50 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_philo
{
	int id;
	struct s_philo_info	*info;
	pthread_t			philo_th;
	pthread_mutex_t		fork;
	struct s_philo		*next;
}				t_philo;
typedef struct s_philo_info
{
	int size;
	long die;
	long eat;
	long sleep;
	int repetitions;
}				t_philo_info;

int ft_atoi (const char *str);
int launch_philos(t_philo *x, t_philo_info *info);
#endif
