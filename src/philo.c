/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:58:44 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/28 15:07:52 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	monitoring(void *arg)
{
	 return (NULL);
}

int		main(int argc, char *argv[])
{
	t_config	conf;
	t_mutex		*mutexes;
	t_data		*data;
	
	if (argc != 5)
		return (0);
	if (!setdata(&conf, &mutexes, &data, argv))
		return (0);
	if (!(pthread_create((*data).big_brother, NULL, &monitoring, data)))

	// Clean up function
		// destroy_mutexes ... 
}