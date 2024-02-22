/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:32 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/20 13:59:34 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


// color :  echo "\x1b[38;2;255;0;0;5mSal\x1b[38;2;0;255;0;7mu\e[0mt"


int main (int argc , char **argv)
{
	t_data data ;

if(argc == 5 || argc == 6)
{
	if( parsing( &data , argv , argc)) // parsing
		ft_erreur("input");
	if(create_mutex(&data))
		ft_erreur("mutex");
	if(simulation_of_life(&data))
		ft_erreur("simulation");

}
else
	ft_erreur("nb_arg");

	return(0);
}
