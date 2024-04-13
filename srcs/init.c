/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:17:38 by vharatyk          #+#    #+#             */
/*   Updated: 2024/04/13 16:46:52 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* asignation des fork gestion des death lock */
void	assign_fork(t_philo *philo, t_fork *forks, int i)
{
	int	nb;

	nb = philo->data->nb_philo;
	philo->right_fork = &forks[(i + 1) % nb];
	philo->left_fork = &forks[i];
	if (philo->id % 2 == 0)
	{
		philo->right_fork = &forks[i];
		philo->left_fork = &forks[(i + 1) % nb];
	}
}

void	philo_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (data->nb_philo > ++i)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		safe_mutex(&philo->philo_mutex, INIT);
		philo->conter = 0 ;
		philo->data = data;
		assign_fork(philo, data->forks, i);
	}
}

void	data_init(t_data *data)
{
	int	i;

	i = -1;
	data->end_simulation = false;
	data->threads_running = false;
	data->delta_t = 0 ;
	data->philos = ft_malloc(sizeof(t_philo) * data->nb_philo);
	data->forks = ft_malloc(sizeof(t_fork) * data->nb_philo);
	safe_mutex(&data->data_mutex, INIT);
	safe_mutex(&data->write, INIT);
	while (data->nb_philo > ++i)
	{
		safe_mutex(&data->forks[i].fork_mutex, INIT);
		data->forks->fork_id = i;
	}
	philo_init(data);
}

void	init_simulation(t_data *data)
{
	int	i;

	i = -1;
	if (data->round == 0)
		return ;
	else if (data->nb_philo == 1)
		safe_thread(&data->philos[0].thread_id, socrate,
			&data->philos[0], CREATE);
	else
	{
		while (data->nb_philo > ++i)
			safe_thread(&data->philos[i].thread_id, simulation,
				&data->philos[i], CREATE);
	}
	safe_thread(&data->reaper, ft_reaper, data, CREATE);
	data->delta_t = get_time();
	set_bool(&data->data_mutex, &data->all_redy, true);
	i = -1;
	while (data->nb_philo > ++i)
		safe_thread(&data->philos[i].thread_id, NULL, NULL, JOIN);
	set_bool(&data->data_mutex, &data->end_simulation, true);
	safe_thread(&data->reaper, NULL, NULL, JOIN);
}
