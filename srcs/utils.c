/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:21:38 by vharatyk          #+#    #+#             */
/*   Updated: 2024/04/13 16:27:38 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_malloc(size_t bytes)
{
	void	*result;

	result = malloc(bytes);
	if (NULL == result)
		ft_exit("malloc");
	return (result);
}

long	get_time(void)
{
	struct timeval	time;
	long int		delta;

	delta = 0;
	gettimeofday(&time, NULL);
	delta = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (delta);
}

void	write_status(t_write status, t_philo *philo)
{
	long	now;

	now = get_time() - philo->data->delta_t;
	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	safe_mutex(&philo->data->write, LOCK);
	if (status == TAKE_FORK && !simulation_end(philo->data))
		printf("%ld %d\x1b[38;2;100;100;100;1m has taken a fork\e[0m\n"\
		, now, philo->id);
	else if (status == EAT && !simulation_end(philo->data))
		printf("%ld %d\x1b[38;2;0;255;0;1m is eating\e[0m\n", now, philo->id);
	else if (status == THINK && !simulation_end(philo->data))
		printf("%ld %d\x1b[38;2;255;255;0;1m is thinking\e[0m\n"\
		, now, philo->id);
	else if (status == SLEP && !simulation_end(philo->data))
		printf("%ld %d\x1b[38;2;100;150;150;1m is sleeping\e[0m\n"\
		, now, philo->id);
	else if (status == THINK && !simulation_end(philo->data))
		printf("%ld %d\x1b[38;2;255;255;0;1m is thinking\e[0m\n"\
		, now, philo->id);
	else if (status == DEAD)
		printf("%ld %d\x1b[38;2;255;0;0;1m died\e[0m\n", now, philo->id);
	safe_mutex(&philo->data->write, UNLOCK);
}

void	wait_threads(t_data *data)
{
	while (!get_bool(&data->data_mutex, &data->all_redy))
		;
}

/**/
void	increase_long(pthread_mutex_t *mutex, long *value)
{
	safe_mutex(mutex, LOCK);
	(*value)++;
	safe_mutex(mutex, UNLOCK);
}
