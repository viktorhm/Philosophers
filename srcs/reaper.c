/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:13:48 by vharatyk          #+#    #+#             */
/*   Updated: 2024/04/12 16:52:15 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static bool philo_dead(t_philo *philo)
{
	long	last_eat;
	long	delta_t_dead;

	if(get_bool(&philo->philo_mutex , &philo->full))
		return(false);
	last_eat = get_time() - get_long(&philo->philo_mutex , &philo->last_eat);
	delta_t_dead = philo->data->time_deth;

	if(last_eat > delta_t_dead)
		return(true);
	return(false);


}


void	*ft_reaper(void *tmp_data)
{
	int		i;
	t_data	*data;
	data = (t_data *)tmp_data;


	if(data->nb_philo > 1)
		while(!philo_runnig(&data->data_mutex, &data->threads_running , data->nb_philo ))
			;

	while(!simulation_end(data))
	{
		i = -1;
		while(data->nb_philo > ++i && !simulation_end(data))
		{
			if(philo_dead(data->philos + i)&& !simulation_end(data))
			{
				set_bool(&data->data_mutex , &data->end_simulation , true);
				write_status( DEAD,data->philos + i );
			}
		}
	}
	return(NULL);
}