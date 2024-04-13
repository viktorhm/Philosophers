/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 03:40:01 by vharatyk          #+#    #+#             */
/*   Updated: 2024/04/13 16:50:48 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_exit(char *str)
{
	printf("error : %s", str);
	exit(EXIT_FAILURE);
}

/*MUTEX*/
/*in the case or error*/
void	error_mutex(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK))
		ft_exit("MUTEX VALUE INVALIDE");
	else if (status == EINVAL && opcode == INIT)
		ft_exit("MUTEX VALUE INVALIDE");
	else if (EDEADLK == status)
		ft_exit("MUTEX DEAD_LOCK");
	else if (EPERM == status)
		ft_exit("MUTEX NO UNLOCK");
	else if (ENOMEM == status)
		ft_exit("MUTEX NO MEMMORY");
	else if (EBUSY == status)
		ft_exit("MUTEX LOCKED");
}

/*gestion of the mutex*/
void	safe_mutex(pthread_mutex_t *mutex, t_opcode opcode)
{
	if (opcode == INIT)
		error_mutex(pthread_mutex_init(mutex, NULL), opcode);
	else if (opcode == LOCK)
		error_mutex(pthread_mutex_lock(mutex), opcode);
	else if (opcode == UNLOCK)
		error_mutex(pthread_mutex_unlock(mutex), opcode);
	else if (opcode == DESTROY)
		error_mutex(pthread_mutex_destroy(mutex), opcode);
	else
		ft_exit("NO MUTEX");
}

/*THREAD*/
/*in the case or error*/
static void	error_thread(int status)
{
	if (status == 0)
		return ;
	ft_exit("THREAD");
}

/*gestion of the mutex*/
void	safe_thread(pthread_t *thread, void *(*function)(void *)
	, void *data, t_opcode opcode)
{
	if (opcode == CREATE)
		error_thread(pthread_create(thread, NULL, function, data));
	else if (opcode == JOIN)
		error_thread(pthread_join(*thread, NULL));
	else if (opcode == DETACH)
		error_thread(pthread_detach(*thread));
	else
		ft_exit("NO MUTEX");
}
