/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:44:31 by verdant           #+#    #+#             */
/*   Updated: 2023/04/27 12:33:30 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_forks(t_philo *philo, int n_must_eat)
{
	pthread_mutex_t *first_fork;
	pthread_mutex_t *second_fork;
	
	if (philo->thread_id % 2 == 0)
	{
		first_fork = philo->l_fork;
		second_fork = philo->r_fork;
	}
	else
	{
		first_fork = philo->r_fork;
		second_fork = philo->l_fork;
	}
	print_log(philo, "has taken a fork", PHILO_TAKEN_FORK);
	pthread_mutex_lock(first_fork);
	pthread_mutex_lock(second_fork);
}

void eating(t_philo *philo)
{
	pick_forks(philo, philo->config->n_must_eat);
	print_log(philo, "is eating", PHILO_STATE_EATING);
	pthread_mutex_lock(&philo->config->meal_lock);
	philo->last_eaten = get_time();
	pthread_mutex_unlock(&philo->config->meal_lock);
	// philo->meals_eaten++;
	usleep_but_better(philo->config->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void sleeping(t_philo *philo)
{
	if (philo->config->dead == true)
		return ;
	print_log(philo, "is sleeping", PHILO_STATE_SLEEPING);
	usleep_but_better(philo->config->time_to_sleep);
}

void thinking(t_philo *philo)
{
	if (philo->config->dead == true)
		return ;
	print_log(philo, "is thinking", PHILO_STATE_THINKING);
}