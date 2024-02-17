/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:55 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/17 15:20:32 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data t_data;


typedef struct s_fork
{
	pthread_mutex_t fork;
	int	fork_id;
}		t_fork;


typedef struct s_philo
{
	int index;

	long int time_eat; // dernier repas
	long int last_eat;
	long int time_sleep;
	int 	round;
	t_fork *left;
	t_fork *right;
	pthread_t thead_id;
	t_data *data ;


}		t_philo ;

typedef struct s_data
{
int nb_philo;
long time_deth;
long time_eat;
long time_slepp;
long delta_t; //start time
long	round; // optionale
t_fork *forks ; //->tout les forck
t_philo *philos ; // tout les philo
}			t_data ;

int ft_erreur(void);
int ft_atoi(char *str);
long int get_time(long init_time);
int is_char_neg (char *str);
int parsing(t_data *data , char **argv , int argc);
int create_mutex(t_data *data);
void presocratiques(t_data *data);
#endif