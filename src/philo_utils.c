/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:03:34 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/28 15:08:29 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	mutexes_init(t_mutex **mutexes, t_config *conf)
{
	int	i;

	i = 0;
	(*mutexes)->fork = malloc(conf->num_of_ph * sizeof((*mutexes)->fork));
	if (!(*mutexes)->fork)
		return (0);
	while (i < conf->num_of_ph)
	{
		if (!pthread_mutex_init(&(*mutexes)->fork[i], NULL))
			return (0);
		i++;
	}
	if (!(pthread_mutex_init(&(*mutexes)->start, NULL)))
		return (0);
	return (1);
}
int	setdata(t_config *conf, t_mutex *mutexes,t_data *data, char *argv[])
{
	conf->num_of_ph = ft_atoi(argv[1]);
	conf->time_to_die = ft_atoi(argv[2]);
	conf->time_to_eat = ft_atoi(argv[3]);
	conf->time_to_sleep = ft_atoi(argv[4]);
	if (!mutexes_init(mutexes, conf))
		return (0);
	data->conf = conf;
	data->mutexes = mutexes;
	return (1);
}
