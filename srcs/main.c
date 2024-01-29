/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:32 by vharatyk          #+#    #+#             */
/*   Updated: 2024/01/29 23:27:25 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "philosophers.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <pthread.h>


static void	*printhello(void *arg)
{
	int i = 0 ;
	while(i!= 100)
	{
 printf("hello");
 i++;
 usleep(10000);
	}
	return (NULL);
}

static void	*printword(void *arg)
{
 	int i = 0 ;
	while(i!= 100)
	{
 printf("word");
 i++;
 usleep(10000);
	}
	return (NULL);

}

void example()
{
	pthread_t	t1;
	pthread_t	t2;

	if(pthread_create(&t1, NULL ,printhello, NULL))
		exit(1);
	if(pthread_create(&t2, NULL ,printword, NULL))
		exit(1);

	if(pthread_join(t1, NULL))
		exit(1);
	if(pthread_join(t2, NULL))
		exit(1);
}



int main (int argc , char **argv)
{

example();


	return(0);
}
