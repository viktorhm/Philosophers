/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:17:38 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/27 03:31:28 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosophers.h"

int init_data(t_data *data)
{
	if(!(data->philos = malloc(sizeof(t_philo) * data-> nb_philo)))
		return(1);

	data->delta_t = get_time();
	data->round = 0;
	data->nb_p_fninsh = 0 ;
	data->stop= 0 ;


	pthread_mutex_init(&data->mutex ,NULL);
	pthread_mutex_init(&data->dead, NULL);
	pthread_mutex_init(&data->eat, NULL);
	pthread_mutex_init(&data->finish, NULL);

	presocratiques(data);

	return(0);
}


int presocratiques(t_data *data)
{
	int	i = -1;
	while(data->nb_philo > ++i)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_eat = data->delta_t;
		data->philos[i].nb_eat = 0;
		data->philos[i].finish = 0;
		set_fork(data , i);
	}
	return(0);
}

int set_fork(t_data *data ,int i)
{
	data->philos[i].fork_right = NULL;
	pthread_mutex_init(&data->philos[i].fork_left, NULL);

	if(data->nb_philo == 1)
		return(1);
	if(i == data->nb_philo - 1)
		data->philos[i].fork_right = &data->philos[0].fork_left; // cercle fork
	else
		data->philos[i].fork_right = &data->philos[i + 1].fork_left;
	return(0);
}


long int get_time(void)
{
	long int delta = 0 ;

	struct timeval	time;
	gettimeofday(&time,NULL);

	delta = time.tv_sec * 1000 + time.tv_usec / 1000 ;

	return(delta);
}