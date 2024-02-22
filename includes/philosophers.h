/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:55 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/22 00:51:19 by vharatyk         ###   ########.fr       */
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


typedef struct s_philo
{
	int index;

	int			is_eating;
	long int	last_eat;
	long int	time_sleep;

	int			round;

	int			left;
	int			right;

	t_data		*data;
	pthread_mutex_t mutex;
	pthread_mutex_t eat;
}		t_philo ;

typedef struct s_data
{

int		nb_philo;
long	time_deth;
long	time_eat;
long	time_slepp;

long	delta_t; //start time
long	round; // optionale

t_philo *philos ; // tout les philo
pthread_mutex_t	*forks;
pthread_mutex_t	info;
pthread_mutex_t	seneque;

}			t_data ;


// parsing //
int parsing(t_data *data , char **argv , int argc);
int is_char_neg (char *str);
int ft_erreur(char *str);
int ft_atoi(char *str);

//init//
void presocratiques(t_data *data);
void assign_fork(t_philo *philo , t_fork *forks, int i);
int create_mutex(t_data *data);
long int get_time(long init_time);

//simulation//
int simulation_of_life(t_data *data);
#endif