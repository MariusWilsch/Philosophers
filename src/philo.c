/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:58:44 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/31 14:21:31 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


int		main(int argc, char *argv[])
{
	t_config	conf;
	t_mutex		mutexes;
	t_data		data;
	
	if (argc != 5)
		return (0);
	if (!setdata(&conf, &mutexes, &data, argv))
		return (0);

	// Clean up function
		// destroy_mutexes ... 
}