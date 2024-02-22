/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:27:17 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/22 11:06:24 by vharatyk         ###   ########.fr       */
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
	int i = 0  ;
	while (data->nb_philo != i )
	{
		//printf("%d",data->philos[i].left);
		i++;
	}
	return(0);
}