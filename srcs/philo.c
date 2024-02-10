/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:32 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/10 17:06:04 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

//  echo "\x1b[38;2;255;0;0;5mSal\x1b[38;2;0;255;0;7mu\e[0mt"

// static void	*routine(void *arg)
// {
// 	int i = 0 ;
// 	int *num ;

// 	num = (int *)arg;
// 	while(i < 10000)
// 	{
// 			(*num)++;
// 			i++;
// 	}
// 	return (NULL);
// }

// void example()
// {
// 	pthread_t	t1;
// 	pthread_t	t2;
// 	int *num ;

// 	num = malloc(sizeof(int));

// 	*num = 0 ;
// 	if(pthread_create(&t1, NULL ,routine, num))
// 		exit(1);
// 	if(pthread_create(&t2, NULL ,routine, num))
// 		exit(1);

// 	if(pthread_join(t1, NULL))
// 		exit(1);
// 	if(pthread_join(t2, NULL))
// 		exit(1);
// 	printf("NUM: %d", *num);
// 	}

int cretate_philo(t_data data)
{

	while()


}

long int get_time(long init_time)
{
	long int seconde = 0 ;
	long int deltatime = 0 ;
	struct timeval	time;

	gettimeofday(&time,NULL);

	seconde = time.tv_sec * 1000 + time.tv_usec / 1000 ;
	deltatime = seconde - init_time ;


	return(deltatime);
}

int ft_erreur(void)
{
write(1,"erreur",6);

return(1);
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


int main (int argc , char **argv)
{
	t_data data ;

if(argc == 4 || argc == 5)
{
	int j = 1 ;
	while(argc != j)
	{
		if(is_char_neg(argv[j]))
			return(ft_erreur());
		j++;
	}
	data.nb_philo = ft_atoi(argv[0]) ;
	data.time_deth = ft_atoi(argv[1]) ;
	data.time_eat = ft_atoi(argv[2]) ;
	data.time_slepp = ft_atoi(argv[3]);
	data.deltat = 0 ;
	data.deltat = get_time(data.deltat);


	printf("%ld ",get_time(data.deltat));
	sleep(1);
	printf("%ld ",get_time(data.deltat));

}

	return(0);
}
