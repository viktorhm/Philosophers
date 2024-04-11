/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:55 by vharatyk          #+#    #+#             */
/*   Updated: 2024/04/11 14:24:02 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <errno.h>

typedef struct s_data	t_data;

typedef enum e_write
{
	EAT,
	THINK,
	TAKE_FORK,
	DEAD,
	SLEP,
}			t_write;

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}			t_opcode;

typedef struct s_fork
{
	pthread_mutex_t fork;
	int	fork_id;


}	t_fork;

typedef struct s_philo
{
	int			id;
	long		conter;
	bool		full;
	long		last_eat;

	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_mutex_t philo_mutex;
	t_data		*data;
	pthread_t	thread_id;
}			t_philo;


typedef struct s_data
{
	t_philo		*philos;
	t_fork		*forks;
	pthread_mutex_t data_mutex;
	pthread_mutex_t write;
	pthread_t	reaper;
	long		time_deth;
	long		time_eat;
	long		time_slepp;
	long		threads_running;

	long		delta_t;
	long		round;

	int			nb_philo;
	int			nb_p_fninsh;
	bool			end_simulation;
	bool		all_redy;

}		t_data;

void ft_clean(t_data *data);
void	ft_usleep(long int time_in_ms);
int	main(int argc, char **argv);
/*init.c*/
static void assign_fork(t_philo *philo ,t_fork *forks , int i);
static void philo_init(t_data *data);
void data_init(t_data *data);

/* parsing.c */
int	parsing(t_data *data, char **argv, int argc);
int	is_char_neg(char *str);
int	ft_erreur(char *str, int value);
int	ft_atoi(char *str);

/*safe_init.c*/

void safe_mutex( pthread_mutex_t *mutex, t_opcode opcode);
void safe_thread( pthread_t *thread, void *(*function)(void *)
	, void *data, t_opcode opcode);

/*lock_unlock*/
void set_bool(pthread_mutex_t *mutex , bool *dest , bool value);
bool get_bool(pthread_mutex_t *mutex , bool *value);
void set_long(pthread_mutex_t *mutex , long *dest , long value);
long get_long(pthread_mutex_t *mutex , long *value);
bool	simulation_end(t_data *data);

/*utils.c*/
void		*ft_malloc(size_t bytes);
void		ft_exit(char *str);
long int	get_time(void);
bool	philo_runnig(pthread_mutex_t *mutex, long *threads , long philo_nbr);
void	increase_long(pthread_mutex_t *mutex, long *value);
void		write_status(t_write status,t_philo *philo);

/*simulation*/
void init_simulation(t_data *data);
void wait_threads(t_data *data);
void	*socrate(void *data);

/* phreaper*/
void	*ft_reaper(void *tmp_data);

#endif