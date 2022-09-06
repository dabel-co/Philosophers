/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:49:03 by dabel-co          #+#    #+#             */
/*   Updated: 2022/09/06 18:35:43 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
typedef struct s_philo
{
	int id;

	struct s_philo_info *info;
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
#endif
