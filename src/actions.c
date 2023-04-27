/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:44:31 by verdant           #+#    #+#             */
/*   Updated: 2023/04/27 15:42:34 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Picks up the forks
 * 
 * @param philo A pointer to a philosopher
 * 
 * @note when the philosopher is eating, he needs to pick up both forks
 * @note the philosopher with even id picks up the left fork first
 * @note the philosopher with uneven id picks up the right fork first
 * @note this prevents deadlock
 */
void	pick_forks(t_philo *philo)
{
	pthread_mutex_t *first_fork;
	pthread_mutex_t *second_fork;
	
	if (philo->id % 2 == 0)
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

/**
 * @brief 
 * 
 * @param philo Pointer to a philosopher
 * 
 * @note This function is used to simulate the eating action.
 * @note It prints a message and then sleeps for the time_to_eat.
 * @note It also updates the last_eaten and meals_eaten variables.
 */
void eating(t_philo *philo)
{
	pick_forks(philo, philo->config->n_must_eat);
	print_log(philo, "is eating", PHILO_STATE_EATING);
	pthread_mutex_lock(&philo->config->meal_lock);
	philo->last_eaten = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->config->meal_lock);
	usleep_but_better(philo->config->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

/**
 * @brief 
 * 
 * @param philo A pointer to a philosopher
 * @note This function is used to simulate the sleeping action.
 * @note It prints a message and then sleeps for the time_to_sleep.
 * @note It also checks if the philosopher is dead.
 */
bool sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->config->meal_lock);
	if (philo->config->dead == true)
	{
		pthread_mutex_unlock(&philo->config->meal_lock);
		return (false);
	}
	pthread_mutex_unlock(&philo->config->meal_lock);
	print_log(philo, "is sleeping", PHILO_STATE_SLEEPING);
	usleep_but_better(philo->config->time_to_sleep);
	return (true);
}

/**
 * @brief 
 * 
 * @param philo A pointer to a philosopher
 * @note This function is used to simulate the thinking action.
 * @note It also checks if the philosopher is dead.
 */
bool thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->config->meal_lock);
	if (philo->config->dead == true)
	{
		pthread_mutex_unlock(&philo->config->meal_lock);
		return (false);
	}
	pthread_mutex_unlock(&philo->config->meal_lock);
	print_log(philo, "is thinking", PHILO_STATE_THINKING);
	return (true);
}