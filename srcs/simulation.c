/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:27:17 by vharatyk          #+#    #+#             */
/*   Updated: 2024/04/11 22:38:13 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*socrate(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_threads(philo->data);
	set_long(&philo->philo_mutex , &philo->last_eat, get_time());
	write_status(TAKE_FORK, philo);
	while(!simulation_end(philo->data))
		{
		printf("test\n");
		ft_usleep(philo->data->time_deth+1);
		}
	return(NULL);
}


static void eat(t_philo *philo)
{
	safe_mutex(&philo->left_fork->fork ,LOCK);
	write_status(TAKE_FORK , philo);
	safe_mutex(&philo->right_fork->fork ,LOCK);
	write_status(TAKE_FORK , philo);

	set_long(&philo->philo_mutex,&philo->last_eat , get_time());
	philo->conter++;
	write_status(EAT , philo);
	ft_usleep(philo->data->time_eat);
	if(philo->data->round > 0 && philo->conter == philo->data->round)
		set_bool(&philo->philo_mutex , &philo->full , true);

	safe_mutex(&philo->right_fork->fork ,UNLOCK);
	safe_mutex(&philo->left_fork->fork ,UNLOCK);
}

static void thinking(t_philo *philo, bool condition)
{
	long	tthink;


	if(condition == false)
		write_status(THINK, philo);
	if(philo->data->nb_philo % 2 == 0)
		return ;
	tthink = (philo->data->time_eat * 2 ) - philo->data->time_slepp;
	if(tthink < 0)
		tthink = 0 ;
	ft_usleep(tthink * 0.50);

}

static void *simulation(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	wait_threads(philo->data);

	set_long(&philo->philo_mutex, &philo->last_eat, get_time());

	increase_long(&philo->data->data_mutex , &philo->data->threads_running);

	while(!simulation_end(philo->data))
		{
			if(get_bool(&philo->philo_mutex, &philo->full))
				break;
			eat(philo);
			write_status(SLEP, philo);
			ft_usleep(philo->data->time_slepp);
			thinking(philo, false);
		}
	return(NULL);

}

void init_simulation(t_data *data)
{
	int i ;

	i = -1;
	if(data->round == 0)
		return ;
	else if(data->nb_philo == 1)
		safe_thread(&data->philos[0].thread_id, socrate , &data->philos[0], CREATE );
	else
	{
		while(data->nb_philo > ++i)
			safe_thread(&data->philos[i].thread_id, simulation , &data->philos[i], CREATE );
	}
	safe_thread(&data->reaper, ft_reaper , data , CREATE);
	data->delta_t = get_time();
	set_bool(&data->data_mutex , &data->all_redy , true); // start simulation

	i = -1;
	while(data->nb_philo > ++i)
		safe_thread(&data->philos[i].thread_id, NULL, NULL, JOIN );
	set_bool(&data->data_mutex, &data->end_simulation, true);
	safe_thread(&data->reaper, NULL , NULL , JOIN);

}