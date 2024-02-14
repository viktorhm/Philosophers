/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:32 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/13 22:35:24 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

// color :  echo "\x1b[38;2;255;0;0;5mSal\x1b[38;2;0;255;0;7mu\e[0mt"


int init(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	data->forks = malloc(sizeof(t_fork)* data->nb_philo);


}

int parsing(t_data *data , char **argv , int argc)
{

int j = 1 ;
	while(argc != j)
	{
		if(is_char_neg(argv[j]))
			return(ft_erreur());
		j++;
	}
	data->nb_philo = ft_atoi(argv[1]) ;
	data->time_deth = ft_atoi(argv[2]) ;
	data->time_eat = ft_atoi(argv[3]) ;
	data->time_slepp = ft_atoi(argv[4]);
	data->deltat = 0 ;
	if(argc == 6)
	{
		data->round = ft_atoi(argv[5]);
	}

	//data->deltat = get_time(data->nb_philo);


}

long int get_time(long init_time)
{
	long int seconde = 0 ;
	long int deltatime = 0 ;
	struct timeval	time;

	gettimeofday(&time,NULL);

	seconde = time.tv_sec * 1000 + time.tv_usec / 1000 ;
	deltatime = seconde - init_time ;


	return(deltatime);
}

int ft_erreur(void)
{
write(1,"erreur",6);

return(1);
}

int is_char_neg (char *str)
{
	int i = 0 ;
	while(str[i])
	{
		if(str[i]>= '0' && str[i]<= '9')
			i++;
		else
			return(1);
	}
	return(0);
}


int main (int argc , char **argv)
{
	t_data data ;

if(argc == 5 || argc == 6)
{
	parsing( &data , argv , argc); // parsing

	data.deltat = get_time(data.deltat);
	printf("%ld ",get_time(data.deltat)); 
	sleep(1);
	printf("%ld ",get_time(data.deltat));

}
	error_exit();

	return(0);
}
