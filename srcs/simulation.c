/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:27:17 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/20 16:53:46 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"philosophers.h"

void print_int_value(int nb)
{

	if(nb >= 9 )
	{
		print_int_value(nb / 10);
		write(1,&"0123456789"[nb%10],1);
	}
	else
		write(1,&"0123456789"[nb%10],1);


}


int simulation_of_life(t_data *data)
{
	int i = 0 ;
	if(0 == data->time_eat)
		return ;
	else if( 1 == data->nb_philo
		)
	else 
	{
		while(i++ < data->nb_philo)
			create_mutex(&data->philos[i].);

	}
}

static void eating(t_data data)
{
	return ;
}
static void slepp(t_data data);
static void dead(t_data data);
