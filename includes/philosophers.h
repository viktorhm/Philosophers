/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:55 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/25 06:37:58 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo t_philo;
typedef struct s_data
{
	t_philo	*philos;
//BASED
	int		nb_philo;
	long	time_deth;
	long	time_eat;
	long	time_slepp;
// USE FOR MY
	int		nb_p_fninsh;
	bool	stop;
	long	delta_t; //start time
	long	round; // optionale not verry
//MUTEX of SHIT
	pthread_mutex_t	mutex;
	pthread_mutex_t	dead;
	pthread_mutex_t	eat; // why ??
	pthread_mutex_t	finish;




}			t_data ;

typedef struct s_philo
{
	int	id;
	pthread_t t_id;
	pthread_t t_deah;

	pthread_mutex_t *fork_right;
	pthread_mutex_t fork_left;

	t_data *data; //uslesse ?

	long int last_eat;
	int	nb_eat;
	int finish;
}		t_philo ;


// parsing //
int parsing(t_data *data , char **argv , int argc);
int is_char_neg (char *str);
int ft_erreur(char *str);
int ft_atoi(char *str);

//init// getion erreur enixistant fonction phtread ??
int init_data(t_data *data);
int presocratiques(t_data *data);
int set_fork(t_data *data ,int i);
long int get_time(); // is  not better working

//simulation//
void *thead(void *tmp_data);
int simulation_of_life(t_data *data);
void sleep_think(t_philo *philo);
void activity (t_philo *philo);
void print_status(char *str , t_philo *philo);
void *is_dead(void *data);
int check_death(t_philo *philo , int i);
void *thead(void *tmp_data);
int simulation_of_life(t_data *data);
void	ft_usleep(long int time_in_ms);
#endif