/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:06:18 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/31 16:18:03 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

bool	wait_for_init(t_philo *local_ph)
{
	struct timeval start
	
	pthread_mutex_lock(&local_ph->mutexes->start);
	gettimeofday(&local_ph->start, NULL); // Init starting time
	printf("I'm thread: %d\tand I'm started at %d\n", local_ph->id, local_ph->start.tv_usec);
	pthread_mutex_unlock(&local_ph->mutexes->start);
	return (local_ph->id < local_ph->conf->num_of_ph);
}

void	*philo_routine(void *arg)
{
	t_philo	*local_ph;
	
	local_ph = (t_philo *)arg;
	wait_for_init(local_ph);
	// printf("%d\t", local_ph->conf->num_of_ph);
	
	return (NULL);
}

// bool	init_philo(t_data *data)
// {
// 	int			i;
// 	t_philo	*philo;
	
// 	philo = malloc(sizeof(t_philo) * data->conf->num_of_ph);
// 	if (!philo)
// 		return (false);
// 	data->philosophers = philo;
// 	i = 0;
// 	pthread_mutex_lock(&data->mutexes->start);
// 	while (i < data->conf->num_of_ph)
// 	{
// 		philo[i].conf = data->conf;
// 		philo[i].mutexes = data->mutexes;
// 		philo[i].id = i;
// 		if (pthread_create(&philo[i].thread, NULL, &philo_routine, &philo[i]))
// 			return (false);
// 		data->philosophers[i] = philo[i]; // How do I link the philosophers[i] with the data struct
// 		i++;
// 	}
// 	pthread_mutex_unlock(&data->mutexes->start);
// 	i = 0;
// 	while (i < data->conf->num_of_ph)
// 	{
// 		if (pthread_join(philo[i].thread, NULL))
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }

bool	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philosophers = malloc(sizeof(t_philo) * data->conf->num_of_ph);
	if (!data->philosophers)
		return (false);
	pthread_mutex_lock(&data->mutexes->start);
	while (i < data->conf->num_of_ph)
	{
		data->philosophers[i].id = i;
		data->philosophers[i].data = data;
		if (pthread_create(data->philosophers[i].thread, NULL, &philo_routine, &data->philosophers[i]))
			return (false);
		i++;
	}
	pthread_mutex_unlock(&data->mutexes->start);
	i = 0;
	while (i < data->conf->num_of_ph)
	{
		pthread_join(data->philosophers[i].thread, NULL);
		i++;
	}
	return (false);
}
