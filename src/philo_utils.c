/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:03:34 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/31 13:50:24 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	mutexes_init(t_mutex *mutexes, t_config *conf)
{
	int	i;

	i = 0;
	mutexes->fork = malloc(conf->num_of_ph * sizeof(mutexes->fork));
	if (!mutexes->fork)
		return (false);
	while (i < conf->num_of_ph)
	{
		if (pthread_mutex_init(&mutexes->fork[i], NULL))
			return (false);
		i++;
	}
	if (pthread_mutex_init(&mutexes->start, NULL))
		return (false);
	return (true);
}
bool	setdata(t_config *conf, t_mutex *mutexes,t_data *data, char *argv[])
{
	conf->num_of_ph = atoi(argv[1]);
	conf->time_to_die = atoi(argv[2]);
	conf->time_to_eat = atoi(argv[3]);
	conf->time_to_sleep = atoi(argv[4]);
	if (!mutexes_init(mutexes, conf))
		return (false);
	data->conf = conf;
	data->mutexes = mutexes;
	return (true);
}
