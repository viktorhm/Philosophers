/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:32 by vharatyk          #+#    #+#             */
/*   Updated: 2024/04/12 16:53:30 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = get_time();
	while ((get_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

void ft_clean(t_data *data)
{
	int i;

	i = -1;
	while(++i < data->nb_philo)
	{
		safe_mutex(&data->philos[i].philo_mutex , DESTROY);
	}
	safe_mutex(&data->write , DESTROY);
	safe_mutex(&data->data_mutex , DESTROY);
	free(data->philos);
	free(data->forks);
}


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (ft_erreur("input", parsing(&data, argv, argc)))
			return (1);
		data_init(&data);
		init_simulation(&data);
		ft_clean(&data);
	}
	else
	{
		printf("plese invalid input : ./philo 2 200 100 100");
		return(1);
	}
		
	return (0);
}

