/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:32 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/16 19:52:19 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

// color :  echo "\x1b[38;2;255;0;0;5mSal\x1b[38;2;0;255;0;7mu\e[0mt"




void presocratiques(t_data *data)
{	
	int i = 0;
	t_philo *philo ;

	data->delta_t = get_time(data->delta_t); //  start compteur time memeroy time 
	
	while(data->nb_philo != i++)
	{
		philo = data->philos + i ;
		philo->index = i;
		philo->last_eat = 0;
		philo->round = 0 ;
		philo->data = data;
		
		assign_fork(philo , data->forks, i);
		
	}




}


int create_mutex(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data-> nb_philo);
	data->forks = mallo(sizeof(t_philo) * data-> nb_philo);
	int i = 0 ;
	while(i != data->nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		data->forks[i].fork_id = i; // eviter de le reinite;
		i++;
	}
	presocratiques( &data);
	//pthread_mutex_init(&data->time_eat, NULL);
	//pthread_nutex_init(&data->time_deth, NULL);
	//gestion d'erreur a gerer ; 
	return(0);
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
	//data->delta_t = -1 ;
	if(data->nb_philo <= 6 || data->time_deth <= 6 || data->time_eat <= 6 || data->time_slepp <= 6) // pas moins de 60 ms 
		return(1);
	if(argc == 6)
	{
		data->round = ft_atoi(argv[5]);
		if(data->round <= 0)
			return(1);
	}
	return(0);
	//data->deltat = get_time(data->nb_philo); //init (a)voir
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
	if( parsing( &data , argv , argc)) // parsing
		ft_erreur();
	if(create_mutex(&data));
		ft_erreur();
	
}
	error_exit();

	return(0);
}
