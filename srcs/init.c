/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:17:38 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/22 11:35:14 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosophers.h"


void presocratiques(t_data *data)
{
	int i = 0;

	data->delta_t = 0;
	data->delta_t = get_time(data->delta_t); //  start compteur time memeroy time

	while(data->nb_philo > i++)
	{
		data->philos[i].index = i;
		data->philos[i].is_eating = 0 ;
		data->philos[i].last_eat = 0;
		data->philos[i].round = 0 ;
		data->philos[i].data = data;
		pthread_mutex_init(&data->philos[i].mutex , NULL);
		pthread_mutex_init(&data->philos[i].eat, NULL);
		pthread_mutex_lock(&data->philos[i].eat);
		pthread_mutex_init(&data->forks[i],NULL);
	i++;
	}
}


int create_mutex(t_data *data)
{
	int i = 0 ;
	if(!(data->philos = malloc(sizeof(t_philo) * data-> nb_philo)))
		return(1);

	pthread_mutex_init(&data->info, NULL);
	pthread_mutex_init(&data->seneque, NULL);
	pthread_mutex_lock(&data->seneque);

	presocratiques(data);

	return(0);
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