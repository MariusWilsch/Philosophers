/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilsch <mwilsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:06:18 by mwilsch           #+#    #+#             */
/*   Updated: 2023/01/27 14:17:32 by mwilsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	convert_time(struct timeval	*s, struct timeval *e)	
{
	return ((e->tv_sec - s->tv_sec) * 1000 + (e->tv_usec - s->tv_usec) / 1000);
}

	// printf("I was started at %d\tI am ph %d\n",local_ph->start.tv_usec, local_ph->number_tag);
	// This is pretty much the dying action
// If I pass the data struct how can I access the philsophers?

void	*philo_routine(void	*arg)  // 
{
	t_philo	*local_ph = (t_philo *)arg;
	struct timeval end;

	while (true)
	{
		gettimeofday(&end, NULL);
		local_ph->elapsed = convert_time(&local_ph->start, &end);
		if (local_ph->elapsed == 700)
		{
			// Set bool to false in data struct
			printf("At %d --> ph %d died\n",local_ph->elapsed, local_ph->number_tag);
			return ((void *)0);
		}
	}
	return (NULL);
}

void	invite_philosophers(t_philo **ph, t_data **data)
{
	struct timeval	start;
	t_philo					*temp;
	int							i;
	

	i = 0;
	temp = (*ph);
	while (i < (*data)->num_of_ph)
	{
		temp[i].number_tag = i;
		i++;
	}
	i = 0;
	while (i < (*data)->num_of_ph)
	{
		gettimeofday(&temp[i].start, NULL);
		temp[i].is_locked = false;
		pthread_mutex_init(&temp[i].lock, NULL);
		if (pthread_create(&temp[i].thread, NULL, &philo_routine, &temp[i]) < 0)
			exit(1);
		i++;
	}
	// Add if clause that when bool is true return
	i = 0;
	while (i < (*data)->num_of_ph)
	{
		pthread_join(temp[i].thread, NULL);
		i++;
	}
}