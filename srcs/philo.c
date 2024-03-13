/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:32 by vharatyk          #+#    #+#             */
/*   Updated: 2024/03/13 09:41:33 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


// color :  echo "\x1b[38;2;255;0;0;5mSal\x1b[38;2;0;255;0;7mu\e[0mt"
int check_is_run(t_data *data)
{
	pthread_mutex_lock(&data->dead);
	if(data->stop)
	{
		pthread_mutex_unlock(&data->dead);
		return(1);
	}
	pthread_mutex_unlock(&data->dead);
	return(0);
}

void the_end(t_data * data)
{

	int i = -1 ;
	while(!check_is_run(data))
		ft_usleep(1);
		
	while(++i < data->nb_philo)
		pthread_join(data->philos[i].t_id, NULL);
	pthread_mutex_destroy(&data->mutex);
	i = - 1;
	while(++i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->philos[i].fork_left);
	}
	
//free(data->philos);
}


int main (int argc , char **argv)
{
	t_data data ;

if(argc == 5 || argc == 6)
{
	if(ft_erreur("input", parsing( &data , argv , argc)))
		return(1);
	if(ft_erreur("mutex", init_data(&data , argc)))
	{
		//free(data.philos);
		return(1);
	}
	ft_erreur("simulation", simulation_of_life(&data));
	the_end(&data);
}
else
	ft_erreur("nb_arg" , 1 );

return(0);
}
