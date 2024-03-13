/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:14:00 by vharatyk          #+#    #+#             */
/*   Updated: 2024/03/13 09:37:53 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parsing(t_data *data, char **argv, int argc)
{
	int	j;

	j = 1;
	while (argc != j)
	{
		if (is_char_neg(argv[j]))
			return (ft_erreur("negatif_number", 1));
		j++;
	}
	data->nb_philo = ft_atoi(argv[1]);
	data->time_deth = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_slepp = ft_atoi(argv[4]);
	if (data->nb_philo < 1 || data->time_deth <= 0
		|| data->time_eat <= 0 || data->time_slepp <= 0)
		return (ft_erreur("value min", 1));
	if (argc == 6)
	{
		data->round = ft_atoi(argv[5]);
		if (data->round <= 0)
			return (1);
	}
	data->philos = NULL;
	return (0);
}

int	is_char_neg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_erreur(char *str, int value)
{
	if (value == 0)
		return (0);
	if (value == 1)
		printf("\x1b[31m error: \x1b[38;2;255;0;0;1m %s \e[0m", str);
	if (value == 2)
		printf("malloc");
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result > 2147483647 || result < -2147483647)
		return (ft_erreur("int_max", 1));
	return (result);
}
