/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:43:45 by dabel-co          #+#    #+#             */
/*   Updated: 2022/08/25 16:47:05 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//philo number
//time to die
//time to eat
//time to sleep
//OPTIONAL : number of times philos need to eat for the sim to end, if blank, end with ded

#include "philo.h"

void print_parameters(char **argv) //debug function
{
	printf("Number of Philosophers = %s\n", argv[1]);
	printf("Time to die = %s\n", argv[2]);
	printf("Time to eat = %s\n", argv[3]);
	printf("Time to sleep = %s\n", argv[4]);
	printf("Number of meals required  = %s\n", argv[5]);
}
int main(int argc, char **argv)
{
	print_parameters(argv);
	return (0);	
}
