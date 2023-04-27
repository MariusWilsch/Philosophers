/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:27:15 by verdant           #+#    #+#             */
/*   Updated: 2023/04/27 15:22:09 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	lock_meal(bool death, pthread_mutex_t *meal_lock)
// {
// 	pthread_mutex_lock(meal_lock);
// 	if (death == true)
// 		return ();
	
// }

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
	while (true)
	{
		if (i == config->num_philos)
			i = 0;
		pthread_mutex_lock(&config->meal_lock);
		if (get_time() - philos[i].last_eaten > config->time_to_die)
		{
			config->dead = true;
			print_log(&philos[i], "died", PHILO_STATE_DEAD);
			pthread_mutex_unlock(&config->meal_lock);
	
			return ;
		}
		if (config->n_must_eat != -1 && philos[i].meals_eaten == config->n_must_eat)
		{
			config->dead = true;
			pthread_mutex_unlock(&config->meal_lock);
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
	while (true)
	{
		eating(philo);
		if (sleeping(philo) == false)
			break ;
		if (thinking(philo) == false)
			break ;
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