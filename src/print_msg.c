/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:31:23 by verdant           #+#    #+#             */
/*   Updated: 2023/04/27 12:26:24 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief 
 * 
 * @param str A error message
 * @return false
 * 
 * @note This function is used to print error messages.
 * @note It always returns false.
 */
bool	print_error(char *str)
{
	ft_printf("%s", str);
	return (false);
}

bool print_log(t_philo *philo, char *msg, t_philo_state state)
{
	const int64_t start_time = philo->config->start_time;
	
	pthread_mutex_lock(&philo->config->print_lock);
	if (state == PHILO_TAKEN_FORK)
	{
		printf("%lld %d %s\n", get_time() - start_time, philo->thread_id, msg);
		return (pthread_mutex_unlock(&philo->config->print_lock));
	}
	if (state == PHILO_STATE_EATING)
	{
		printf("%lld %d %s\n", get_time() - start_time, philo->thread_id, msg);
		return (pthread_mutex_unlock(&philo->config->print_lock));
	}
	if (state == PHILO_STATE_DEAD)
	{
		printf("%lld %d %s\n", get_time() - start_time, philo->thread_id, msg);
		return (pthread_mutex_unlock(&philo->config->print_lock));
	}
	if (state == PHILO_STATE_SLEEPING)
	{
		printf("%lld %d %s\n", get_time() - start_time, philo->thread_id, msg);
		return (pthread_mutex_unlock(&philo->config->print_lock));
	}
	if (state == PHILO_STATE_THINKING)
	{
		printf("%lld %d %s\n", get_time() - start_time, philo->thread_id, msg);
		return (pthread_mutex_unlock(&philo->config->print_lock));
	}
	return (true);
}
