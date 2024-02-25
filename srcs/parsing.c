/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:14:00 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/25 01:27:10 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int parsing(t_data *data , char **argv , int argc)
{

int j = 1 ;
	while(argc != j)
	{
		if(is_char_neg(argv[j]))
			return(ft_erreur("negatif_number"));
		j++;
	}
	data->nb_philo = ft_atoi(argv[1]) ;
	data->time_deth = ft_atoi(argv[2]) ;
	data->time_eat = ft_atoi(argv[3]) ;
	data->time_slepp = ft_atoi(argv[4]);
	if(data->nb_philo <= 2 || data->time_deth <= 6 || data->time_eat <= 6 || data->time_slepp <= 6) // pas moins de 60 ms
		return(1);
	if(argc == 6)
	{
		data->round = ft_atoi(argv[5]);
		if(data->round <= 0)
			return(1);
	}
	data->philos = NULL;
	return(0);
	//data->deltat = get_time(data->nb_philo); //init (a)voir
}


int is_char_neg (char *str)
{
	int i = 0 ;
	while(str[i])
	{
		if(str[i]>= '0' && str[i]<= '9')
			i++;
		else
			return(1);
	}
	return(0);
}

int ft_erreur(char *str)
{
	int i = 0 ;
write(1,"erreur : ",9);
while(str[i])
{
	write(1,&str[i++],1);
}

return(1);
}


int ft_atoi(char *str)
{
	int  i = 0 ;
	int result = 0 ;

	while(str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}

	if (result > 2147483647 || result < -2147483647)
		{
			return(ft_erreur("int_max"));
		}

	return(result);
}
