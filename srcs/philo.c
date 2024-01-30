/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:32 by vharatyk          #+#    #+#             */
/*   Updated: 2024/01/30 16:21:49 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philosophers.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <pthread.h>


// static void	*routine(void *arg)
// {
// 	int i = 0 ;
// 	int *num ;

// 	num = (int *)arg;
// 	while(i < 10000)
// 	{
// 			(*num)++;
// 			i++;
// 	}
// 	return (NULL);
// }

// void example()
// {
// 	pthread_t	t1;
// 	pthread_t	t2;
// 	int *num ;

// 	num = malloc(sizeof(int));

// 	*num = 0 ;
// 	if(pthread_create(&t1, NULL ,routine, num))
// 		exit(1);
// 	if(pthread_create(&t2, NULL ,routine, num))
// 		exit(1);

// 	if(pthread_join(t1, NULL))
// 		exit(1);
// 	if(pthread_join(t2, NULL))
// 		exit(1);
// 	printf("NUM: %d", *num);
// 	}

int is_char_neg (char *str)
{
	int i = 0 ;
	while(str[i])
	{
		if(str[i]>= '0' && str[i]<= '9')
			i++;
		else
			return(0);
	}
	return(1);
}


int main (int argc , char **argv)
{
int nb_philo = 0 ;
int time_deth = 0 ;
int time_eat = 0 ;
int time_slepp = 0 ;


if(argc == 4 || argc == 5)
{
	int j = 0 ;
	while(argc == j)
	{
		if(is_char_neg(argv[j]))
			return(ft_erreur());
		j++;
	}
	nb_philo = ft_atoi() ;
	time_deth = ft_atoi() ;
	time_eat = ft_atoi() ;
	time_slepp = ft_atoi();





}


	return(0);
}
