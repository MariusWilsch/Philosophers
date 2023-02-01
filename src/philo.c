/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:58:44 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/31 15:18:57 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// bool monitor_situation(t_data *data)
// {
// 	int	i;

	
// 	return (true);
// }


int		main(int argc, char *argv[])
{
	t_config	conf;
	t_mutex		mutexes;
	t_data		data;
	
	if (argc != 5 || !setdata(&conf, &mutexes, &data, argv))
		return (0);
	if (!init_philo(&data))
		return (0);
	// monitor_simulation(&data);
	// printf("%d", data.philosophers[2].id);
		// printf("%d", data.philosophers[0].id);
}