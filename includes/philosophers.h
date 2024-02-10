/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:55 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/10 17:26:24 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>


typedef struct s_data
{
int nb_philo;
int time_deth;
int time_eat;
int time_slepp;
int long deltat;
}			t_data ;


typedef struct s_philo
{
	int index;
	long int time eat;
	long int sleep;
	t_fork left;
	t_fork right;
	pthread_t thead;


} t_philo ;

int ft_erreur(void);

int ft_atoi(char *str);


#endif