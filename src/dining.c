/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:27:15 by verdant           #+#    #+#             */
/*   Updated: 2023/05/02 16:09:53 by verdant          ###   ########.fr       */
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
void	is_meal_expired(t_config *c, t_philo *philos)
{
	int	i;

	i = 0;
	while (true)
	{
		if (i == c->num_philos)
			i = 0;
		pthread_mutex_lock(&c->meal_lock);
		if (get_time() - philos[i].last_eaten > c->time_to_die)
		{
			c->dead = true;
			printf("%lld %d died\n", get_time() - c->start_time, philos[i].id);
			pthread_mutex_unlock(&c->meal_lock);
			return ;
		}
		if (c->n_must_eat != -1 && philos[i].meals_eaten == c->n_must_eat)
		{
			c->dead = true;
			pthread_mutex_unlock(&c->meal_lock);
			return ;
		}
		i++;
		pthread_mutex_unlock(&c->meal_lock);
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		if (eating(philo) == false)
			break ;
		if (sleeping(philo) == false)
			break ;
		if (thinking(philo) == false)
			break ;
	}
	return (NULL);
}

bool	start_dinner(t_config *config, t_philo *ph, int n_philos)
{
	int	i;

	i = 0;
	config->start_time = get_time();
	while (i < n_philos)
	{
		if (pthread_create(&(ph[i].thread), NULL, &philo_routine, &ph[i]) == -1)
		{
			config->dead = true;
			return (print_error("Dining: Thread creation failed\n"));
		}
		pthread_mutex_lock(&config->meal_lock);
		ph[i].last_eaten = get_time();
		pthread_mutex_unlock(&config->meal_lock);
		i++;
	}
	is_meal_expired(config, ph);
	return (true);
}
