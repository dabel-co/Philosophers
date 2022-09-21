/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:32:52 by dabel-co          #+#    #+#             */
/*   Updated: 2022/09/21 13:01:57 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_valid_input(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	while (argc > 1)
	{
		i = 0;
		argc--;
		while (argv[argc][i] != '\0')
		{
			if ((argv[argc][i] >= '0' && argv[argc][i] <= '9')
					&& ft_atoi(argv[1]) > 0)
				i++;
			else
			{
				printf("invalid input\n");
				return (1);
			}
		}
	}
	return (0);
}

t_philo_info	*extract_information(char **argv)
{
	t_philo_info	*x;

	x = malloc(sizeof(t_philo_info));
	x->dead = 0;
	x->size = ft_atoi(argv[1]);
	x->die = ft_atoi(argv[2]);
	x->eat = ft_atoi(argv[3]);
	x->sleep = ft_atoi(argv[4]);
	if (argv[5])
		x->repetitions = ft_atoi(argv[5]);
	else
		x->repetitions = 0;
	return (x);
}

int	start_routine(t_philo_info *x)
{
	t_philo	*philo;
	int		i;
	t_philo	*aux;

	i = 0;
	philo = malloc(sizeof(struct s_philo));
	aux = philo;
	while (i < x->size)
	{
		philo->id = i + 1;
		philo->meals = 0;
		philo->info = malloc(sizeof(struct s_philo_info));
		philo->info = x;
		philo->info->dead = 0;
		if (i + 1 != x->size)
		{
			philo->next = malloc(sizeof(struct s_philo));
			philo = philo->next;
		}
		i++;
	}
	philo->next = aux;
	launch_philos(philo->next, x);
	free_mem(philo);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo_info	*x;

	if (check_valid_input(argc, argv))
		return (1);
	x = extract_information(argv);
	start_routine(x);
	return (0);
}
