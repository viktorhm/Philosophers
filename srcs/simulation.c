/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:27:17 by vharatyk          #+#    #+#             */
/*   Updated: 2024/04/13 16:41:20 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sychronize_philos(t_philo *philo)
{
	if (philo->data->nb_philo % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_usleep(3);
	}
	else
	{
		if (philo->id % 2)
			thinking(philo, true);
	}
}

void	*socrate(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_eat, get_time());
	write_status(TAKE_FORK, philo);
	while (!simulation_end(philo->data))
		ft_usleep(philo->data->time_deth + 1);
	return (NULL);
}

void	eat(t_philo *philo)
{
	safe_mutex(&philo->left_fork->fork_mutex, LOCK);
	write_status(TAKE_FORK, philo);
	safe_mutex(&philo->right_fork->fork_mutex, LOCK);
	write_status(TAKE_FORK, philo);
	set_long(&philo->philo_mutex, &philo->last_eat, get_time());
	philo->conter++;
	write_status(EAT, philo);
	ft_usleep(philo->data->time_eat);
	if (philo->data->round > 0 && philo->conter == philo->data->round)
		set_bool(&philo->philo_mutex, &philo->full, true);
	safe_mutex(&philo->right_fork->fork_mutex, UNLOCK);
	safe_mutex(&philo->left_fork->fork_mutex, UNLOCK);
}

void	thinking(t_philo *philo, bool condition)
{
	long	tthink;

	if (condition == false)
		write_status(THINK, philo);
	if (philo->data->nb_philo % 2 == 0)
		return ;
	tthink = (philo->data->time_eat * 2) - philo->data->time_slepp;
	if (tthink < 0)
		tthink = 0 ;
	ft_usleep(tthink * 0.42);
}

void	*simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_eat, get_time());
	increase_long(&philo->data->data_mutex, &philo->data->threads_running);
	sychronize_philos(philo);
	while (!simulation_end(philo->data))
	{
		if (get_bool(&philo->philo_mutex, &philo->full))
			break ;
		eat(philo);
		write_status(SLEP, philo);
		ft_usleep(philo->data->time_slepp);
		thinking(philo, false);
	}
	return (NULL);
}
