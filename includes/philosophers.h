/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:55 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/22 16:25:35 by vharatyk         ###   ########.fr       */
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
	pthread_mutex_t mutex_fork ;
	int	pos;
	int free; //??
}	t_fork;

typedef struct s_philo
{

	pthread_t	philo_thread;
	int			index;
	int			is_eating;
	long int	last_eat; //time_t -> best ??
	long int	time_die;
	int			left;
	int			right;

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
t_fork *forks;

pthread_mutex_t	mutex;
pthread_mutex_t	seneque;

}			t_data ;


// parsing //
int parsing(t_data *data , char **argv , int argc);
int is_char_neg (char *str);
int ft_erreur(char *str);
int ft_atoi(char *str);

//init//
void presocratiques(t_data *data);
int create_mutex(t_data *data);
long int get_time(long init_time);

//simulation//
int simulation_of_life(t_data *data);
#endif