/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:27:17 by vharatyk          #+#    #+#             */
/*   Updated: 2024/03/13 15:23:30 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex);
	print_status("\x1b[38;2;100;150;150;1m is sleeping\e[0m \n", philo);
	pthread_mutex_unlock(&philo->data->mutex);
	ft_usleep(philo->data->time_slepp);
	pthread_mutex_lock(&philo->data->mutex);
	print_status("\x1b[38;2;255;255;0;1m is thinking\e[0m \n", philo);
	pthread_mutex_unlock(&philo->data->mutex);
}

void	activity(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_left);
	pthread_mutex_lock(&philo->data->mutex);
	print_status("\x1b[38;2;100;100;100;1m has taken a fork\e[0m \n", philo);
	pthread_mutex_unlock(&philo->data->mutex);
	if (!philo->fork_right)
	{
		ft_usleep(philo->data->time_deth * 2);
		return ;
	}
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(&philo->data->mutex);
	print_status("\x1b[38;2;100;100;100;1m has taken a fork\e[0m \n", philo);
	pthread_mutex_unlock(&philo->data->mutex);
	pthread_mutex_lock(&philo->data->mutex);
	print_status("\x1b[38;2;0;255;0;1m is eating\e[0m\n", philo);
	pthread_mutex_lock(&philo->data->eat);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->data->eat);
	pthread_mutex_unlock(&philo->data->mutex);
	ft_usleep(philo->data->time_eat);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(&philo->fork_left);
	sleep_think(philo);
}

void	*is_dead(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	ft_usleep(philo->data->time_deth + 1);
	pthread_mutex_lock(&philo->data->eat);
	pthread_mutex_lock(&philo->data->finish);
	if (check_death(philo, 0) && !philo->finish
		&& ((get_time() - philo->last_eat) >= (long)(philo->data->time_deth)))
	{
		pthread_mutex_unlock(&philo->data->eat);
		pthread_mutex_unlock(&philo->data->finish);
		pthread_mutex_lock(&philo->data->mutex);
		print_status("\x1b[38;2;255;0;0;1m died \e[0m\n", philo);
		pthread_mutex_unlock(&philo->data->mutex);
		check_death(philo, 1);
	}
	pthread_mutex_unlock(&philo->data->eat);
	pthread_mutex_unlock(&philo->data->finish);
	return (NULL);
}

void	*thead(void *tmp_data)
{
	t_philo	*philo;

	philo = (t_philo *)tmp_data;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_eat / 10);
	while (check_death(philo, 0))
	{
		pthread_create(&philo->t_deah, NULL, is_dead, tmp_data);
		activity(philo);
		pthread_detach(philo->t_deah);
		if ((int)++philo->nb_eat == philo->data->round)
		{
			pthread_mutex_lock(&philo->data->finish);
			philo->finish = 1;
			philo->data->nb_p_fninsh++ ;
			if (philo->data->nb_p_fninsh == philo->data->nb_philo)
			{
				pthread_mutex_unlock(&philo->data->finish);
				check_death(philo, 2);
			}
			pthread_mutex_unlock(&philo->data->finish);
			return (NULL);
		}
	}
	return (NULL);
}

int	simulation_of_life(t_data *data)
{
	int	i;

	i = 0;
	while (i != data->nb_philo)
	{
		data->philos[i].data = data;
		if (pthread_create(&data->philos[i].t_id, NULL,
				thead, &data->philos[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
