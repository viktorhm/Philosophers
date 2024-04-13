/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_unlock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 04:41:15 by vharatyk          #+#    #+#             */
/*   Updated: 2024/04/13 16:54:21 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* gestion des unlock lock return la value et unlock + propre */
void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	safe_mutex(mutex, LOCK);
	*dest = value;
	safe_mutex(mutex, UNLOCK);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	tmp;

	safe_mutex(mutex, LOCK);
	tmp = *value;
	safe_mutex(mutex, UNLOCK);
	return (tmp);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	safe_mutex(mutex, LOCK);
	*dest = value;
	safe_mutex(mutex, UNLOCK);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	tmp;

	safe_mutex(mutex, LOCK);
	tmp = *value;
	safe_mutex(mutex, UNLOCK);
	return (tmp);
}

bool	simulation_end(t_data *data)
{
	return (get_bool(&data->data_mutex, &data->end_simulation));
}
