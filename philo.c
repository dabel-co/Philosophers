/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:43:45 by dabel-co          #+#    #+#             */
/*   Updated: 2022/09/06 18:35:39 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//philo number
//time to die
//time to eat
//time to sleep
//OPTIONAL : number of times philos need to eat for the sim to end, if blank, end with ded

#include "philo.h"

int check_valid_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	argc++;
	return (0);
}

t_philo_info *extract_information(char **argv)
{
	t_philo_info	*x;

	x = malloc(sizeof(t_philo_info));
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
int start_routine(t_philo_info *x)
{
	t_philo	philo[x->size];
	int		i;

	i = 0;
	while (i < x->size)
	{
		philo[i].id = i + 1;
		philo[i].info = x;
		i++;
	}
	i = 0;
	while (i < x->size)
	{
		printf("philo number = %d\n", philo[i].id);
		printf("die = %lu\n", philo[i].info->die);
		i++;
	}
	return (0);

}
int main(int argc, char **argv)
{
	t_philo_info	*x;
	if (check_valid_input(argc, argv))
		return (1);
	x = extract_information(argv);
	start_routine(x);
	return (0);
}
