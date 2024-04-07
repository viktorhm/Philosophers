/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:15:32 by vharatyk          #+#    #+#             */
/*   Updated: 2024/04/07 07:17:57 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (ft_erreur("input", parsing(&data, argv, argc)))
			return (1);

		data_init(&data);
		init_simulation(&data);

		free(data.philos);
		free(data.forks);
	}
	else
		ft_erreur("nb_arg", 1);
	return (0);
}
