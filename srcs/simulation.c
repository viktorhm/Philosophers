/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:27:17 by vharatyk          #+#    #+#             */
/*   Updated: 2024/04/08 03:16:43 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


static void eat(t_philo *philo)
{
	safe_mutex(&philo->left_fork->fork ,LOCK);
	write_status(TAKE_FORK , philo);
	safe_mutex(&philo->right_fork->fork ,LOCK);
	write_status(TAKE_FORK , philo);

	set_long(&philo->philo_mutex,&philo->last_eat , get_time());
	philo->conter++;
	write_status(EAT , philo);
	if(philo->data->round > 0 && philo->conter == philo->data->round)
		set_bool(&philo->philo_mutex , &philo->full , true);

	safe_mutex(&philo->right_fork->fork ,UNLOCK);
	safe_mutex(&philo->left_fork->fork ,UNLOCK);
}

static void thinking(t_philo *philo)
{
	write_status(THINK, philo);

}

static void *simulation(void *data)
{
	t_philo *philo ;

	philo = (t_philo *)data;

	wait_threads(philo->data);




	while(!simulation_end(philo->data))
		{
			if(philo->full)
				break;
			eat(philo);
			//thinking(philo);

		}



}

void init_simulation(t_data *data)
{
	int i ;

	i = -1;
	if(data->round == 0)
		return ;
	else if(data->nb_philo == 1)
		return ;//safe_thread(&data->philos[0].thread_id, lone_)
	else
	{
		while(data->nb_philo > ++i)
			safe_thread(&data->philos[i].thread_id, simulation , &data->philos[i], CREATE );
	}

	safe_thread(&data->reaper, ft_reaper , data , CREATE);

	set_bool(&data->data_mutex, &data->all_redy, true);
	data->delta_t = get_time();
	set_bool(&data->data_mutex , &data->all_redy , true);

	i = -1;
	while(data->nb_philo > ++i)
		safe_thread(&data->philos[i].thread_id, NULL, NULL, JOIN );


}