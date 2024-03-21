/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:21:38 by vharatyk          #+#    #+#             */
/*   Updated: 2024/03/21 14:10:44 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(char *str, t_philo *philo)
{
	long int	time;

	time = -1;
	time = get_time() - philo->data->delta_t;
	if (time >= 0 && check_death(philo, 0))
		printf("%ld %d%s", time, philo->id, str);
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

int	check_death(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->data->dead);
	if (i)
		philo->data->stop = i;
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->dead);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (1);
}
