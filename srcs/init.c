/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:17:38 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/22 16:17:27 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosophers.h"

static void inti_philo(t_data *data)
{
	int i = 0 ;
	pthread_mutex_init(&data->mutex ,NULL);
	while(i < data->nb_philo)
	{
		pthread_mutex_lock(&data->mutex);
		if(i < data->nb_philo)
			pthread_create(&data->philos[i].philo_thread, NULL, routine, table);
		i++;
		}
}



void presocratiques(t_data *data)
{
	int	i = 0;

	while(data->nb_philo > i++)
	{
		data->philos[i].index = i;
		if(i == 0)
			data->philos[i].left= data->nb_philo -1 ;
		else
			data->philos[i].left = i - 1;
		data->philos[i].right = i ;
		i++;
	}
}

void set_fork(t_data *data)
{
	int i= 0 ;
	while(data->nb_philo < i)
	{
		pthread_mutex_init(&data->forks,NULL);
		data->forks[i].free = 1;
		data->forks[i].pos = i;
		i++;
	}


}

int create_mutex(t_data *data)
{
	int i = 0 ;
	if(!(data->philos = malloc(sizeof(t_philo) * data-> nb_philo)))
		return(1);
	if(!(data->forks = malloc(sizeof(t_fork)* data->nb_philo)));

	pthread_mutex_init(&data->mutex, NULL);

	set_fork(data);
	set_philo(data);
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