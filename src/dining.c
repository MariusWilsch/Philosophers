/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:27:15 by verdant           #+#    #+#             */
/*   Updated: 2023/04/27 12:44:24 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief 
 * 
 * @param config 
 * @param philos 
 * 
 * @note Is it necessary to lock the mutex here?
 */
void is_meal_expired(t_config *config, t_philo *philos)
{
	int	i;

	i = 0;
	while (config->dead == false)
	{
		if (i == config->num_philos)
			i = 0;
		pthread_mutex_lock(&config->meal_lock);
		if (get_time() - philos[i].last_eaten >= config->time_to_die)
		{
			config->dead = true;
			print_log(&philos[i], "died", PHILO_STATE_DEAD);
			return ;
		}
		i++;
		pthread_mutex_unlock(&config->meal_lock);
	}
}

void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->config->dead == false)
	{
		eating(philo); // TODO: Add n_must_eat logic
		sleeping(philo);
		thinking(philo);
		// Repeat
	}
	return (NULL);
}

bool start_dinner(t_config *config, t_philo *philos , int n_philos)
{
	int i;

	i = 0;
	config->start_time = get_time();
	while (i < n_philos)
	{
		if (pthread_create(&(philos[i].thread), NULL, &philo_routine, &philos[i]) == -1)
		{
			config->dead = true;
			return (print_error("Dining: Thread creation failed\n"));
		}
		pthread_mutex_lock(&config->meal_lock);
		philos[i].last_eaten = get_time();
		pthread_mutex_unlock(&config->meal_lock);
		i++;
	}
	is_meal_expired(config, philos);
	return (true);
}