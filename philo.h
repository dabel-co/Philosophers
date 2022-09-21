/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:55:55 by dabel-co          #+#    #+#             */
/*   Updated: 2022/09/21 13:01:14 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define RED "\033[0;31m"

typedef struct s_philo
{
	int					id;
	struct s_philo_info	*info;
	pthread_t			philo_th;
	pthread_mutex_t		fork;
	useconds_t			last_meal;
	int					meals;
	struct s_philo		*next;
}				t_philo;

typedef struct s_philo_info
{
	int			size;
	long		die;
	long		eat;
	long		sleep;
	int			repetitions;
	int			dead;
	useconds_t	init_time;
}				t_philo_info;

int			ft_atoi(const char *str);
int			launch_philos(t_philo *x, t_philo_info *info);
void		ft_usleep(useconds_t wait_time);
useconds_t	get_time(void);
int			check_meals(t_philo *x);
void		free_mem(t_philo *x);
#endif
